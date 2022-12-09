

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
