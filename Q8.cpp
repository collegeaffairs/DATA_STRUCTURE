/*
Q8 practical list 
Display a circular queue with using template by using an array.
*/

#include<iostream>
using namespace std;

template < typename E >
class Queue{
	
	private:
		int cp; //size
		int front;
		int rear;
		int n; // no of elements in queue.
		E* arr;
	public:
		Queue(int size){
			front = 0;
			rear =0;
			cp = size;
			arr = new E[size];
			n = 0;
		}		
		void Enqueue(E item){
			if(n == cp){
				cout<<"Ovelflow" << endl;
				return;
			}else{
				arr[rear] = item;
				rear=(rear+1)%cp;
				n++;
			}
		}
		
		void Dequeue(){
			if( isEmpty()){
				cout << "Underflow queue";
				return;
				
			}else{
				front=(front+1)%cp;
				n--;
			}
		}
		bool isEmpty(){
			return(n==0);
		}
		
		int size() const{
			return n;
		}
		
		E froEle() {
			if(isEmpty()){
			return -1;	
			}else{
				return arr[front];
			}
			
		}
		
};
	
	int main(){

	cout<<"Enter the size of array: ";
	int n;
	cin >> n;
	Queue <char>s1(n);
	cout<<"Slect:\n";
	cout<<"1. to add\n";
	cout<<"2. to delete\n";
	cout<<"3. to isEmpty\n";
	cout<<"4. to front element\n";
	cout<<"5. to Exit\n";
	bool flag = false;
	while(!flag){
		int select;
		cout<<"Make choice: " << endl;
	cin >> select;
	switch(select){
		case 1:
			cout << "Enter item to add: ";
			char value;
			cin >> value;
			s1.Enqueue(value);
			break;
		case 2:
			s1.Dequeue();
			break;
		case 3:
			//cout << "Stack is empty: "<< (bool)s1.isEmpty() << endl;
			
			if (s1.isEmpty())
			cout << "Queue is empty" << endl;
			else
			cout << "Queue is not empty" << endl;
			break;
		case 4:
			cout << "Front is "<<s1.froEle() << endl;
			break;
		case 5:
			flag = true;
			break;
		default:
				cout << "Invalid Value";
							
	}
	
	}

}
