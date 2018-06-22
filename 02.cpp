#include <cstring>
#include <iostream> 

using namespace std;
 
template<class T> class node {
public:
	T data;
	node<T>* left;
	node<T>* right;

	node() { 
		left = NULL;
		right = NULL;
	}
};
 

template<class T>  class tree 
{

private:
	node<T>* root;

	void push(node<T>* parent, T& obj)	{
		if (parent->data < obj )		{
			if (parent->left == NULL) {
				parent->left = new node<T>();
				parent->left->data = obj;
			}
			else {
				push(parent->left, obj);
			}
		}
		else { 
			if (parent->right == NULL) {
				parent->right = new node<T>();
				parent->right->data = obj;
			}
			else {
				push(parent->right, obj);
			}
		}
	}

	void print(node<T>* parent){
		if (parent != NULL){
			print(parent->left);
			cout << parent->data << endl;
			print(parent->right);
		}
	}

public:

	tree() {
		root = NULL; 
	}

	void push(T& obj) {
		if (root == NULL) {
			root = new node<T>();
			root->data = obj;
		}
		else {
			push(root, obj);
		}
	}

	void print()	{
		print(root);
	}
};



class product{
public:
	char name[32];
	float price;

	product() {

	}

	product(product& p) {
		this->price = p.price;
		strcpy(this->name, p.name);
	}

	product(char* n,  float p) {
		strcpy(name, n);
		price = p;
	} 


	/*Начало вашего кода*/
	//TODO: Пишите код тут

	/*Конец вашего кода*/
	/*Памятка! Если вы стёрли строки доступные для редактирования - нажмите F5*/
 

	friend ostream& operator <<(ostream &os, product& p) {
		os << p.name;
		return os;
	}
};


int main()
{  
	product p1 ("Milk", 55.0f);
	product p2 ("Bread", 10.5f);
	product p3 ("Cheese", 300.0f);
	product p4 ("Beer", 70.0f);
	product p5 ("Potatoes", 20.0f);

	tree<product> store;
	store.push(p1);
	store.push(p2);
	store.push(p3);
	store.push(p4);
	store.push(p5);
	
	store.print();
 
	return 0;
}
