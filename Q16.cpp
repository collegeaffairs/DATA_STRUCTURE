#include <iostream>
#include <string>
#include <cmath>

#include <math.h>

using namespace std;

class stack{
    public:
    int top;
    int size;
    int *arr;
    int capacity;

public:
    stack(int length){
        if(length <0){
               cout<<"wrong"<<endl;

        }else{
        capacity= length;
        arr = new int[length];
        top= -1;
        size=0;
        }

    }

   void push(int data){
       if(top>= capacity-1){
        cout<<"overflow"<<endl;
        return;
       }
       arr[++top]= data;
       size++;
    }
    void pop(){
    if(isempty()){
        cout<<"underflow"<<endl;
        return;
    }
    else{
        //cout<<"popped"<<endl;
        --top;
        size--;
    }
    }

   int isempty() {
   return (top== -1);

   }


   int sizex(){
   return size;
   }

   int topEl(){
       if(isempty()){
            cout<<"stack is empty this function is not possible"<<endl;
        return -1;
       }
       return arr[top];
   }

   void clear(){
   top = -1;
   size=0;
   return;
   }

   void multiPush(int no_of_datas, int *values){
       if(capacity-1 < top+ no_of_datas){
            cout<<"stack cannot hold that much of datas"<<endl;
        return;
       }

       int i=0;
       while(i != no_of_datas){
        push(values[i++]);
       }
       return;
   }

   void multiPop(int n){
        int i=0;
        if(n <= size){
             while(i != n){
        pop();
        i++;
       }
       cout <<"this many "<< n <<" elements has been pop out from stack"<< endl;
      }
       return;
   }
   void print(){
       for(int i=0;i<size;++i){
       cout<<i<<" : " <<arr[i]<<endl;
       }
       
   }


};

int function(string str){

    stack opstk(str.length());

    int i=0;
    
     string strr ="";
     int count=0;
     char pre;
     

    while(i != (int)str.length()){
            char symb = str.at(i++);
            int symbInt =(int)symb;
           
          
            if(symbInt != 94 && symbInt != 32 && (symbInt < 37 || symbInt >47)){
              
               strr +=""+ to_string(symbInt-48);
                count++;
                pre=0;
                
            }else{
                if(symbInt==32){
                  
                      opstk.push(stoi(strr));
                      strr="";
                      pre=0;
                }else if((pre>=37 && pre <=47) || pre==94){
                        //symbol is operand so push it

        int opnd2 = opstk.topEl();
        opstk.pop();

        int opnd1 = opstk.topEl();
        opstk.pop();
        int ans=0;
        switch(symb){

        case '+':ans = opnd2+opnd1;
        opstk.push(ans);
        break;
        case '-': ans = opnd1 - opnd2;
        opstk.push(ans);
        break;
        case '*': ans = opnd1* opnd2;
         opstk.push(ans);
        break;
        case '/': ans = opnd1/opnd2;
         opstk.push(ans);
        break;
         case '^': ans = pow(opnd1,opnd2);
         opstk.push(ans);
        break;

        default:cout<<"error";

        }
        cout<<"ans : ";
        opstk.print();
        
                }else{
                     opstk.push(stoi(strr));
                         pre = symb;
                         strr="";
                     i--;
                
                }   
            }
       
    }
  int ret = opstk.topEl();
        opstk.pop();
        return ret;
    }
   
int main()
{
    string str = "160 20 30+-30 80 20/++2^30+";  
    cout<<function(str);
    return 0;
}
