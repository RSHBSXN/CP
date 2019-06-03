/*
    Author: Rishabh Saxena
    All the best!!
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define xll __int128
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define vi vector<int>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<ll>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
void shiftDown(vi &Heap,int index){
    while(index < Heap.size()){
        int left = index * 2;
        int right = left + 1;
        if(right < Heap.size()){
            if(max(Heap[left],Heap[right]) > Heap[index]){
                if(Heap[left] > Heap[right]){
                    swap(Heap[index],Heap[left]);
                    index = left;
                }
                else{
                    swap(Heap[index],Heap[right]);
                    index = right;
                }
            }
            else
                break;
        }
        else if(left < Heap.size() && Heap[left] > Heap[index]){
            swap(Heap[left],Heap[index]);
            index = left;
        }
        else
            break;
    }
}
void HeapInsert(vi &Heap,int num){
    Heap.push_back(num);
    int index = Heap.size()-1;
    while(index > 1){
        int par = index/2;
        if(Heap[par] < Heap[index]){
            swap(Heap[par],Heap[index]);
            index = par;
        }
        else{
            break;
        }
    }
}
void HeapDisp(vi &Heap){
    vi arr;
    for(int i=0;i<10;++i){
        arr.push_back(Heap[1]);
        swap(Heap[1],Heap[Heap.size()-1]);
        Heap.pop_back();
        shiftDown(Heap,1);
    }
    for(int i=0;i<10;++i){
        cout<<arr[i]<<' ';
        HeapInsert(Heap,arr[i]);
    }
    cout<<'\n';
}
int main(){
    int n;
    cin >> n;
    vi Heap(n+1);
    for(int i=1;i<=n;++i){
        cin >> Heap[i];
    }
    for(int i=(n/2);i>0;i--){
        shiftDown(Heap,i);
    }
    int m;
    cin >> m;
    while(m--){
        int type,num;
        cin >> type;
        if(type == 1){
            cin >> num;
            HeapInsert(Heap,num);
        }
        else if(type == 2){
            HeapDisp(Heap);
        }
        else if(type == 3){
            swap(Heap[Heap.size()-1],Heap[1]);
            Heap.pop_back();
            shiftDown(Heap,1);
        }
        // HeapDisp(Heap);
    }
}
