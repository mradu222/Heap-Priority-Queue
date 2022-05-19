#include<iostream>
#include<queue>
using namespace std;
int main(){
    //max Heap
    priority_queue<int> pq;
    pq.push(5);
    pq.push(8);
    pq.push(6);
    pq.push(2);
    cout<<"Element at top is: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Element at top is: "<<pq.top()<<endl;
    cout<<"size is: "<<pq.size()<<endl;
    if(pq.empty()){
        cout<<"Queue is empty";
    }
    else{
        cout<<"Not Empty";
    }

    //min Heap
    priority_queue<int,vector<int>,greater<int>> minHeap;
    minHeap.push(5);
    minHeap.push(8);
    minHeap.push(6);
    minHeap.push(2);
    cout<<"Element at top is: "<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<"Element at top is: "<<minHeap.top()<<endl;
    cout<<"size is: "<<minHeap.size()<<endl;
    if(minHeap.empty()){
        cout<<"Queue is empty";
    }
    else{
        cout<<"Not Empty";
    }

}