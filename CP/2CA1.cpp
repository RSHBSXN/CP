/*
    Author: Rishabh Saxena
    All the best!!
*/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define XLL __int128
#define pii pair<int,int>
#define pll pair<LL,LL>
#define vi vector<int>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<LL>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
struct bitrep{
    int bitCount,number;
    bitrep(){}
    bitrep(int number){
        this->number = number;
        bitCount = 0;
        for(int i=0;i<32;++i){
            if((number & (1 << i)) != 0){
                bitCount++;
            }
        }
    }
};
vector<bitrep> ARR;
bool compare(bitrep A,bitrep B){
    if(A.bitCount > B.bitCount)
        return true;
    else if(A.bitCount == B.bitCount && A.number >= B.number){
        return true;
    }
    else
        return false;
}
void heapInsert(vector<bitrep>&HEAP,int i){
    int par = i/2;
    while(i > 1 && compare(HEAP[i],HEAP[par])){
        swap(HEAP[i],HEAP[par]);
        i = par;
        par = i/2;
    }
}
int main(){
    int N;
    cin >> N;
    ARR.resize(N);
    for(int i=0;i<N;++i){
        int num;
        cin >> num;
        ARR[i] = bitrep(num);
    }
    vector<bitrep> HEAP(1);
    for(int i=0;i<N;++i){
        HEAP.push_back(ARR[i]);
        heapInsert(HEAP,HEAP.size()-1);   
    }
    int q;
    cin >> q;
    while(q--){
        int id;
        cin >> id;
        switch(id){
            case 1:
                int num;
                cin >> num;
                HEAP.push_back(bitrep(num));
                heapInsert(HEAP,HEAP.size()-1);
                break;
            case 2:
                if(HEAP.size() == 1)
                    cout<<-1;
                else
                    cout<<HEAP[1].number<<'\n';
        }
    }
    
}
