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
#define vi vector<int>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<ll>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
struct oper{
    int type,color,prio,ind;
    oper(){
        color = -1;
        prio = INT32_MAX;
    }
};
void Fill(MATRIX &MAT,int color,int ind,int size,bool isRow){
    for(int i=0;i<size;++i){
        if(isRow)
            MAT[ind][i] = color;
        else
            MAT[i][ind] = color;
    }
}
int main(){
    FASTIO;
    int n,m,k;
    cin >> n >> m >> k;
    unordered_map<int,oper> rows,cols;
    map<int,oper> seq;
    int prior = 1;
    while(k--){
        int type,number,color;
        cin >> type >> number >> color;
        number--;
        unordered_map<int,oper> *ref = NULL;
        if(type == 1)
            ref = &rows;
        else
            ref = &cols;
        (*ref)[number].color = color;
        (*ref)[number].ind = number;
        (*ref)[number].prio = prior++;
        (*ref)[number].type = type;
    }
    for(auto x : rows){
        seq[x.second.prio] = x.second;
    }
    for(auto x : cols){
        seq[x.second.prio] = x.second;
    }
    MATRIX MAT(n,vi(m));
    for(auto x : seq){
        if(x.second.type == 1)
            Fill(MAT,x.second.color,x.second.ind,m,true);
        else
            Fill(MAT,x.second.color,x.second.ind,n,false);
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cout<<MAT[i][j]<<' ';
        }
        cout<<'\n';
    }
    
}
