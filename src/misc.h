#ifndef H_MISC
#define H_MISC
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <locale>
#include <sstream>
#include <regex>
#include <typeinfo>
#include <cstdint>
#define string std::string
#define MAX_DB_SIZE 16
#define MAX_DB_DB_SIZE 16



class node
{
private:
	string node_name;
	string node_type;
public:
	string firstname;
	string secondname;
	string thirdname;
	string age;
	string hier;
	virtual string get_node_name(void);
	virtual string get_node_type(void);
	virtual void set_node_type(string nt);
	virtual void set_node_name(string nn);
	virtual void show_node(void);
	virtual bool write_node(FILE *fl);
	virtual string drop_all(void);
};


void show_node_u(node *);

class proger : public node
{
private:
	string node_name;
	string pay_size;
	string node_type;
	string lang_of_prog;
public:
	void set_lang_of_prog(string lop);
	string get_lang_of_prog(void);
	string firstname;
	string secondname;
	string thirdname;
	string age;
	string hier;
	virtual string get_pay_size(void);
	virtual  void set_pay_size(string ps);
	virtual string drop_all(void)
	{
		string str;
		std::ostringstream convert;
		convert << pay_size;
		str = convert.str();
		return "(filed)node_type:" + this->get_node_type() + "(filed)node_name:" + this->get_node_name() + "(filed)pay_size:" + pay_size + "(filed)lang_of_prog:" + lang_of_prog\
			+ "(filed)firstname:" + firstname + "(filed)secondname:" + secondname + "(filed)thirdname:" + thirdname + "(filed)age:" + age + "(filed)hier:" + hier;;
	}
};


class uborshik : public proger
{
private:
	string node_name;
	string pay_size;
	string node_type;
	string sex;
public:
	string firstname;
	string secondname;
	string thirdname;
	string age;
	string hier;
	virtual void set_pay_size(string ps)
	{
		pay_size = ps;
	}
	virtual string get_sex(void);
	virtual void set_sex(string s);
	virtual string drop_all(void)
	{
		return "(filed)node_type:" + this->get_node_type() + "(filed)node_name:" + this->get_node_name() + "(filed)pay_size:" + pay_size\
			+ "(filed)firstname:" + firstname + "(filed)secondname:" + secondname + "(filed)thirdname:" + thirdname + "(filed)age:" + age + "(filed)sex:" + sex + "(filed)hier:" + hier;
	}
};

class admin : public uborshik
{
private:
	string node_name;
	string pay_size;
	string node_type;
	string sex;
public:
	string firstname;
	string secondname;
	string thirdname;
	string age;
	string hier;
	string zloy;
	virtual void set_pay_size(string ps)
	{
		pay_size = ps;
	}
	virtual void set_sex(string s)
	{
		sex = s;
	}
	virtual void set_zloy(string z);
	virtual string get_zloy(void);
	virtual string drop_all(void)
	{
		return "(filed)node_type:" + this->get_node_type() + "(filed)node_name:" + this->get_node_name() + "(filed)pay_size:" + pay_size\
			+ "(filed)firstname:" + firstname + "(filed)secondname:" + secondname + "(filed)thirdname:" + thirdname + "(filed)age:" + age + "(filed)sex:" + sex + "(filed)zloy:" + zloy + "(filed)hier:" + hier;
	}
};

class table
{
private:
	string table_name;

public:
	std::multimap <string, node *> node_map;
	table(string tn);
	~table();
	bool add_node(node *n);
	void show_table(void);

};

class db
{
private:
	string name;
	string file_name;
	std::multimap<string, table *> tbl;
	uint32_t table_counter;
public:
	db(string n, uint32_t t);
	~db();
	void set_name(string n);
	string get_name(void);
	string get_file_name(void);
	uint32_t get_table_counter(void);
	void set_file_name(string fn);
	void init(string fn);
	bool add_table(string tn);
	bool add_node(string tn, node *n);
	bool write_table(table *t, FILE *fl, string tn);
	void show(void);
	bool write_dump(void);
	bool read_dump(void);
	bool parse_buffer(string buffer);
	bool parse_table_buffer(string buffer);
	node * parse_node_buffer(string buffer, string table_name);
	std::vector<node *> * find_node_on_node_name(string table_name, string node_name);
//	friend std::vector <void *> * (find_node_on_wo)(string table_name, void *wo);
	std::vector<node *> * find_specific_node_on_any_field(string table_name, node *part);
	bool delete_node(node *part);
	bool edit_node(string node_name, node *part);
	std::vector<node *> * node_vector(string tn);
};

#undef string
#endif MISC