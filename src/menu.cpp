#include "menu.h"

node *make_admin_from_kb(void)
{
	std::string kb_buffer;
//	bool zloy = false;
	admin *tmp = new admin;
	tmp->set_node_type("admin");
	std::cout << "enter admin node name(must be unique): ?>";
	std::getline(std::cin, kb_buffer);
//	std::cin.ignore(1, '\n');
	if (kb_buffer == "#") kb_buffer = "";
	tmp->set_node_name(kb_buffer);
	std::cout << "enter firstname: ?>";
	std::getline(std::cin, kb_buffer);
//	std::cin.ignore(1, '\n');
	if (kb_buffer == "#") kb_buffer = "";
	tmp->firstname = kb_buffer;
	std::cout << "enter secondname: ?>";
	std::getline(std::cin, kb_buffer);
//	std::cin.ignore(1, '\n');
	if (kb_buffer == "#") kb_buffer = "";
	tmp->secondname = kb_buffer;
	std::cout << "enter thirdname: ?>";
	std::getline(std::cin, kb_buffer);
//	std::cin.ignore(1, '\n');
	if (kb_buffer == "#") kb_buffer = "";
	tmp->thirdname = kb_buffer;
	std::cout << "enter age: ?>";
	std::getline(std::cin, kb_buffer);
//	std::cin.ignore(1, '\n');
	if (kb_buffer == "#") kb_buffer = "";
	tmp->age = kb_buffer;
	std::cout << "enter size of pay: ?>";
	std::getline(std::cin, kb_buffer);
//	std::cin.ignore(1, '\n');
	if (kb_buffer == "#") kb_buffer = "";
	tmp->set_pay_size(kb_buffer);
	std::cout << "enter sex: ?>";
	std::getline(std::cin, kb_buffer);
//	std::cin.ignore(1, '\n');
	if (kb_buffer == "#") kb_buffer = "";
	tmp->set_sex(kb_buffer);
	std::cout << "enter zloy or not(true, false): ?>";
	std::getline(std::cin, kb_buffer);
	//std::cin.ignore(1, '\n');
	if (kb_buffer == "#") kb_buffer == "";
	tmp->set_zloy(kb_buffer);
	std::cout << "enter hierarchy: ?>";
	std::getline(std::cin, kb_buffer);
//	std::cin.ignore(1, '\n');
	if (kb_buffer == "#") kb_buffer = "";
	tmp->hier = kb_buffer;
	return tmp;
}

node * make_uborshik_from_kb(void)
{
	std::string kb_buffer;
	uborshik *tmp = new uborshik;
	tmp->set_node_type("uborshik");
	std::cout << "enter uborshik node name(must be unique): ?>";
	std::getline(std::cin, kb_buffer);
	if (kb_buffer == "#") kb_buffer = "";
	tmp->set_node_name(kb_buffer);
	std::cout << "enter firstname: ?>";
	std::getline(std::cin, kb_buffer);
	if (kb_buffer == "#") kb_buffer = "";
	tmp->firstname = kb_buffer;
	std::cout << "enter secondname: ?>";
	std::getline(std::cin, kb_buffer);
	if (kb_buffer == "#") kb_buffer = "";
	tmp->secondname = kb_buffer;
	std::cout << "enter thirdname: ?>";
	std::getline(std::cin, kb_buffer);
	if (kb_buffer == "#") kb_buffer = "";
	tmp->thirdname = kb_buffer;
	std::cout << "enter age: ?>";
	std::getline(std::cin, kb_buffer);
	if (kb_buffer == "#") kb_buffer = "";
	tmp->age = kb_buffer;
	std::cout << "enter size of pay: ?>";
	std::getline(std::cin, kb_buffer);
	if (kb_buffer == "#") kb_buffer = "";
	tmp->set_pay_size(kb_buffer);
	std::cout << "enter sex: ?>";
	std::getline(std::cin, kb_buffer);
	if (kb_buffer == "#") kb_buffer = "";
	tmp->set_sex(kb_buffer);
	std::cout << "enter hierarchy: ?>";
	std::getline(std::cin, kb_buffer);
	if (kb_buffer == "#") kb_buffer = "";
	tmp->hier = kb_buffer;
	return tmp;
}

node * make_proger_from_kb(void)
{
	std::string kb_buffer;
	std::regex e("");
	std::match_results<std::string::const_iterator> m;
	proger *tmp = new proger;
	tmp->set_node_type("proger");
	std::cout << "enter proger node name(must be unique): ?>";
	std::getline(std::cin, kb_buffer);
	if (kb_buffer == "#") kb_buffer = "";
	tmp->set_node_name(kb_buffer);
	std::cout << "enter firstname: ?>";
	std::getline(std::cin, kb_buffer);
	if (kb_buffer == "#") kb_buffer = "";
	tmp->firstname = kb_buffer;
	std::cout << "enter secondname: ?>";
	std::getline(std::cin, kb_buffer);
	if (kb_buffer == "#") kb_buffer = "";
	tmp->secondname = kb_buffer;
	std::cout << "enter thirdname: ?>";
	std::getline(std::cin, kb_buffer);
	if (kb_buffer == "#") kb_buffer = "";
	tmp->thirdname = kb_buffer;
	std::cout << "enter age: ?>";
	std::getline(std::cin, kb_buffer);
	if (kb_buffer == "#") kb_buffer = "";
	tmp->age = kb_buffer;
	std::cout << "enter size of pay: ?>";
	std::getline(std::cin, kb_buffer);
	if (kb_buffer == "#") kb_buffer = "";
	tmp->set_pay_size(kb_buffer);
	std::cout << "enter lang of programming: ?>";
	std::getline(std::cin, kb_buffer);
	if (kb_buffer == "#") kb_buffer = "";
	tmp->set_lang_of_prog(kb_buffer);
	std::cout << "enter hierarchy: ?>";
	std::getline(std::cin, kb_buffer);
	if (kb_buffer == "#") kb_buffer = "";
	tmp->hier = kb_buffer;
	return (node *)tmp;
}

node * make_general_from_kb(void)
{
	std::string kb_buffer;
	node *tmp = new node;
	tmp->set_node_type("");
	std::cout << "enter general node name(must be unique): ?>";
	std::getline(std::cin, kb_buffer);
	if (kb_buffer == "#") kb_buffer = "";
	tmp->set_node_name(kb_buffer);
	std::cout << "enter firstname: ?>";
	std::getline(std::cin, kb_buffer);
	if (kb_buffer == "#") kb_buffer = "";
	tmp->firstname = kb_buffer;
	std::cout << "enter secondname: ?>";
	std::getline(std::cin, kb_buffer);
	if (kb_buffer == "#") kb_buffer = "";
	tmp->secondname = kb_buffer;
	std::cout << "enter thirdname: ?>";
	std::getline(std::cin, kb_buffer);
	if (kb_buffer == "#") kb_buffer = "";
	tmp->thirdname = kb_buffer;
	std::cout << "enter age: ?>";
	std::getline(std::cin, kb_buffer);
	if (kb_buffer == "#") kb_buffer = "";
	tmp->age = kb_buffer;
	std::cout << "enter hierarchy: ?>";
	std::getline(std::cin, kb_buffer);
	if (kb_buffer == "#") kb_buffer = "";
	tmp->hier = kb_buffer;
	return tmp;
}

node * menu::make_node_from_keyboard(void)
{
	std::string type_of_node;
	std::string kb_buffer;
	node *tmp = NULL;
	std::cout << "Available types are proger, admin, uborshik, general" << std::endl;
	std::cout << "Enter type of node: ?>";
	std::getline(std::cin,  type_of_node);
//	std::cin.ignore(1, '\n');
	if (type_of_node == "proger")
	{
		tmp = make_proger_from_kb();
	}
	if (type_of_node == "uborshik")
	{
		tmp = make_uborshik_from_kb();
	}
	if (type_of_node == "admin")
	{
		tmp = make_admin_from_kb();
	}
	if (type_of_node == "general")
	{
		tmp = make_general_from_kb();
	}
	return tmp; 
}

void menu::make_inquiry(void)
{
	node *tmp;
	std::vector<node *> *vec;
	std::string kb_buffer;
	std::cout << "search node#:" << std::endl;
	std::cout << "any table(name of table or all: ?>";
	std::getline(std::cin, kb_buffer);
	std::cin.ignore(7777, '\n');
	if (kb_buffer == "all") kb_buffer = "";
	tmp = this->make_node_from_keyboard();
	vec = this->database->find_specific_node_on_any_field(kb_buffer, tmp);
	if (vec == NULL)
	{
		std::cout << "not found" << std::endl;
		return;
	}
	for (std::vector<node *>::iterator it = vec->begin(); it != vec->end(); ++it)
	{
		show_node_u(*it);
	}
	delete vec;
}

void menu::show_db(void)
{
	this->database->show();
}

void menu::delete_node(void)
{
	node *tmp;
	std::vector<node *> *vec;
	std::string kb_buffer;
	std::cout << "search node for del#:" << std::endl;
	std::cout << "any table(name of table or all: ?>";
	std::getline(std::cin, kb_buffer);
	std::cin.ignore(7777, '\n');
	if (kb_buffer == "all") kb_buffer = "";
	tmp = this->make_node_from_keyboard();
	vec = this->database->find_specific_node_on_any_field(kb_buffer, tmp);
	if (vec == NULL)
	{
		std::cout << "not found" << std::endl;
		return;
	}
	for (std::vector<node *>::iterator it = vec->begin(); it != vec->end(); ++it)
	{
		if (this->database->delete_node(*it))
		{
			std::cout << "element deleted" << std::endl;
		}
		else
		{
			std::cout << "element not deleted" << std::endl;
		}
	}
	delete vec;
}

void menu::add_table(void)
{
	std::cout << "Enter table name: ?>";
	std::string kb_buffer;
	std::cin.ignore(100, '\n');
	std::getline(std::cin, kb_buffer);
	if (!this->database->add_table(kb_buffer))
	{
		std::cout << "cannnot add table " << kb_buffer << std::endl;
	}
}

void menu::add_node(void)
{
	node *tmp = NULL;
	std::string kb_buffer;
	std::cout << "Enter table name: ?>";
	std::cin.ignore(100, '\n');
	std::getline(std::cin, kb_buffer);
	tmp = this->make_node_from_keyboard();
	if (typeid(tmp).name() == "class node *")
	{
		tmp->set_node_type("general");
	}
	if (tmp == NULL)
	{
		std::cout << "Invalid node" << std::endl;
	}
	if (!this->database->add_node(kb_buffer, tmp))
	{
		std::cout << "Can not add node" << std::endl;
	}
}

void menu::edit_node(void)
{

}

std::string compare_by_firstname(node *one)
{
	return one->firstname;
}

std::string compare_by_age(node *one)
{
	return one->age;
}

std::string compare_general(node *one)
{
	return one->get_node_type();
}

std::string (*get_compare_function(std::string buffer))(node *)
{
	if (buffer == "firstname")
	{
		return &compare_by_firstname;
	}
	if (buffer == "age")
	{
		return &compare_by_age;
	}
	return &compare_general;
}

void menu::show_sorted(void)
{
	std::string kb_buffer;
	std::cout << "Enter table name(or all): ?>";
	std::cin.ignore(1, '\n');
	std::getline(std::cin, kb_buffer);
	if (kb_buffer == "all")
	{
		kb_buffer = "";
	}
	std::vector<node *> *tmp = this->database->node_vector(kb_buffer);
	if (tmp == NULL)
	{
		std::cout << "cannot get vector node" << std::endl;
		return;
	}
	if (tmp->empty())
	{
		std::cout << "tmp is empty" << std::endl;
		return;
	}
	std::cout << "choose param for sorting(firstname, secondname, thirdname, age, hier: ?>";
	std::cin.ignore(1, '\n');
	std::getline(std::cin, kb_buffer);
	std::multimap<std::string, node *> *mmap = new std::multimap<std::string, node *>;
	for (auto it = tmp->begin(); it != tmp->end(); ++it)
	{
		mmap->insert(std::pair<std::string, node *>(get_compare_function(kb_buffer)(*it), *it));
	}
	for (auto it = mmap->begin(); it != mmap->end(); ++it)
	{
		show_node_u(it->second);
	}
	delete tmp;
	delete mmap;
}

void menu::show_menu(void)
{
	std::string kb_buffer;
	std::cout << "SUPER MENU" << std::endl;
	std::cout << "1: show db" << std::endl;
	std::cout << "2: make inquiry" << std::endl;
	std::cout << "3: delete node" << std::endl;
	std::cout << "4: edit node" << std::endl;
	std::cout << "5: add table" << std::endl;
	std::cout << "6: add node" << std::endl;
	std::cout << "7: show sorted" << std::endl;
	std::cout << "8: quit" << std::endl;
	std::cout << "?>";
	std::cin >> kb_buffer;
	if (kb_buffer == "7")
	{
		this->show_sorted();
	}
	if (kb_buffer == "4")
	{
		this->edit_node();
	}
	if (kb_buffer == "5")
	{
		this->add_table();
	}
	if (kb_buffer == "6")
	{
		this->add_node();
	}
	if (kb_buffer == "2")
	{
//		std::cin.ignore(1, '\n');
		this->make_inquiry();
	}
	if (kb_buffer == "8")
		exit(0);
	if (kb_buffer == "1")
	{
//		std::cin.ignore(1, '\n');
		show_db();
	}
	if (kb_buffer == "3")
	{
		this->delete_node();
	}
	this->show_menu();
		
}