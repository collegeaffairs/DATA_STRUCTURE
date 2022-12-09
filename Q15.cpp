
//Using STL of queue. 
#include<iostream>
#include<queue>
using namespace std;

void printMaxHeap(priority_queue<int> maxHeap){
    
    while(!maxHeap.empty()){
        cout << "\t" << maxHeap.top();
        maxHeap.pop();
    }
    cout << "\n";
}

void printMinHeap(priority_queue<int, vector<int>, greater<int> > minHeap){
    
    while(!minHeap.empty()){
        cout << "\t" << minHeap.top();
        minHeap.pop();
    }
    cout << "\n";
}


int main(){
    
// max heap priority queue.

    priority_queue<int> pq;

    pq.push(14);
    pq.push(5);
    pq.push(49);
    pq.push(9);
    pq.push(19);
    pq.push(13);

    cout << "Element at the top " << pq.top() << endl;
    pq.pop();
    cout << "Element at the top " << pq.top() << endl;


    // min heap priority queue.

    priority_queue<int, vector<int>, greater<int> > minHeap;
    minHeap.push(4);
    minHeap.push(5);
    minHeap.push(56);
    minHeap.push(6);
    minHeap.push(16);
    minHeap.push(2);
    minHeap.push(10);

    cout << "Element at the top " << minHeap.top() << endl;
    minHeap.pop();
    cout << "Element at the top " << minHeap.top() << endl;

    cout << "Priority Queue with max heap : ";
    printMaxHeap(pq);
    cout << "Priority Queue with min heap : ";
    printMinHeap(minHeap);

}
