/*
 * cppprimer.cpp
 *
 *  Created on: 2013.11.21
 *      Author: Caroline
 */

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <iterator>

#include <set>
#include <map>

using namespace std;

class QueryResult;
std::ostream& print(std::ostream& os, const QueryResult &qr);

class TextQuery {
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream& );
	QueryResult query(const std::string& ) const;
private:
	std::shared_ptr<std::vector<std::string> > file; //文件内容
	std::map<std::string, std::shared_ptr<std::set<line_no> > > wm; //词和行号的集合
};

/*把每一行放入text, 存入file(vector), 组成word和行号(set)的映射*/
TextQuery::TextQuery(std::ifstream &is) : file(new std::vector<std::string>)
{
	std::string text;
	while (std::getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		std::istringstream line(text);
		std::string word;
		while (line >> word) {
			auto& lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}

class QueryResult {
friend std::ostream& print (std::ostream&, const QueryResult& );
public:
	using line_no = std::vector<std::string>::size_type;
	QueryResult (std::string s, //查询单词
			std::shared_ptr<std::set<line_no>> p, //匹配行号
			std::shared_ptr<std::vector<std::string>> f) : //输入文件
				sought(s), lines(p), file(f) {}
	std::set<line_no>::iterator begin() { return lines->begin(); }
	std::set<line_no>::iterator end() { return lines->end(); }
	std::shared_ptr<std::vector<std::string>> get_file() { return file; }
private:
	std::string sought; //查找字符串
	std::shared_ptr<std::set<line_no>> lines; //行号集合
	std::shared_ptr<std::vector<std::string>> file; //文件集合
};

/*找到指定sought的集合, 返回迭代器, 传入string和set*/
QueryResult TextQuery::query(const std::string& sought) const {
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file); //没有找到, 不打印
	else
		return QueryResult(sought, loc->second, file); //按行号打印
};

std::string make_plural (std::size_t ctr, const std::string& word,
		const std::string ending)
{
	return (ctr > 1) ? word + ending : word;
}

std::ostream& print(std::ostream& os, const QueryResult &qr){
	os << qr.sought << " occurs " << qr.lines->size() << " "
			<< make_plural(qr.lines->size(), "time", "s") << std::endl;
	for(auto num : *qr.lines)
		os << "\t(line " << num+1 << ") " << *(qr.file->begin()+num) << std::endl;
	return os;
}

void runQueries (std::ifstream &infile) {
	TextQuery tq(infile);
	while (true) {
		std::cout << "enter word to look for, or q to quit: ";
		std::string s;
		if ( !(cin>>s) || s == "q" ) break;
		print(std::cout, tq.query(s)) << std::endl;
	}
}

/*抽象基类, 没有public成员*/
class Query_base {
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default; //虚的析构函数
private:
	virtual QueryResult eval (const TextQuery&) const = 0; //纯虚函数
	virtual std::string rep() const = 0;
};

//为Query_base提供接口(interface)
class Query {
	friend Query operator~ (const Query &); //取反
	friend Query operator| (const Query&, const Query&); //取或
	friend Query operator& (const Query&, const Query&); //取交
public:
	Query(const std::string&);
	QueryResult eval(const TextQuery &t) const { return q->eval(t); } //估值关联的查询
	std::string rep() const { return q->rep(); } //生成string版本的查询
private:
	Query(std::shared_ptr<Query_base> query) : q(query) {}
	std::shared_ptr<Query_base> q; //使用动态绑定
};

//重载输出(<<)操作符
std::ostream & operator<<(std::ostream &os, const Query &query)
{
	return os << query.rep();
}

//单词查询类
class WordQuery : public Query_base {
	friend class Query;
	WordQuery (const std::string &s) : query_word (s) {}
	QueryResult eval (const TextQuery &t) const { return t.query(query_word); }
	std::string rep() const { return query_word; };
	std::string query_word;
};

//Query接口实现动态绑定WordQuery
inline Query::Query (const std::string &s) : q(new WordQuery(s)) {}

//取反查询
class NotQuery : public Query_base {
	friend Query operator~ (const Query &); //友元是取反函数
	NotQuery (const Query &q) : query(q) {}
	std::string rep() const {return "~("+query.rep()+")";}
	QueryResult eval (const TextQuery &t) const;
	Query query;
};

//实现取反操作, 动态绑定NotQuery对象
//最终使用的是WordQuery类, Query构建需要WordQuery, 再传入NotQuery;
inline Query operator~ (const Query &operand) {
	return std::shared_ptr<Query_base> (new NotQuery(operand));
}

//二元查询, 没有eval, 则继承纯虚函数
class BinaryQuery : public Query_base {
protected:
	BinaryQuery (const Query &l, const Query &r, std::string s) :
		lhs(l), rhs(r), opSym(s) {}
	std::string rep() const {
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
	Query lhs, rhs;
	std::string opSym;
};

//取并查询
class AndQuery : public BinaryQuery {
	friend Query operator& (const Query&, const Query&);
	AndQuery (const Query& left, const Query& right) : BinaryQuery (left, right, "&") {}
	QueryResult eval (const TextQuery&) const;
};

inline Query operator& (const Query& lhs, const Query& rhs) {
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

//取或查询
class OrQuery : public BinaryQuery {
	friend Query operator| (const Query&, const Query&);
	OrQuery (const Query& left, const Query& right) : BinaryQuery (left, right, "|") {}
	QueryResult eval (const TextQuery&) const;
};

inline Query operator| (const Query& lhs, const Query& rhs) {
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

QueryResult OrQuery::eval(const TextQuery& text) const {
	auto right = rhs.eval(text), left = lhs.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no> >(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult AndQuery::eval(const TextQuery& text) const {
	auto left = lhs.eval(text), right = rhs.eval(text); //调用的是WordQuery的eval
	auto ret_lines = std::make_shared<std::set<line_no>>();
	std::set_intersection(left.begin(), left.end(), right.begin(), right.end(),
			std::inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult NotQuery::eval(const TextQuery& text) const
{
	auto result = query.eval(text); //调用WordQuery.eval;
	auto ret_lines = std::make_shared<std::set<line_no>>();
	auto beg = result.begin(), end = result.end();
	auto sz = result.get_file()->size();
	for (size_t n=0; n!=sz; ++n) {
		if (beg==end || *beg != n )
			ret_lines->insert(n);
		else if (beg!=end)
			++beg;
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}

bool get_word(std::string& str) {
	std::cout << "enter word to look for, or q to quit: " << std::endl;
	if ( !(std::cin >> str) || str == "q" ){
		std::cout << str;
		return false;
	}
	else{
		std::cout << str;
		return true;
	}
}

int main (void) {

	std::ifstream infile;
	infile.open("storyDataFile.txt");
    TextQuery file = infile;
    //Query q = ~Query("Alice");
    //Query q = Query("hair") | Query("Alice");
    //Query q = Query("hair") & Query("Alice");
    Query q = Query("fiery") & Query("bird") | Query("wind");
    const auto results = q.eval(file);
    cout << "\nExecuting Query for: " << q << endl;
    print(cout, results) << endl;
    infile.close();
	return 0;

}
