#include "List.h"

using namespace std;

List::list_node::list_node(car& c, list_node* n): data(&c), next(n)
{
}

void List::list_node::print_node()
{

}

List::List()
{
	head = NULL;
	size_of_list = 0;

	cout << "-->List constructed" << endl;
}

List::~List()
{
    list_node *current_node = head;
    list_node *temp_node = NULL;
	while(current_node != NULL)
	{
		temp_node = current_node;
		current_node = current_node->next;
		delete temp_node;
	}
	cout << "-->List destructed" << endl;
}

void List::pushFront(car& c)
{
	list_node *temp = head;
	head = new list_node(c, temp);
	size_of_list++;
}

void List::popFront()
{
    list_node *temp = head;
    head = head->next;
    delete temp;
}

void List::print_list()
{
	list_node *current_node = head;

	for(int i=0; i<size_of_list; i++)
	{
		current_node->print_node();
		cout << endl;
		current_node = current_node->next;
	}
}

void List::push_from_list(List& l) //inserts all posts of List l
{                                  //to this List (used in enhance)
    list_node* temp = l.head;

    for(int i=0; i<l.size_of_list; i++)
    {
        pushFront(*(temp->data));
        temp = temp->next;
    }
}
