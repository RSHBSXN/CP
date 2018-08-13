#include <iostream>
#include <vector>
using namespace std;
void swap(int &A,int &B){
    int temp = A;
    A = B;
    B = temp;
}
void makeHeap(vector<int> &ARR,int root){
    int left = root * 2 + 1;
    int right = left + 1;
    if(left >= ARR.size()){
        return;
    }
    else{
        makeHeap(ARR,left);
        makeHeap(ARR,right);
        int max = left;
        if(right < ARR.size())
            max = (ARR[right] > ARR[left])?right:left;
        if(ARR[max] > ARR[root])
            swap(ARR[max],ARR[root]);
    }
}
void display(vector<int> ARR){
    for(int x : ARR)
        cout<<x<<' ';
    cout<<'\n';
}
int main(){
    int N;
    cin >> N;
    vector<int> ARR(N);
    for(int &x : ARR)
        cin >> x;
    display(ARR);
    makeHeap(ARR,0);
    display(ARR);
}
