//Q9 

#include<iostream>
using namespace std;


class node{
	public:
	int data;
	node* next;
	
		node(int val, node*ptr=0){
			data=val;
			next=ptr;
		}
	friend class queue;
	friend class CLL;
};


class CLL{
	public:
	node* cursor;

		CLL(){
			cursor =0;
		}
int front(){
	return (cursor-> next->data);
}	

int back(){
	return (cursor-> data);
}

void advance(){
	cursor = cursor->next;
}

void addToFront(int el){
	node* ptr = new node(el);
	if(cursor == 0){
		cursor =ptr;
		cursor->next = cursor;
		
	}else{
		ptr->next = cursor->next;
		cursor->next = ptr;
	}
}

void addToBack(int el){
	addToFront(el);
	advance();
}

void display(){
	node* ptr = cursor->next;
	 // ptr is non 0
	do{
		cout << ptr->data  <<" "; 
		ptr = ptr->next;
	}while(ptr != cursor->next);
	cout << endl;
} 

bool isEmpty(){
	return(cursor == 0);
}

node* search(int el){
//	if(isEmpty) return 0;
	node* ptr= cursor -> next;
	do{
		if(ptr -> data == el) 
		return ptr;
		ptr = ptr-> next;
	}
	while(ptr != cursor-> next);	
	return 0;
}

void remove(){
	if (isEmpty())
	 return;
    else if(cursor->next == cursor){
			delete cursor; // first delete data
			cursor = 0;   // setting value of cursor to 0
		}
	else{   
			node* temp = cursor -> next;
			cursor->next = temp -> next;
			delete temp;	
		}
	}
	
friend class queue;
};

class queue{
	CLL l;
	int n;
	public:
		queue(){
			n = 0;
		}

		void enqueue(int el){
			l.addToBack(el);
			n++;
			cout << "Element enqueued" << endl;
		}

		void dequeue(){
			if(l.isEmpty()){
				cout << "Queue Underflow" << endl;
				return;
			}
			else{
			l.remove();
			n--;
			}
		}

		bool isEmpty(){
			return (n==0);
		}

		int size(){
			return n;
		}

		int frontEl(){
			return l.front();
		}

		void display(){
			l.display();
		}

};

int main(){
	queue q;
	cout<<"Slect:\n";
	cout<<"1. Enqueue\n";
	cout<<"2. Dequeue\n";
	cout<<"3. to isEmpty\n";
	cout<<"4. front element\n";
	cout<<"5. Exit\n";
	bool flag = false;
	while(!flag){
		int select;
		cout<<"Make choice: " << endl;
	cin >> select;
	switch(select){
		case 1:
			cout << "Enter item to add: ";
			int value;
			cin >> value;
			q.enqueue(value);
			break;
		case 2:
			q.dequeue();
			break;
		case 3:
			if (q.isEmpty())
			cout << "Queue is empty" << endl;
			else
			cout << "Queue is not empty" << endl;
			break;
		case 4:
			if(q.isEmpty())
				cout << "Empty Queue" << endl;
			else
				cout << "Front is "<<q.frontEl() << endl;
			break;
		case 5:
			flag = true;
			break;
		default:
				cout << "Invalid Value";
							
	}
	
	}

}//main
