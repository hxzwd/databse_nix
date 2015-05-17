#include "misc.h"


class menu
{
public:
	db *database;
	void show_menu(void);
	void make_inquiry(void);
	void show_db(void);
	void delete_node(void);
	void add_node(void);
	void add_table(void);
	void edit_node(void);
	void show_sorted(void);
	node * make_node_from_keyboard();

};