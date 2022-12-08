// Q3 practical list 
//signal linked list

#include<iostream>
using namespace std;


class node{
	
	int data;
	node* next;
	friend class SLL;
	public:
		node(int val, node*ptr=0){
			data=val;
			next=ptr;
		}
		
};
class SLL{
	node* head;
	public:
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

void remove_at_i(int i){
	node* prev = head;
	node* ptr = head;
	int count = 0;
	while(count != i){
		count++;
		ptr = ptr->next;
	}
	while(prev->next != ptr){
		prev= prev->next;
	}
	prev->next = ptr->next; 
	delete ptr;
}
node* search(int val){
	node* ptr = head;
	while(ptr){
	if(ptr->data == val){
		return ptr;
	}
	ptr = ptr->next;
	}
    return 0;
}

void insert_after(int val, node* ptr){
	ptr->next = new node(val, ptr->next);
//node* temp = new node(val);
//temp->next = ptr->next;
//ptr->next = temp;
}

int insert_at_i(int i){

	node* ptr = head;
	int count = 0;
	while(count != i){
		count++;
		ptr = ptr->next;
	}
	return ptr->data;
}


int countNodes(){
	int count =0;
	node* ptr = head;
	while (ptr){
		count++;
		ptr=ptr->next;
	}
	return count;
}
void insert_data(int val, int el){

	if(search(el)){
		node* temp = search(el);
		if(temp){
			insert_after(val, temp);
		}
		else{
			insert_after(val, head);
		}
	}else{
		cout<<"Element not found\n";
	}	
}
void insert_at_end(int val){
	if(head){
		node* ptr = head;
		while(ptr->next != 0){
			ptr = ptr->next;
		}
		ptr->next = new node(val); 
	}else{
		add_to_head(val);
	}
}
void concat(SLL s){
	cout << "Inside concat " << endl;
	node* ptr = this->head;
	while(ptr->next!=0){
		ptr= ptr->next;
	}
	ptr->next=s.head;
	s.head =0;
	//return this;
}

};
int main(){
	SLL s;
	SLL s1;	
	cout<<"Slect:\n";
	cout<<"1. -> add to head\n";
	cout<<"2. -> add data with element\n";
	cout<<"3. -> add data at ith position\n";
	cout<<"4. -> remove from begining\n";
	cout<<"5. -> display items\n";
	cout<<"6. -> search item\n";
	cout<<"7. -> add data at end\n";
	cout<<"8. -> remove item from ith position\n";	
	cout<<"9. -> concatenate lists\n";	
		
	
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
			s.add_to_head(value);
			break;
		case 2:
			cout<<"Enter data after you want to enter: ";
			int el;
			cin >> el;
			cout << "Enter item to add: ";
			int val;
			cin >> val;
			s.insert_data(val, el);
			break;
			
		case 3:
			cout << "Indexes start from 0,1,2....";
			cout << "Enter the ith position: ";
			int i;
			cin >> i;
			if (i > s.countNodes())
			 cout << "invalid index: ";
			else{	
			cout << "Enter the item to add: ";
			int item;
			cin >> item;
			s.insert_data(item,s.insert_at_i(i-1));
			}
			break;
				
		case 4:
			cout<< "Removed "<<	s.remove_from_begining()<<endl;
			break;
		case 5:
				s.display();
				break;
				
		case 6:
				cout << "Enter item you want to search: ";
				int ite;
				cin >> ite;
				cout <<s.search(ite);
				break;
		case 7:
				cout << "Enter item you want to add at end: ";
				int abc;
				cin >> abc;
				 s.insert_at_end(abc);
				cout << "Item addeed" << endl;
				break;
		case 8: 
				cout << "Indexes start from 0,1,2....";
				cout << "Enter the ith position to remove: ";
				int pos;
				cin >> pos;
				if (pos > s.countNodes()){
					 cout << "invalid index: ";
				}
		    	else{
				s.remove_at_i(pos);
				cout << "Element removed.\n";
			    }
			    break;
		case 9: 
			int ele;
			char ch;
			do{
			cout << "Enter element: ";
			cin >> ele;
			s1.add_to_head(ele);
			cout << "Wanna enter more elements: Y | N ";
			cin >> ch;
			}while(ch=='Y'||ch=='y');
			cout << "Entered list:  ";
			s1.display();
			cout << "/nList after concatination: ";
			s.concat(s1);
			break;
		default:
				flag = true;
				break;
				
			
}
}
return 0;
}



