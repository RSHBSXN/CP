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
vector<vector<pii>> ADJLST;
vector<pair<int,int>> VIS;
int DFS(int a,int b){
    VIS[a].first = 1;
    if(a == b){
        VIS[a].first = 2;
        VIS[a].second = 0;
    }
    int MIN = INT32_MAX;
    for(int i=0;i<ADJLST.size();++i){
        pii adjc = ADJLST[a][i];
        int curr = adjc.second;
        if(VIS[adjc.first].first == 2){
            MIN = min(MIN,VIS[adjc.first].second);
        }
        else if(VIS[adjc.first] == 0){
            curr
        }
    }
}
int main(){
    int N,M;
    cin >> N >> M;
    int dest = INT32_MIN;
    ADJLST = vector<vector<pii>> (N+1);
    VIS = vector<bool>(N+1,false);
    for(int i=0;i<M;++i){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        ADJLST[a].push_back({b,c});
        ADJLST[b].push_back({a,c});
        if(d == 1)
            dest = max(a,dest);
    }
    int src;
    cin >> src;
    pii res =  DFS(src,dest);
    if(res.second)
        cout<<res.first;
    else
        cout<<-1;
}
