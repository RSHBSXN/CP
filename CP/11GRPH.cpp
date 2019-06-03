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
void dfs(const list<int> ADJLST[],int index,bool VIS[]){
    if(!VIS[index]){
        VIS[index] = true;
        cout<<index<<' ';
        for(auto x = ADJLST[index].begin();x != ADJLST[index].end();x++){
            if(!VIS[*x])
                dfs(ADJLST,*x,VIS);
        }
        return;
    }
    return;
}
void func(const vector<int> &X){
    X[0] = 5;
}
int main(){
    int N;
    cin >> N;
    list<int> ADJLST[N];
    int edges;
    cin >> edges;
    bool VIS[N];
    memset(VIS,0,N);
    for(int i=0;i<edges;++i){
        int a,b;
        cin >> a >> b;
        ADJLST[a].push_back(b);
        ADJLST[b].push_back(a);
    }
    for(int i=0;i<N;++i){
        if(!VIS[i])
            dfs(ADJLST,i,VIS);
    }
}
