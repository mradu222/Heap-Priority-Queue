#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size = 0;

    heap( ){
        arr[0] = -1;
        size = 0;

    }

    void insert(int val){
        size = size +1;
        int index = size;
        arr[index] = val;
        
        while(index>1){
            int parent = index/2;
             
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
                
            }
            else {
                return;
            }

        }
        
    }
    void print(){
        for(int i = 1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;

    }
    void deleteFromHeap(){
        if(size == 0){
            cout<<"Nothing to delete"<<endl;
            return;
        }
        //Step1: put last indext to first index
        arr[1] = arr[size];

        //step-2 remove last index
        size--;

        //step-3 put root node to its correct position
        int i = 1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex <size && arr[i] < arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex<size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
        }
    }

};

//heapify function
void heapify(int arr[], int size, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left<=size && arr[largest]<arr[left]){
        largest = left;
    }
    if(right<=size && arr[largest]< arr[right]){
        largest = right;
    }
    if(largest != i){//matlab ki largest ki position change hui hai to usko uski shi position par swap krdenge
        swap(arr[largest],arr[i]);
        heapify(arr,size, largest);//neeche jake bhi check krlo or koi shi position to nahi hai
    }
}
//min heapify
void minHeapify(int arr[], int size, int i){
    int smallest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left<=size && arr[smallest]>arr[left]){
        smallest = left;
    }
    if(right<=size && arr[smallest]> arr[right]){
        smallest = right;
    }
    if(smallest != i){//matlab ki largest ki position change hui hai to usko uski shi position par swap krdenge
        swap(arr[smallest],arr[i]);
        minHeapify(arr,size, smallest);//neeche jake bhi check krlo or koi shi position to nahi hai
    }
}

void heapSort(int arr[], int n){
    int size = n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;

        heapify(arr,size,1);
    }
}

int main(){
    heap h;
    h.insert(50);
    h.insert(51);
    h.insert(52);
    h.insert(60);
    h.insert(53);
    h.print();
    h.deleteFromHeap();
    h.print();
    int arr[6] = {-1,65,53,55,52,50};
    int n =5;
    for(int i = n/2; i> 0;i--){
        heapify(arr,n,i);
    }
    cout<<"Printing the array of max heap: "<<endl;
    for(int i = 1; i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    for(int i = n/2; i> 0;i--){
        minHeapify(arr,n,i);
    }

    cout<<"Printing the array of min heap: "<<endl;
    for(int i = 1; i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    heapSort(arr,n);
    cout<<"Printing the array after heap sort: "<<endl;
    for(int i = 1; i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

}
