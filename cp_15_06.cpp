/*
 * cppprimer.cpp
 *
 *  Created on: 2013.11.7
 *      Author: Caroline
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

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
	QueryResult (std::string s,
			std::shared_ptr<std::set<line_no>> p,
			std::shared_ptr<std::vector<std::string>> f) :
				sought(s), lines(p), file(f) {}
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
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval (const TextQuery&) const = 0; //纯虚函数
	virtual std::string rep() const = 0;
};

class Query {
	friend Query operator~ (const Query &);
	friend Query operator| (const Query&, const Query&);
	friend Query operator& (const Query&, const Query&);
public:
	Query(const std::string&);
	QueryResult eval(const TextQuery &t) const { return q->eval(t); } //估值关联的查询
	std::string rep() const { return q->rep(); } //生成string版本的查询
private:
	Query(std::shared_ptr<Query_base> query) : q(query) {}
	std::shared_ptr<Query_base> q;
};

int main (void) {

	std::ifstream infile;
	infile.open("file.txt");
	runQueries(infile);
	infile.close();

	return 0;

}
