//Heap insert
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
void display(vector<int> &ARR){
    for(int x : ARR)
        cout<<x<<' ';
    cout<<'\n';
}
int main(){
    vector<int> Heap;
    while(true){
        int index = Heap.size();
        int num;
        cin >> num;
        if(num == -1)
            break;
        Heap.resize(Heap.size()+1);
        Heap[index] = num;
        HeapInsert(Heap,index);
        display(Heap);
    }

}
