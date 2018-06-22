#include <cstring>
#include <iostream> 

using namespace std;


template<class T> class node {
public:
	T data;
	node<T>* tail;
	node() {
		tail = NULL;
	}
};
 
template<class T> class list {
private:
	node<T>* head;
	node<T>* front;

public:
	list() {
		head = NULL;
		front = NULL;
	}

	
	/*Начало вашего кода*/
	//TODO: Пишите код тут
	//
	//
	
	void push(T *Prod)
	{
		node<T>* TmpNode=new node<T>;
		TmpNode->data=*Prod;
				
		if(head==0) head=front;
		
		TmpNode->tail=front;
		front=TmpNode;
		
		cout << "Pushed: " << TmpNode->data.name << endl;

	}
	

	/*Конец вашего кода*/
	/*Памятка! Если вы стёрли строки доступные для редактирования - нажмите F5*/


	class iterator {
		node<T>* n;
	public:
		iterator() {
			n = NULL;
		}

		iterator(node<T>* t) : n(t) {

		}
  
		T& operator *() {
			return n->data;
		}

		iterator& operator ++(int) {
			n = n->tail;
			return *this;
		}

		bool operator ==(iterator it) {
			return it.n == this->n;
		}

		bool operator !=(iterator it) {
			return it.n != this->n;
		}


	};

	iterator begin()
	{
		return iterator(front);
	}

	iterator end()
	{
		return NULL;
	}

};


class product{
public:
	char name[32];
	float price;

	product() {

	}

	product(char* n,  float p) {
		strcpy(name, n);
		price = p;
	}
};


int main()
{  
	product p1 ("Milk", 55.0f);
	product p2 ("Bread", 10.5f);
	product p3 ("Cheese", 300.0f);

	list<product> store;

	store.push(&p1); 
	store.push(&p2); 
	store.push(&p3); 
  
	for(list<product>::iterator i = store.begin(); i != store.end(); i++)
	{
		product tmp = *i;
		cout << tmp.name << endl;
	}
 
	return 0;
}
