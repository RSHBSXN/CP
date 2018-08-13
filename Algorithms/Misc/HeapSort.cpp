//HeapSort
#include <iostream>
#include <vector>
using namespace std;
void swap(int &A,int &B){
    int temp = A;
    A = B;
    B = temp;
}
void HeapInsert(vector<int> &Heap,int index){
    int parent = (index - 1) / 2;
    if(index == 0 || Heap[parent] >= Heap[index])
        return;
    else{
        swap(Heap[index],Heap[parent]);
        HeapInsert(Heap,parent);
    }
}
void heapify(vector<int> &ARR,int root){
    int left = root * 2 + 1;
    int right = left + 1;
    if(left >= ARR.size()){
        return;
    }
    else{
        heapify(ARR,left);
        heapify(ARR,right);
        int max = left;
        if(right < ARR.size())
            max = (ARR[right] > ARR[left])?right:left;
        if(ARR[max] > ARR[root])
            swap(ARR[max],ARR[root]);
    }
}
int DelHeap(vector<int> &Heap){
    int num = Heap[0];
    swap(Heap[0],Heap[Heap.size()-1]);
    Heap.pop_back();
    heapify(Heap,0);   
    return num;
}
void display(vector<int> &ARR){
    for(int x : ARR)
        cout<<x<<' ';
    cout<<'\n';
}
void heapSort(vector<int> &ARR){
    vector<int> Heap;
    for(int &x : ARR){
        int index = Heap.size();
        Heap.resize(Heap.size()+1);
        Heap[index] = x;
        HeapInsert(Heap,index);
    }
    for(int &i : ARR)
        i = DelHeap(Heap);   
}
int main(){
    int N;
    cin >> N;
    vector<int> ARR(N);
    for(int &x : ARR)
        cin >> x; 
    heapSort(ARR);
    display(ARR);
}
