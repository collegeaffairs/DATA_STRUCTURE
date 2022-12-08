//Q7 practical list 
// stack implementation using linked list 
#include<iostream>
using namespace std;

// template <typename J>
class node{
	public:
	int data;
	node* next;
	
		node(int val, node*ptr=0){
			data=val;
			next=ptr;
		}
	//template <class u>
	friend class SLL;
	friend class stack;
};

//template <class E>
class SLL{
	public:
	node* head;

		SLL(){
			head =0;
		}
	
		

void add_to_head(int val){
	head = new node(val, head);
}

void display(){
	node* ptr = head;
	while(ptr) // ptr is non 0
	{
		cout <<ptr->data  <<" "; 
		ptr = ptr->next;
	}
	cout << endl;
} 
int remove_from_begining(){
	if(head){
		node* ptr =head; // pointer should starts from head.
		int val=ptr->data;
		head = head->next;
		delete ptr;  // delete is a function use to delete pointer.
		return val;
	}else{
		return 0;
	}
}

friend class stack;
};


class stack{
	SLL l;
	int tos;
	int cp;
	public:
	stack(){
		tos = -1;
	}

	void push(int el){
		l.add_to_head(el);
		++tos;
	}

	int size(){
		int count = 0;
		node* ptr = l.head;
		while(ptr){
			count++;
			ptr=ptr->next;
		}
		return count;
	}

	bool isEmpty(){
		return (l.head==0);
	}

	void pop(){
		if(!isEmpty()){
			l.remove_from_begining();
			cout << "Element poped " << endl;
			--tos;
		}
		else
		cout << "stack underflow" << endl;
	}

	int topEl(){
		if(l.head)
			return l.head->data;
	}

	void clear(){
		while(l.head){
			l.remove_from_begining();
		}
	}

};
	void menuOption(){
	cout<<"1. -> push\n";
	cout<<"2. -> pop\n";
	cout<<"3. -> size\n";
	cout<<"4. -> top of stack\n";
	cout<<"5. -> isEmpty\n";
	cout<<"6..-> Exit\n";	
	}
	
int main(){
	stack s;
	menuOption();
	

	bool flag = false;
	while(!flag){
		int select;
		cout<<"Make choice: " << endl;
	cin >> select;
	switch(select){
		case 1:
			cout << "Enter item to push: ";
			int value;
			cin >> value;
			s.push(value);
			break;
		case 2:
			 s.pop();
			break;
			
		case 3:
			cout << "Current Size of stack: " << s.size() << endl;
			break;
				
		case 4:
			cout << s.topEl() << " is the top of the stack." << endl;
			break;
		case 5:
			if(s.isEmpty())
				cout << "Empty stack: ";
			else
			cout << "Stack not empty." << endl;
			break;

		case 6:
					cout << "Exited" << endl;
					flag = true;
					break;								
											
		default:
				cout << "You have enter wrong choice.\n";
				
						
}
}
return 0;
}
