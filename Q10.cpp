//Q10.

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
        friend class dequeue;
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

class dequeue{
	DLL l;
	int n;
	public:
		dequeue(){
			n = 0;
		}

		void enqueueFront(int el){
			l.add_to_front(el);
			n++;
			cout << "Element enqueued" << endl;
		}

		void enqueueBack(int el){
			l.add_to_back(el);
			n++;
			cout << "Element enqueued" << endl;
		}
		void dequeueFront(){
			if(l.isempty()){
				cout << "Queue Underflow" << endl;
				return;
			}
			else{
			l.remove_front();
			n--;
			}
		}

		void dequeueBack(){
			if(l.isempty()){
				cout << "Queue Underflow" << endl;
				return;
			}
			else{
			l.remove_back();
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

        int backEl(){
			return l.back();
		}

		void display(){
			l.display();
		}

};

int main(){
	dequeue q;
	cout<<"Slect:\n";
	cout<<"1. Enqueue at front\n";
    cout<<"2. Enqueue at back\n";
    cout<<"3. Dequeue Front\n";
	cout<<"4. Dequeue Back\n";
	cout<<"5. Back element\n";
	cout<<"6. front element\n";
    cout<<"7. display\n";
	cout<<"8. Exit\n";
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
			q.enqueueFront(value);
			break;

        case 2:
			cout << "Enter item to add: ";
			int value;
			cin >> value;
			q.enqueueBack(value);
			break;
		case 3:
			q.dequeueFront();
			break;

        case 4:
			q.dequeueBack();
			break;
		case 5:
			if (q.isEmpty())
			cout << "Queue is empty" << endl;
			else
			cout << "Back Element: " <<q.backEl() << endl;
			break;

        case 6:
			if (q.isEmpty())
			cout << "Queue is empty" << endl;
			else
			cout << "Front Element: " <<q.frontEl() << endl;
			break;
		case 7:
			if(q.isEmpty())
				cout << "Empty Queue" << endl;
			else
				q.display();
			break;
		case 8:
			flag = true;
			break;
		default:
				cout << "Invalid Value";
                break;
							
	}
	
	}

}//main
