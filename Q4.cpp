//Doubly linked list

#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node* next;
	node* prev;
	
		node(){
			next=0;
			prev=0;
		}
		node(int val,node*ptr=0,node* ptr1=0){
			data=val;
			next=ptr1;
			prev=ptr;
		}	
		friend class DLL;
};

class DLL{
	node* header;
	node* trailer;
	public:
		DLL(){
			header=new node();
			trailer=new node();
			header->next=trailer;
			trailer->prev=header;
		}
	
	bool isempty(){
		return(header->next==trailer);
	}
	
	void display(){
		node* ptr= header->next;
		while(ptr!=trailer){
			cout << ptr->data << " ";
			ptr=ptr->next;
		}
		return;
	}
	
	node* find_index_i(int i){

		node* ptr = header;
		int count = 0;
		while(count != i){
			count++;
			ptr = ptr->next;
		}
		return ptr->next;
	}
	void add(node* v,int val){
		node* temp;
		temp= new node(val);
		temp->next=v;
		temp->prev=v->prev;
		v->prev->next=temp;
		v->prev=temp;
	}
	
	int front(){
		return(header->next->data);
	}
	
	int back(){
		return(trailer->prev->data);
	}
	
	void add_to_front(int val){
		add(header->next,val);
	}
	
	void add_to_back(int val){
		add(trailer,val);
	}
	
	node* search(int val){
		node* ptr=header;
		while(ptr!=trailer){
			if(ptr->data==val)
			  return ptr;
			ptr=ptr->next;
		}
		return 0;
	}	

	void remove(node* v){
		node* u= v->prev;
		node* w= v->next;

		u->next=w;
		w->prev=u;
		delete v;
	}

	void remove_front(){
		if(!isempty())
			remove(header->next);
	}

	void remove_back(){
		if(!isempty())
			remove(trailer->prev);
	}

	void remove_el(int el){
		if(!isempty()){
			node* ptr= search(el);
			if(ptr)
				remove(ptr);
		}
	}

	void remove_at_i(int i){
		if(!isempty())
			remove(find_index_i(i-1));
	}

	int countNodes(){
	int count =0;
	node* ptr = header;
	while (ptr){
		count++;
		ptr=ptr->next;
	}
	return count;
	}
};


int main(){
	DLL l;
	cout << "menu: " << endl;
	cout << "1.  add to head\n";
	cout << "2.  add to back\n";
	cout << "3.  search an element\n";
	cout << "4.  front element\n";
	cout << "5.  end element\n";
	cout << "6.  Display list\n";
	cout << "7.  add at ith position\n";
	cout << "8.  remove from ith position\n";
	cout << "9.  remove from beginning\n";
	cout << "10. remove from back\n";
	cout << "11. exit\n";

	bool flag = true;
	
	while(flag){
		cout << "Enter your choice: ";
	    int ch;
	    cin >> ch;
	    
	  switch(ch){
	  	case 1: cout << "Enter the element to add: ";
	  	        int el;
	  	        cin >> el;
	  	        l.add_to_front(el);
	  	        break;
	  	
		case 2: cout << "Enter the element to add: ";
	  	        int el1;
	  	        cin >> el1;
				l.add_to_back(el1);
	  	        break;
		
		case 3: cout << "Enter the element to search: ";
	  	        int el2;
	  	        cin >> el2;
	  	        if (l.search(el2))
				  cout << el2 << " found\n" ;			
	  	        else
	  	        cout << el2 << " not found\n" ;
	  	        break; 
				  
		case 4:  if (!l.isempty())
	  	        cout << l.front() << endl;
	  	        else
	  	        cout << "List is empty\n";
	  	        break;
				 
		case 5:  if (!l.isempty())
	  	        cout << l.back() << endl;
	  	        else
	  	        cout << "List is empty\n";
	  	        break;
	  	        
	  	case 6: l.display();
		         break;

		case 7: 
			cout << "Enter the ith position: "<< endl;
			int i;
			cin >> i;
			if (i > l.countNodes())
			 cout << "invalid index: ";
			else{	
			cout << "Enter the item to add: ";
			int item;
			cin >> item;
			l.add(l.find_index_i(i-1),item);
			}
			break;
				  
		case 8: 
				cout << "Enter the ith position to remove: ";
				int pos;
				cin >> pos;
				if (pos > l.countNodes()){
					 cout << "invalid index: " << endl;
				}
		    	else{
				l.remove_at_i(pos);
				cout << "Element removed.\n";
			    }
			    break;

		case 10: 
				l.remove_back();
				cout << "Back element removed. " << endl;
				break;
		case 9: 
				l.remove_front();
				cout << "Front element removed. " << endl;
				break;

		case 11: flag = false;
		         break;
 
		default: cout << "Invalid choice";
		         break;	  	
	  }
	}
	return 0;
}
