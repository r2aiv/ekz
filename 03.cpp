#include <cstring>
#include <iostream> 

using namespace std;
 


class product {
public:
	char name[32];
	float price;
	product() {
	}

	product(product& p) {
		this->price = p.price;
		strcpy(this->name, p.name);
	}

	product(char* n, float p) {
		strcpy(name, n);
		price = p;
	}

};

class node {
public:
	product* data;
	node* tail;

	node() {
		tail = NULL;
	}
};
 
 
class queue_priority {
private:
	node* header;
	node* font;
public:

	queue_priority(){
		header = NULL;
		font = NULL;
	}

	void push(product* data) {
		node* n = new node();
		n->data = data;
		if (header != NULL)
			header->tail = n;

		if (font == NULL)
			font = n;

		header = n;

		sort();
	}

	product* pop() {

		product* r = font->data;

		font = font->tail;

		return r;

	}

	void sort() {


	/*Начало вашего кода*/
	//TODO: Пишите код тут

	/*Конец вашего кода*/
	/*Памятка! Если вы стёрли строки доступные для редактирования - нажмите F5*/


	}

	void swap(node* a, node* b)
	{
		product* temp = a->data; 

		a->data = b->data;

		b->data = temp;
	}

	bool empty() {
		return font == NULL;
	}

};



int main()
{  
	product* p1 = new product("Milk", 55.0f);
	product* p2 = new product("Bread", 10.5f);
	product* p3 = new product("Cheese", 300.0f); 
	product* p4 = new product("Beer", 70.0f);
	product* p5 = new product("Potatoes", 20.0f);

	queue_priority store;
	store.push(p1);
	store.push(p2);
	store.push(p3);
	store.push(p4);
	store.push(p5);
	
	while (!store.empty())
	{
		product* tmp = store.pop();
		cout << tmp->name << endl;
	} 
 
	return 0;
}
