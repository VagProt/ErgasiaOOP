#ifndef _List_h
#define _List_h

#include <iostream>
#include <string>

using namespace std;

class car;
//declaration off class List

class List
{
    public:
		List();
		~List();

		void pushFront(car&);
		void popFront();
		void print_list();
		void push_from_list(List&);

    private:
        struct list_node //declaring struct list_node nested in List
        {
                list_node(car&, list_node*);
                void print_node();

                car* data;
                list_node* next;
        };

        list_node *head;
        int size_of_list;
};

#endif // _List_h
