/*
    Author: Rishabh Saxena
    All the best!!
*/
#include <bits/stdc++.h>
#include <vector>
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
MATRIX ADJLST;
vector<ll> VAL;
ll N,X;
ll dfs(int parent,int index){
    ll Sum = VAL[index];
    for(int i=0;i<ADJLST[index].size();++i){
        int adjc = ADJLST[index][i];
        if(adjc != parent){
            Sum += dfs(index,adjc);
        }
    }
    return max(Sum,-X);
}

int main(){
    FASTIO;
    int t;
    cin >> t;
    while(t--){
        cin >> N >> X;
        ADJLST = MATRIX(N);
        VAL = vector<ll>(N);
        for(int i=0;i<N;++i)
            cin >> VAL[i];
        for(int i=1;i<N;++i){
            int a,b;
            cin >> a >> b;
            --a,--b;
            ADJLST[a].push_back(b);
            ADJLST[b].push_back(a);
        }
        cout<<dfs(-1,0)<<'\n';
        ADJLST.clear();
    }
}
