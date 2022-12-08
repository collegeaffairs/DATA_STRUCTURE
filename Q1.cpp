// Created by Ayush Jha
// Here assumed this list is given 
// int arr[5] = {23, 314, 45, 55, 67}; 

#include<iostream>
using namespace std;

int linearSearch(int *arr, int x){
    for(int i=0; i <5; i++){
        if(arr[i] == x)
            return i;
        
    }
    return -1;
}
int main(){
// assumed this list is given 
int arr[5] = {23, 314, 45, 55, 67};
int n;
cout << "enter seach: ";
cin >> n;

cout <<"The array, we have: " ;
for(int i=0; i<5; i++){
    cout << arr[i] << " ";
}
cout << endl;

cout<<"Index position: ";
cout<<linearSearch( arr, n) << endl;

    return 0;
    
}