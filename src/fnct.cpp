#include "misc.h"
#define string std::string

void db::set_name(string n)
{
	name = n;
}

string db::get_name(void)
{
	return name;
}

string db::get_file_name(void)
{
	return file_name;
}

void db::set_file_name(string fn)
{
	file_name = fn;
}

db::db(string n, uint32_t t)
{
	name = n;
	table_counter = t;
}

void db::init(string fl)
{
	file_name = fl;
}

bool db::add_table(string tn)
{
	table *tmp;
	std::multimap<string, table *>::iterator it;
	it = tbl.find(tn);
	if (it != tbl.end())
	{
		return false;
	}
	if(table_counter == MAX_DB_SIZE)
	{
		return false;
	}
	try
	{
		tmp = new table(tn);
	}
	catch(...)
	{
		return false;
	}
	tbl.insert(std::pair<string, table *> (tn, tmp));
	table_counter++;
	return true;
}

bool db::add_node(string tn, node *n)
{
	std::multimap<string, table *>::iterator it;
	it = tbl.find(tn);
	if(it == tbl.end())
	{
		return false;
	}
	it->second->add_node(n);
	return true;
}

void db::show(void)
{
	for(std::multimap<string, table *>::iterator it = tbl.begin(); it != tbl.end(); ++it)
	{
		std::cout << "table # " << it->first << std::endl;
		it->second->show_table();
	}
}

db::~db()
{
	for(std::multimap<string, table *>::iterator it = tbl.begin(); it != tbl.end(); ++it)
	{
		delete it->second;
	}
}

table::~table()
{
	for(std::multimap<string, node *>::iterator it = node_map.begin(); it != node_map.end(); ++it)
	{
		if (it->second == NULL) continue;
		delete it->second;
	}
}


bool table::add_node(node *n)
{
	node_map.insert(std::pair<string, node *> (n->get_node_name(), n));
	return true;
}

void show_node_u(node *part)
{
	string buffer;
	buffer = part->drop_all();
	std::match_results<string::const_iterator> m;
	std::regex e("([\(]filed[\)])([^\(]*)([\:])([^\(\%]*)");
	while (buffer != "" && std::regex_search(buffer, m, e))
	{
		std::cout << m[0] << std::endl;
		uint32_t position = buffer.find(m[0]);
		buffer.erase(position, m[0].length());
	}
}

void table::show_table(void)
{
	uint32_t i = 0;
	for(std::multimap<string, node *>::iterator it = node_map.begin(); it != node_map.end(); ++it)
	{
		std::cout << "node: " << i << std::endl;
		show_node_u(it->second);
		i++;
	}
}

bool db::write_table(table *t, FILE *fl, string tn)
{
	char ch = '%';
	char *cstr = new char[tn.length() + 1];
	strcpy(cstr, tn.c_str());
	fwrite(cstr, 1, strlen(cstr), fl);
	delete[] cstr;
	if (t->node_map.empty())
	{
		fwrite("(filed)%", 1, 8, fl);
		return true;
	}
	for(std::multimap<string, node *>::iterator it = t->node_map.begin(); it != t->node_map.end(); ++it)
	{
		if(!it->second->write_node(fl))
		{
			return false;
		}
		fwrite(&ch, 1, 1, fl);
	}
	return true;
}

bool node::write_node(FILE *fl)
{
	char *cstr = new char[this->drop_all().length() + 1];
	strcpy(cstr, this->drop_all().c_str());
	fwrite(cstr, 1, strlen(cstr), fl);
	delete [] cstr;
	return true;
}

table::table(string tn)
{
	table_name = tn;
}

string node::get_node_name(void)
{
	return node_name;
}

void node::show_node(void)
{
	std::cout << "show node f: " << node_name << std::endl;
}

void node::set_node_type(string nt)
{
	node_type = nt;
}

string node::get_node_type(void)
{
	return node_type;
}

void node::set_node_name(string nn)
{
	node_name = nn;
}

void proger::set_pay_size(string ps)
{
	pay_size = ps;
}

string proger::get_pay_size(void)
{
	return pay_size;
}

uint32_t db::get_table_counter(void)
{
	return table_counter;
}

string node::drop_all(void)
{
	return "(filed)node_type:" + this->get_node_type() + "(filed)node_name:" + this->get_node_name() + "(filed)firstname:" + firstname + "(filed)secondname:" + secondname + "(filed)thirdname:" + thirdname + "(filed)age:" + age + "(filed)hier:" + hier;
}

void proger::set_lang_of_prog(string lop)
{
	lang_of_prog = lop;
}

string proger::get_lang_of_prog(void)
{
	return lang_of_prog;
}

std::vector<node *> * db::find_node_on_node_name(string table_name, string node_name)
{
	std::vector<node *> *tmp = new std::vector<node *>;
	if (table_name == "")
	{
		for (std::multimap<string, table *>::iterator it = tbl.begin(); it != tbl.end(); ++it)
		{
			
			for (std::multimap<string, node *>::iterator it0 = it->second->node_map.begin(); it0 != it->second->node_map.end(); ++it0)
			{
				
				if (it0->second->get_node_name() == node_name)
					tmp->insert(tmp->begin(), it0->second);
			}
		}
		if (tmp->empty())
		{
			delete tmp;
			return NULL;
		}
	}
	else
	{
		std::multimap<string, table *>::iterator it;
		it = tbl.find(table_name);
		if (it == tbl.end())
		{
			delete tmp;
			return NULL;
		}
		for (std::multimap<string, node *>::iterator it0 = it->second->node_map.begin(); it0 != it->second->node_map.end(); ++it0)
		{
			
			if (it0->second->get_node_name() == node_name)
				tmp->insert(tmp->begin(), it0->second);
		}
		if (tmp->empty())
		{
			delete tmp;
			return NULL;
		}
	}
	return tmp;
}

std::vector<node *> * db::find_specific_node_on_any_field(string table_name, node * part)
{
	std::vector<node *> *tmp = new std::vector<node *>;
	if (part == NULL)
		return NULL;
	string buffer = part->drop_all();
	string dump;
	string add_str;
	bool flag = true;
	std::match_results<string::const_iterator> m;
	std::regex e("([\(]filed[\)])([^\(\:]+)([\:])([^\(\%]+)");
//	std::cout << "IN SEARCH ####" << std::endl << std::endl;
	if (table_name == "")
	{
		for (std::multimap<string, table *>::iterator it = tbl.begin(); it != tbl.end(); ++it)
		{
			for (std::multimap<string, node *>::iterator it0 = it->second->node_map.begin(); it0 != it->second->node_map.end(); ++it0)
			{
				dump = it0->second->drop_all();
//				std::cout << '\t' << "this is dump: " << dump << std::endl;
				while (buffer != "" && std::regex_search(buffer, m, e))
				{
					if (dump.find(m[0]) == -1)
						flag = false;
					if (flag == false)
						break;
					uint32_t position = buffer.find(m[0]);
					buffer.erase(position, m[0].length());
				}
				if (flag == true)
				{
					tmp->insert(tmp->begin(), (node *)(it0->second));
				}
				if (flag == false)
				{
					flag = true;
				}
				buffer = part->drop_all();
			}
		}
		if (tmp->empty())
		{
			delete tmp;
			return NULL;
		}
		
	}
	else
	{
		std::multimap<string, table *>::iterator it;
		it = tbl.find(table_name);
		if (it == tbl.end())
		{
			delete tmp;
			return NULL;
		}
		for (std::multimap<string, node *>::iterator it0 = it->second->node_map.begin(); it0 != it->second->node_map.end(); ++it0)
		{
			dump = it0->second->drop_all();
			while (buffer != "" && std::regex_search(buffer, m, e))
			{
				if (dump.find(m[0]) == -1)
					flag = false;
				if (flag == false)
					break;
				uint32_t position = buffer.find(m[0]);
				buffer.erase(position, m[0].length());
			}
			if (flag == true)
			{
				tmp->insert(tmp->begin(), (node *)(it0->second));
			}
			if (flag == false)
			{
				flag = true;
			}
		}
		if (tmp->empty())
		{
			delete tmp;
			return NULL;
		}
	}
	return tmp;
}


void uborshik::set_sex(string s)
{
	sex = s;
}

string uborshik::get_sex(void)
{
	return sex;
}

void admin::set_zloy(string z)
{
	zloy = z;
}

string admin::get_zloy(void)
{
	return zloy;
}

bool db::delete_node(node *part)
{
	for (std::multimap<string, table *>::iterator it = tbl.begin(); it != tbl.end(); ++it)
	{
		if (it->second->node_map.empty())
		{
			continue;
		}
		std::multimap<string, node *>::iterator ti = it->second->node_map.find(part->get_node_name());
		if (ti == it->second->node_map.end())
			continue;
		delete ti->second;
		it->second->node_map.erase(ti);
	}
	return true;
}

bool db::edit_node(string node_name, node *part)
{
	for (std::multimap<string, table *>::iterator it = tbl.begin(); it != tbl.end(); ++it)
	{
		if (it->second->node_map.empty())
		{
			continue;
		}
		std::multimap<string, node *>::iterator ti = it->second->node_map.find(node_name);
		if (ti == it->second->node_map.end())
			continue;
		it->second->node_map.erase(ti);
		it->second->node_map.insert(std::pair<string, node *>(part->get_node_name(), part));
	}
	return true;
}			

std::vector<node *> * db::node_vector(string table_name)
{
	std::vector<node *> *tmp = new std::vector<node *>;
	if (table_name == "")
	{
		for (std::multimap<string, table *>::iterator it = tbl.begin(); it != tbl.end(); ++it)
		{
			for (std::multimap<string, node *>::iterator it0 = it->second->node_map.begin(); it0 != it->second->node_map.end(); ++it0)
			{
				tmp->push_back(it0->second);
			}
		}
		if (tmp->empty())
		{
			delete tmp;
			return NULL;
		}
	}
	else
	{
		std::multimap<string, table *>::iterator it;
		it = tbl.find(table_name);
		if (it == tbl.end())
		{
			delete tmp;
			return NULL;
		}
		for (std::multimap<string, node *>::iterator it0 = it->second->node_map.begin(); it0 != it->second->node_map.end(); ++it0)
		{
			tmp->push_back(it0->second);
		}
		if (tmp->empty())
		{
			delete tmp;
			return NULL;
		}
	}

	return tmp;
}