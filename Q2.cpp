// Created by Ayush Jha 
// Here assumed, this ascending order list is given  
// int arr[5] = {23, 31, 45, 55, 67}; 

#include <iostream>
using namespace std;

int binarySearch(int *arr, int key, int l=0, int r=4){
    
    int mid = l+(r-l)/2;   // for the mid value
    if(arr[mid] == key){
        return mid;
    }
    if(arr[mid] < key){
        return binarySearch(arr, key, mid+1, r);
    }
    if(arr[mid] > key){
        return binarySearch(arr, key, l, mid-1);
    }
    return -1;
}
int main(){
// assumed this ascending order list is given  
int arr[5] = {23, 31, 45, 55, 67};
int n;
cout << "enter seach: ";
cin >> n;

cout <<"The array, we have: " ;
for(int i=0; i<5; i++){
    cout << arr[i] << " ";
}
cout << endl;

cout << "Index position: ";
cout<<binarySearch( arr, n) << endl;

    return 0;
    
}