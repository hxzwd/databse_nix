
#include "misc.h"
#include "menu.h"



int main(void)
{
/*	int c;
	node *t_node;
	t_node = new proger;
	t_node->set_node_name("proger one");
	dynamic_cast<proger *>(t_node)->set_pay_size(3000);
	db tmp("new db", 0);
	tmp.add_table("new table");
	tmp.add_table("second table");
	tmp.add_node("new table", t_node);
	t_node = new proger;
	t_node->set_node_name("proger five");
	tmp.add_node("new table", t_node);
	t_node = new proger;
	t_node->set_node_name("proger from second table");
	tmp.add_node("second table", t_node);
	tmp.show();
	tmp.init("test.txt");
	if(!tmp.write_dump())
	{
		std::cout << std::endl << "cannot open the file" << std::endl;
	} 
	tmp.read_dump();
	std::cin >> c;
	*/
	proger *p0, *p1, *p2, *p3, *p4, *p5;
	admin *a0;
	uborshik *u0, *u1;
	a0 = new admin;
	u0 = new uborshik;
	u1 = new uborshik;
	a0->set_node_type("admin");
	a0->set_node_name("admin single");
	a0->set_pay_size("100000");
	a0->set_zloy("true");
	a0->firstname = "admin firstname";
	a0->secondname = "admin secondname";
	a0->thirdname = "admin thirdname";
	a0->age = "1000";
	a0->set_sex("not stated");
	u0->set_node_type("uborshik");
	u1->set_node_type("uborshik");
	u0->set_node_name("uborshik one");
	u1->set_node_name("uborshik two");
	u0->set_pay_size("1200");
	u1->set_pay_size("1300");
	u0->set_sex("male");
	u1->set_sex("female");
	u0->age = "15";
	u1->age = "23";
	u0->firstname = "troyan";
	u0->secondname = "boyanov";
	u0->thirdname = "vasilevich";
	u1->firstname = "masha";
	u1->secondname = "boyanova";
	u1->thirdname = "troyanova";
	p0 = new proger;
	p1 = new proger;
	p2 = new proger;
	p3 = new proger;
	p4 = new proger;
	p5 = new proger;
	p0->set_lang_of_prog("c++");
	p1->set_lang_of_prog("c#");
	p2->set_lang_of_prog("assembler");
	p3->set_lang_of_prog("pascal");
	p4->set_lang_of_prog("php");
	p5->set_lang_of_prog("c/c++");
	p0->firstname = "ivan";
	p0->secondname = "petrov";
	p0->thirdname = "petrovich";
	p0->age = "28";
	p1->firstname = "petr";
	p1->secondname = "ivanov";
	p1->thirdname = "ivanovich";
	p1->age = "23";
	p2->firstname = "katya";
	p2->secondname = "ivanova";
	p2->thirdname = "ivanovna";
	p2->age = "18";
	p3->firstname = "sidr";
	p3->secondname = "ivanov";
	p3->thirdname = "petrovich";
	p3->age = "40";
	p4->firstname = "misha";
	p4->secondname = "petrov";
	p4->thirdname = "ivanovich";
	p4->age = "13";
	p5->firstname = "nadya";
	p5->secondname = "ivanova";
	p5->thirdname = "petrovna";
	p5->age = "30";
	p0->set_node_name("proger one");
	p1->set_node_name("proger two");
	p2->set_node_name("proger three");
	p3->set_node_name("proger four");
	p4->set_node_name("proger five");
	p5->set_node_name("proger six");
	p2->hier = "1: proger(1, 2, 3)";
	p0->set_node_type("proger");
	p1->set_node_type("proger");
	p2->set_node_type("proger");
	p3->set_node_type("proger");
	p4->set_node_type("proger");
	p5->set_node_type("proger");
	p0->set_pay_size("1337");
	p1->set_pay_size("228");
	p2->set_pay_size("322");
	p3->set_pay_size("13");
	p4->set_pay_size("150000000");
	p5->set_pay_size("10000");
	db test_write("newbw", 0);
	db test_read("newbr", 0);
	test_write.add_table("table one");
	test_write.add_table("table two");
	test_write.add_table("table three");
	test_write.init("test.txt");
	test_write.add_node("table one", (node *)p1);
	test_write.add_node("table one", (node *)p2);
	test_write.add_node("table three", (node *)p3);
	test_write.add_node("table three", (node *)p4);
	test_write.add_node("table three", (node *)p5);
	test_write.add_node("table three", (node *)p0);
	test_write.add_node("table three", (node *)a0);
	test_write.add_node("table one", (node *)u1);
	test_write.add_node("table three", (node *)u0);
	test_write.write_dump();
	test_read.init("test.txt");
	test_read.read_dump();
	
	
//	test_write.show();
	
	
	menu mn;
	mn.database = &test_read;
	mn.show_menu();
	/*
	test_read.show();
	std::vector<node *> *tmp = test_read.find_node_on_node_name("", "proger five");
	if (tmp != NULL)
	{

		std::cout << tmp->at(0)->drop_all() << std::endl;
		delete tmp;
	}
	proger *p = new proger;
	p->secondname = "ivanova";

	std::vector<node *> *tmp0 = test_read.find_specific_node_on_any_field("", (node *)p);
	
	if (tmp0 != NULL)
	{
	
		std::cout << ((proger *)(tmp0->at(0)))->firstname << std::endl;
		std::cout << ((proger *)(tmp0->at(1)))->firstname << std::endl;
		delete tmp0;
	}
	else
	{
		std::cout << "tmp0 is null" << std::endl;
	}
	delete p;
	*/
	return 0;
}
