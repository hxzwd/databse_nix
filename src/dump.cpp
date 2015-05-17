#include "misc.h"

bool db::write_dump(void)
{
	FILE *fl;
	std::string str;
	char ch = '|';
	char *cstr = new char[this->get_file_name().length() + 1];
	strcpy(cstr, this->get_file_name().c_str());
	if((fl = fopen(cstr, "wb+")) == NULL)
	{
		return false;
	}
	delete [] cstr;
	str = ":db:" + this->get_name() + ":tables:";
	cstr = new char[1 + str.length()];
	strcpy(cstr, str.c_str());
	fwrite(cstr, strlen(cstr), 1, fl);
	delete [] cstr;
	for(std::map<std::string, table *>::iterator it = tbl.begin(); it != tbl.end(); ++it)
	{
		if(!this->write_table(it->second, fl, it->first))
		{
			return false;
		}
		fwrite(&ch, 1, 1, fl);
	}
	ch = '*';
	fwrite(&ch, 1, 1, fl);
	fclose(fl);
	return true;
}

bool parse_proger(proger *tmp, std::string buffer)
{
	std::match_results<std::string::const_iterator> m;
	std::regex e("([\(]filed[\)])(node_type[\:])([a-zA-Z0-9/s]+)([\(]filed[\)])(node_name[\:])([^\(]+)([\(]filed[\)])(pay_size[\:])([0-9]+)([\(]filed[\)])(lang_of_prog[\:])([^\(\%]+)([\(]filed[\)])(firstname[\:])([^\(]+)([\(]filed[\)])(secondname[\:])([^\(]+)([\(]filed[\)])(thirdname[\:])([^\(\%]+)([\(]filed[\)])(age[\:])([^\(]+)([\(]filed[\)])(hier[\:])([^\(\%]*)");
	if (!std::regex_search(buffer, m, e))
	{
		std::cout << buffer << std::endl;
		return false;
	}
	tmp->set_node_name(m[6]);
	tmp->set_pay_size(m[9]);
	tmp->set_lang_of_prog(m[12]);
	tmp->firstname = m[15];
	tmp->secondname = m[18];
	tmp->thirdname = m[21];
	tmp->age = m[24];
	tmp->hier = m[27];
	return true;
}

bool parse_uborshik(uborshik *tmp, std::string buffer)
{
	std::match_results<std::string::const_iterator> m;
	std::regex e("([\(]filed[\)])(node_type[\:])([a-zA-Z0-9/s]+)([\(]filed[\)])(node_name[\:])([^\(]+)([\(]filed[\)])(pay_size[\:])([0-9]+)([\(]filed[\)])(firstname[\:])([^\(]+)([\(]filed[\)])(secondname[\:])([^\(]+)([\(]filed[\)])(thirdname[\:])([^\(\%]+)([\(]filed[\)])(age[\:])([^\(\%]+)([\(]filed[\)])(sex[\:])([^\(\%]+)([\(]filed[\)])(hier[\:])([^\(\%]*)");
	if (!std::regex_search(buffer, m, e))
	{
		std::cout << buffer << std::endl;
		return false;
	}
	tmp->set_node_name(m[6]);
	tmp->set_pay_size(m[9]);
	tmp->firstname = m[12];
	tmp->secondname = m[15];
	tmp->thirdname = m[18];
	tmp->age = m[21];
	tmp->set_sex(m[24]);
	tmp->hier = m[27];
	return true;
}

bool parse_admin(admin *tmp, std::string buffer)
{
	std::match_results<std::string::const_iterator> m;
	std::regex e("([\(]filed[\)])(node_type[\:])([a-zA-Z0-9/s]+)([\(]filed[\)])(node_name[\:])([^\(]+)([\(]filed[\)])(pay_size[\:])([0-9]+)([\(]filed[\)])(firstname[\:])([^\(]+)([\(]filed[\)])(secondname[\:])([^\(]+)([\(]filed[\)])(thirdname[\:])([^\(\%]+)([\(]filed[\)])(age[\:])([^\(\%]+)([\(]filed[\)])(sex[\:])([^\(\%]+)([\(]filed[\)])(zloy[\:])([^\(\%]+)([\(]filed[\)])(hier[\:])([^\(\%]*)");
	if (!std::regex_search(buffer, m, e))
	{
		std::cout << buffer << std::endl;
		return false;
	}
//	bool zloy = false;
//	if (m[27] == "true") zloy = true;
	tmp->set_node_name(m[6]);
	tmp->set_pay_size(m[9]);
	tmp->firstname = m[12];
	tmp->secondname = m[15];
	tmp->thirdname = m[18];
	tmp->age = m[21];
	tmp->set_sex(m[24]);
	tmp->set_zloy(m[27]);
	tmp->hier = m[30];
	return true;
}

bool parse_general(node *tmp, std::string buffer)
{
	std::match_results<std::string::const_iterator> m;
	std::regex e("([\(]filed[\)])(node_type[\:])([a-zA-Z0-9/s]+)([\(]filed[\)])(node_name[\:])([^\(]+)([\(]filed[\)])(firstname[\:])([^\(]+)([\(]filed[\)])(secondname[\:])([^\(]+)([\(]filed[\)])(thirdname[\:])([^\(\%]+)([\(]filed[\)])(age[\:])([^\(\%]+)([\(]filed[\)])(hier[\:])([^\(\%]*)");
	if (!std::regex_search(buffer, m, e))
	{
		std::cout << buffer << std::endl;
		return false;
	}
	tmp->set_node_name(m[6]);
	tmp->firstname = m[9];
	tmp->secondname = m[12];
	tmp->thirdname = m[15];
	tmp->age = m[18];
	tmp->hier = m[21];
	return true;
}

node * get_spec_node(std::string node_type, std::string buffer)
{
	if (node_type == "proger")
	{
		proger *tmp =  new proger;
		tmp->set_node_type(node_type);
		if (!parse_proger(tmp, buffer)) return NULL;
		return tmp;
	}
	if (node_type == "uborshik")
	{
		uborshik *tmp = new uborshik;
		tmp->set_node_type(node_type);
		if (!parse_uborshik(tmp, buffer)) return NULL;
		return tmp;
	}
	if (node_type == "admin")
	{
		admin *tmp = new admin;
		tmp->set_node_type(node_type);
		if (!parse_admin(tmp, buffer)) return NULL;
		return tmp;
	}
	if (node_type == "general")
	{
		node *tmp = new node;
		tmp->set_node_type(node_type);
		if (!parse_general(tmp, buffer)) return NULL;
		return tmp;
	}
	return NULL;
	
}

node * db::parse_node_buffer(std::string buffer, std::string table_name)
{
	node *tmp = NULL;
	std::string node_type;
	std::match_results<std::string::const_iterator> m, m0;
	std::regex e("([\(]filed[\)])(node_type[\:])([a-zA-Z0-9\s]+)([\(]filed[\)])");
	std::regex e0("");
	if (!std::regex_search(buffer, m, e))
	{
		return NULL;
	}
//	std::cout << "NODE TYPE:" << std::endl;
//	std::cout << m[3] << std::endl;
	node_type = m[3];
	tmp = get_spec_node(node_type, buffer);
	if (tmp == NULL) return NULL;
	
	/*
	e0 = "(class\s)("  + node_type + ")";

	if (!std::regex_search((std::string)typeid(*tmp).name(), m0, e0))
	{
		return false;
	}
	if (m[2] == "proger")
	{
		parse_proger(
	}
	std::cout << "typeid name " << typeid(*tmp).name() << std::endl;
	*/
	this->add_node(table_name, tmp);
	return tmp;
}

bool db::parse_table_buffer(std::string buffer)
{
	std::string *buf;
	std::string add_buf;
	std::string table_name;
	node * nd;
	uint32_t len = buffer.length();
	std::match_results<std::string::const_iterator> m, m0;
	std::regex e("([^%]+)(%)");
	std::regex e0("([a-zA-Z\s]+)(\(filed\))");
	uint32_t i = 0;
//	std::cout << "PARSE_TABLE_FUNCTION #" << std::endl;
	while (buffer != "")
	{
		if (!std::regex_search(buffer, m, e))
		{
			return false;
		}
		if (i == 0)
		{
			
			table_name = m[0];
			uint32_t position = table_name.find('(', 0);
			add_buf = table_name;
			add_buf.erase(0, position);
			table_name.erase(position, table_name.length() - position);
//			std::cout << '\t' << "table_name is " << table_name << std::endl;
			this->add_table(table_name);
			nd = parse_node_buffer(add_buf, table_name);

			i++;
			buffer.erase(0, m[0].length());
			continue;
		}
//		std::cout << m[0] << std::endl;
		nd = parse_node_buffer(m[0], table_name);
		i++;
		buffer.erase(0, m[0].length());
	}
//	std::cout << "PARSE_TABLE_FUNCTION END #" << std::endl;
//	std::cout << "TABLE NAME IS " << table_name << std::endl;
	/*
	std::cout << "PARSE_TABLE_BUFFER FUNCTION ####" << std::endl;
	std::cout << buffer << std::endl;
	std::cout << m[0] << std::endl;
	std::cout << m[1] << std::endl;
	std::cout << m[2] << std::endl;
	std::cout << m[3] << std::endl;
	std::cout << m[4] << std::endl;
	std::cout << m[5] << std::endl;
	std::cout << "LASKD" << std::endl;
	std::cout << buffer.erase(0, m[0].length()) << std::endl;
	std::cout << "i is:: " << i << std::endl;
	*/
	return true;
}

bool db::parse_buffer(std::string buffer)
{
	std::string buf[MAX_DB_SIZE] = { "" };
	if (buffer == "") return false;
	std::match_results<std::string::const_iterator> m;
	std::regex e("(:db:)(.+)(:tables:)(.+)");
	if (!std::regex_search(buffer, m, e))
	{
		return false;
	}
	/*
	std::cout << "PARSE_BUFFER FUNCTION ###" << std::endl;
	std::cout << m[0] << std::endl;
	std::cout << m[1] << std::endl;
	std::cout << m[2] << std::endl;
	std::cout << m[3] << std::endl;
	std::cout << m[4] << std::endl;
	std::cout << m[5] << std::endl;
	std::cout << m[6] << std::endl;
	std::cout << m[7] << std::endl;
	std::cout << m[8] << std::endl;
	std::cout << m[9] << std::endl;
	std::cout << "PARSE_BUFFER FUNCTION END ###" << std::endl;
	*/
	this->set_name(m[2]);
	uint32_t len = m[4].length();
	std::string m1 = m[4];
	for (uint32_t j = 0, i = 0; i < len; i++)
	{
		if (m1[i] == '|')
		{
			if (!parse_table_buffer(buf[j]))
				return false;
			j++;
			continue;
		}
		if (j == MAX_DB_SIZE)
			return false;
		buf[j] += m1[i];
		

	}
	/*
	std::cout << "VIHLOP PARSE_BUFFER#" << std::endl;
	std::cout << m[0] << std::endl;
	std::cout << m[1] << std::endl;
	std::cout << m[2] << std::endl;
	std::cout << m[3] << std::endl;
	std::cout << m[4] << std::endl;
	std::cout << m[5] << std::endl;
	std::cout << "VIHLOP PARSE_BUFFER# END END END#" << std::endl;
	*/
	return true;
}

bool db::read_dump(void)
{
	//bool parse_buffer(std::string buffer);
	/*
	FILE *fl;
	char *cstr = new char[this->get_file_name().length() + 1];
	strcpy(cstr, this->get_file_name().c_str());
	if((fl = fopen(cstr, "wb+")) == NULL)
	{
	return false;
	}
	delete [] cstr;
	fclose(fl);
	*/
	std::ifstream fin(this->get_file_name(), std::ios_base::binary);
	if (!fin.is_open())
	{
		return false;
	}
	char ch = 0x0;
	uint32_t i = 0;
	std::string buffer[MAX_DB_DB_SIZE] = { "" };
	while (!fin.eof())
	{
		
		
		fin.read(&ch, sizeof(char));
		if (ch == '*')
		{
			if (!parse_buffer(buffer[i]))
			{
				return false;
			}
			i++;
			continue;
		}
		if (i == MAX_DB_DB_SIZE)
			return false;
		buffer[i] += ch;
	}
	fin.close();
	/*
	std::match_results<std::string::const_iterator> m;
	std::regex e("(:db:)(.+)(:tables:)(.+)(\\*)");
	std::regex_search(buffer, m, e);
	this->set_name(m[2]);
	std::cout << m[3] << std::endl;
	std::cout << m[2] << std::endl;
	*/
	
	return true;
}