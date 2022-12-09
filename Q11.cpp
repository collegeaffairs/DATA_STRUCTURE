// BST

#include<iostream>
using namespace std;

class node {
	public :
	int data;
	node* left;
	node* right;	
		node(){
			left=0;
			right=0;
		}
		node(int el){
			data = el;
			left = 0;
			right = 0;
		}
	
};

class Queue{
	
	private:
		int cp; //size
		int front;
		int rear;
		int n; // no of elements in queue.
		node** arr;
	public:
		Queue(int size){
			front = 0;
			rear =0;
			cp = size;
			arr = new node*[size];
			n = 0;
		}		
		void Enqueue(node* p){
			if(rear == cp){
				cout<<"Ovelflow" << endl;
				return;
			}else{
				arr[rear++] = p;
				n++;
			}
		}
		node* Dequeue(){
			if( isEmpty()){
				cout << "Underflow stack";
				return 0;
				
			}else{
				node* temp = froEle();
				front++;
				n--;
				return temp;
			}
		}
		bool isEmpty() const{
			return(front == rear);
		}
		
		int size() const{
			return n;
		}
		
		node* froEle() {
			if(isEmpty()){
			return 0;	
			}else{
				return arr[front];
			}
			
		}
		friend class BST;
};



class BST {
	
	public:
	node* root;
		BST() {
			root = 0;
		}
		
	void insert(int el){
		node* temp = new node(el);
		node* curr = root;
		node* prev = 0;
		
		while (curr){
			prev = curr;
			if(el <= curr->data){
			  curr = curr-> left;
			}else{
				curr = curr-> right;
			}
		}
		if(prev == 0){
			root = temp;
		}else if(el <= prev-> data){
			prev-> left = temp;
		}else{
			prev-> right = temp;
		}
	}
	node* search(int el){
		node* ptr = root;
		while(ptr){
			if(ptr->data == el){
				return ptr;
			}else if(ptr-> data < el){
				ptr = ptr->right;
			}else{
				ptr = ptr->left;
			}
		}
		return 0;
	}

	void replace(int el,int rep){
		node* temp = search(el);
		findAndDeleteByCopy(el);
		insert(el);
	}
	
	// delete by merge algo
	void deleteByMerge(node* &curr){
		node* temp = curr;
		if(temp !=0){
			if(curr->right== 0){
				curr = curr->left;
			}else if(curr->left == 0){
				curr = curr->right;
			}else{
				temp = curr->left;
				while(temp->right !=0){
					temp = temp->right;
				}
				temp->right = curr->right;
				temp = curr;
				curr = curr->left;
			}
			delete temp;
		}
	}
	// getting data and deleting by uisng merge function 
	void findAndDeleteByMerge(int el){
		node* curr = root;
		node* prev = 0;
		while(curr){
			if(curr->data = el){
				break;
			}
			prev = curr;
			if(curr->data < el){
				curr = curr->right;
			}else{
				curr = curr->left;
			}
		}
			if(curr !=0 && curr->data == el){
				if(curr == root){
					deleteByMerge(root);
				}else if(prev->left == curr){
					deleteByMerge(prev->left);
				}else{
					deleteByMerge(prev->right);
				}
			}else if(root){
				cout << "Element is not found\n";
			}else{
				cout << "Empty TREE\n";
			}
	}
	// delete by copy algo
	void deleteByCopy(node* &curr){
		node * prev;
		node* temp = curr;
		if(curr->right == 0){
			curr = curr->left;
		}else if(curr->left == 0){
			curr = curr->right;
		}else{
			temp= curr->left;
			prev = curr;
			while(temp->right !=0){
				prev = temp;
				temp = temp->right;
			}
			curr->data = temp->data;
			if(prev == curr){
				prev->left = temp->left;
			}else{
				prev->right = temp->left;
			}
		}
		delete temp;
	}
	
	// deleting by using copy function 
	void findAndDeleteByCopy(int el){
		node* curr = root;
		node* prev = 0;
		while(curr){
			if(curr->data == el){
				break;
			}
			prev = curr;
			if(curr->data < el){
				curr = curr->right;
			}else{
				curr = curr->left;
			}
		}
			if(curr !=0 && curr->data == el){
				if(curr == root){
					deleteByCopy(root);
				}else if(prev->left == curr){
					deleteByCopy(prev->left);
				}else{
					deleteByCopy(prev->right);
				}
			}else if(root){
				cout << "Element is not found\n";
			}else{
				cout << "Empty TREE\n";
			}
		}

	
//Traversal in BST : 1) Breadth first 2) Depth first
//	 traversal through Breadth first

	void breadthFirst(){
		Queue Q(count(root));
		node* p = root;
		if(p != 0){
			Q.Enqueue(p);
			while(!Q.isEmpty()){
				p = Q.Dequeue();
				visit(p);
				if(p->left){
					Q.Enqueue(p->left);
				}
				if(p->right){
					Q.Enqueue(p->right);
				}
			}
		}
	}
	void visit(node* temp){
		cout << temp->data << " ";
	}
	
	// depth first algo
	
	//inorder 
	// LVR
	void inorder(node* curr){
		if(curr){
		inorder(curr->left);
		visit(curr);
		inorder(curr->right);
		}
	}
	
	//pre oder
	//VLR
	void preorder(node* curr){
		if(curr){
			visit(curr);
			preorder(curr->left);
			preorder(curr->right);
		}
	}
	
	//post order
	// LRV
	void postorder(node* curr){
			if(curr){
			postorder(curr->left);
			postorder(curr->right);
			visit(curr);
		}
	}
	
	//count number of nodes in a tree

	int count(node* curr){
		if(curr==0){
			return 0;
		}
		else 
		return 1+count(curr->left)+ count(curr->right);
	}
	

	int height(node* curr){
	if(curr == 0){
		return 0;
	}else{
		int l = height(curr->left);
		int r = height(curr->right);
		if(l>r){
			return l + 1;
		}else{
			return r +1;
		}
	}
	
  }
};

 void menuOption(){
  cout << "1  Add node \n";
  cout << "2. Delete a node \n";
  cout << "3. search a node\n";
  cout << "4. Display nodes (depth first treversal)\n";
  cout << "5. Traversal by breadth first\n";
  cout << "6. Height of the tree\n";
  cout << "7. Replace element x with y\n";
  cout << "8. to exit\n";
 }

int main(){
	BST B;
	menuOption();
	bool flag = false;
	while(!flag){
		int select;
		cout<<"Make choice: " << endl;
	cin >> select;
	switch(select){
		case 1:
				cout << "Enter the value to add: " ;
				int val;
				cin >> val;
				B.insert(val);
				break;
		case 2:
				cout << "Enter the value to be deleted: ";
				int value;
				cin >> value;
				cout << "1.Delete by copy\n2.Delete by merge" << endl;
				int cho;
				cin>>cho;
				if(cho==1){
				B.findAndDeleteByCopy(value);
				cout << value << " deleted." << endl;
				}
				else if(cho==2){
				B.findAndDeleteByMerge(value);
				cout << value << " deleted." << endl;
				}
				else 
				cout << "Wrong choice" << endl;
				
				break;
		case 3:
				cout << "Enter element to be searched: ";
				int el;
				cin >> el;
				if(B.search(el))
					cout << el << " found" << endl;
				else
					cout << el << " not found" << endl;
				break;

		case 4:
				cout << "Display elements in: \n1.Preorder\n2.Postorder\n3.Inorder\n";
				int ch;
				cin >> ch;
				switch(ch){
					case 1: B.preorder(B.root);
							cout << endl;
							break;
					case 2: B.postorder(B.root);
							cout << endl;
							break;
					case 3: B.inorder(B.root);
							cout << endl;
							break;
				}
				break;
		case 5:
				cout << "elements level by level in BST: ";
				 B.breadthFirst();
				cout << endl;
				break;
		
		case 6:
				cout << "height of the tree is: " << B.height(B.root) << endl;
				break;
		case 7:
				cout << "Enter the element to be replaced: " ;
				int element;
				cin >> element;
				if(B.search(element))
				{
					cout << "enter new value: " ;
					int newVal;
					cin >> newVal;
					B.replace(element,newVal);
				}
				else
					cout << element << " doesn't exist in tree." << endl;
				break;
		case 8:
					cout << "Exited" << endl;
					flag = true;
					break;								
											
		default:
				cout << "You have enter wrong choice.\n";
				
						
}
}
return 0;
}
    



// Second Way to using SLT
// Binary Search Tree 


#include <iostream>
#include <queue>

using namespace std;

class node{
    public:
int data;
node* right;
node* left;



    node(){
        right=0;
        left=0;

    }

    node(int val){
    right=0;
    left=0;
    data= val;
    }
};


class BST{
public:
node *root;



    BST(){
    root=0;
    }

   //insert an element x
   node* helper(int key,node *cur){

       if(cur==0){
        return new node(key);
       }

       if(key < cur->data ){
        // go in left
      cur->left =  helper(key,cur->left);

       }else{
    cur->right=  helper(key,cur->right);
       }

return cur;


   }

   void insert(int val){
       if(root==0){
        root= new node(val);
        return;
       }

     root =  helper(val,root);

   }


   void deleteByMerge(int val){

  root= helperDeleteByMerge(root,val);

   }

   node *predInorder(node *curr){

   if(curr->right ==0){
    return curr;
   }
return predInorder(curr->right);

   }

   node* helperDeleteByMerge(node *cur,int key){

   if(cur==0){
    return cur;
   }

   if(key< cur->data){
    cur->left =  helperDeleteByMerge(cur->left,key);
    return cur;
   }else if(key > cur->data){
    cur->right =  helperDeleteByMerge(cur->right,key);
    return cur;
   }else{

   if(cur->left == 0){
    return cur->right;
   }else if(cur->right == 0){
   return cur->left;
   }


   node *pred = predInorder(cur->left);

   pred->right = cur->right;

 node *toreturn= cur->left;

   cur->right=0;
   cur->left=0;
   delete cur;
   cur=0;

return toreturn;


   }

     }

   void levelTraversal(){

   queue<node*> q;

   node *ptr = root;

   if(root !=0){
    q.push(ptr);
   }

   while(!q.empty()){


   ptr = q.front();

   cout<<"  "<<q.front()->data<<endl;
   q.pop();


   if(ptr->left !=0){
    q.push(ptr->left);
   }
   if(ptr->right !=0){
    q.push(ptr->right);
   }

   }

   }

   void inorder(node *cur){

   if(cur ==0){
    return;
   }
   inorder(cur->left);
   cout<<cur->data<<" , ";
   inorder(cur->right);

   }
   void postOrder(node *cur){

   if(cur ==0){
    return;
   }
   postOrder(cur->left);

   postOrder(cur->right);
    cout<<cur->data<<" , ";

   }
   void preOrder(node *cur){

   if(cur ==0){
    return;
   }
    cout<<cur->data<<" , ";
   preOrder(cur->left);
   preOrder(cur->right);

   }

   int getheight(){

   height(root);

   }

   int height(node *curr){

       if(curr==0){
        return 0;
       }
       if(curr->left ==0 & curr->right ==0){
        return 1;
       }

       int h = max(height(curr->left),height(curr->right));
       return 1+h;

   }

   void display(){
   inorder(root);
   cout<<endl;
   preOrder(root);
     cout<<endl;
   postOrder(root);
     cout<<endl;
       cout<<endl;

   }
};

void menu(){

cout<<"1. insert"<<endl;
cout<<"2. Level Traversal"<<endl;
cout<<"3. delete a node"<<endl;
cout<<"4. display tree in inorder , preorder , postorder"<<endl;
cout<<"5 . height"<<endl;
cout<<"0. Exit"<<endl;
cout<<"SELECT OPTION"<<endl;

}

int main()
{

    BST obj;
    int sel =100;

    while(sel !=0){
        menu();
        cin>>sel;

        switch(sel){

        case 1:{
            cout<<"enter the data to be inserted : ";
            int d;
            cin>>d;
            obj.insert(d);
        }
        break;

        case 2:{
        obj.levelTraversal();
        }
        break;
        case 3:{

        cout<<"enter a data to delete : ";
        int d;
        cin>>d;
        obj.deleteByMerge(d);

        }
        break;
        case 4:{
        obj.display();
        }
        break;
        case 5:{
        cout<<"height : "<<obj.getheight()<<endl;
        }

        case 0:sel =0;

        }


    }

    return 0;
}
