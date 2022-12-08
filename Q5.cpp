//Circular linked list 

#include<iostream>
using namespace std;

template <typename J>
class node{
	public:
	J data;
	node<J>* next;
	
		node(J val, node<J>*ptr=0){
			data=val;
			next=ptr;
		}
	template <class u>
	friend class SLL;
};

template <class E>
class SLL{
	public:
	node<E>* cursor;

		SLL(){
			cursor =0;
		}
E front(){
	return (cursor-> next->data);
}	

E back(){
	return (cursor-> data);
}

void advance(){
	cursor = cursor->next;
}

void addToFront(int el){
	node<E>* ptr = new node<E>(el);
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
	node<E>* ptr = cursor->next;
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

node<E>* search(E el){
//	if(isEmpty) return 0;
	node<E>* ptr= cursor -> next;
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
			node<E>* temp = cursor -> next;
			cursor->next = temp -> next;
			delete temp;	
		}
	}

	void concat(SLL l){
		if(!l.isEmpty()){
			node<E>*ptr = l.cursor->next;
			l.cursor->next=this->cursor->next;
			this->cursor->next=ptr;
			this->cursor=l.cursor;
			l.cursor=0;
		}
	}

	void add_with_el(E ele,E v){
		if(!isEmpty()){
			node<E>*temp = new node<E>(ele);
			node<E>*ptr = search(v);
			temp->next=ptr->next;
			ptr->next=temp;

		}
	}
	
	void removeElemnet(E el){
		if (isEmpty())
	 		return;
   		else 
		{
			node<E>* ptr = cursor->next;
			node<E>* prev = cursor;
			do{
				if(ptr->data==el)
					break;
				prev = ptr;
				ptr=ptr->next;
			}while(ptr != cursor->next);
			prev->next=ptr->next;
			delete ptr;

		}
	}

};
void menuOption(){
	cout << "1. -> add element to front\n";
	cout << "2. -> add element to back\n";
	cout << "3. -> display front element\n";
	cout << "4. -> display last element\n";
	cout << "5. -> advance Circular Linked List\n";
	cout << "6. -> remove cursor -> next element\n";
	cout << "7. -> search an element\n";
	cout << "8. -> display elements.\n";
	cout << "9. -> remove front element !!!\n";
	cout << "10.-> remove back element !!!\n";
	cout << "11.-> concatenate two lists !!!\n";
	cout << "12.-> add an element x after an element y from the list\n";
	cout << "13 -> Exit!!!!!\n";
}

int main(){
		SLL <int>s;
		SLL <int>s2;
	SLL<int>* s1;
	menuOption();
	
	bool flag = false;
	while(!flag){
		int select;
		cout<<"Make choice: " << endl;
	cin >> select;
	switch(select){
		case 1: 
			cout << "Enter element to add: ";
			int frontValue;
			cin >> frontValue;
			s.addToFront(frontValue);
			cout << frontValue << " element is added." << endl;
			break;
			
		case 2:
			cout << "Enter element to add: ";
			int backValue;
			cin >> backValue;
			s.addToBack(backValue);
			cout << backValue << " element is added." << endl;
			break;
			
		case 3:
			cout << "Front element " << s.front();
			break;
			 
		case 4:
			cout << "Back element " << s.back();	
			break;
			
		case 5:
			s.advance();
			cout << "Circular Linked List Advacned" << endl;
			break;
			
		case 6: 
		if(!s.isEmpty()){
			cout << "Enter element to remove: " ;
			int rel;
			cin >> rel;
			if(s.search(rel)){
			s.removeElemnet(rel);
			cout << rel << " is removed.\n ";	
			}
			else{
				cout << rel << " not found.\n";
			}
			
		}
		else
		cout << "List is empty !!!!\n";
		break;
		case 7:
			cout << "Enter element to search : ";
			int searchElement;
			cin >> searchElement;
			if(s.search(searchElement)){
				cout << searchElement << " is at address: " << s.search(searchElement) << endl;
			}
			else
			cout << "Element not found\n";
			break;
	    case 8:
		    s.display();
		    break;
		case 9:
		    s.removeElemnet(s.front());
			cout << "Front element removed." << endl;
			break;
		
		case 10:
			s.removeElemnet(s.back());
			cout << "Back element removed." << endl;
			break;

		case 11: 
			cout << "Enter elements for 2nd list: ";
			int ele;
			char ch;
			do{
				cin>> ele;
				s2.addToFront(ele);
				cout << "wanna enter more: Y|N";
				cin>> ch;
			}while(ch=='y'||ch=='Y');
			cout << "Entered list : ";
			s2.display();
			s.concat(s2);
			break;
		case 12: 
			cout << "Enter element to add: ";
			int el;
			cin >> el;
			cout << "After which element: ";
			int v;
			cin >> v;
			if(s.search(v)){
			s.add_with_el(el,v);
			cout << el << " element is added." << endl;
			}
			else 
			cout << v << " not found in list." << endl;
			break;
		case 13:
		    flag = true;
			break;
		default:
			cout << "You have choose wrong option.\n";
		//	flag = true;
		//	break;				
			
}
}
}//main
