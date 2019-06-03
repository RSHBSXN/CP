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
#define MAX(N,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
MATRIX ADJLST;
vi COL;
//0 uncoloured 1 black 2 red
bool isBipartite(int vertex,int color){
    COL[vertex] = color;
    if(color == 1)
        color = 2;
    else
        color = 1;
    bool can = true;
    for(int i=0;i<ADJLST[vertex].size();++i){
        int adjc = ADJLST[vertex][i];
        if(!COL[adjc]){
            can = isBipartite(adjc,color);
        }
        if(COL[adjc] && COL[adjc] == COL[vertex] || !can)
            return false;
    }
    return true;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int N,E;
        cin >> N >> E;
        ADJLST = MATRIX(N+1);
        COL = vi(N+1,0);
        while(E--){
            int a,b;
            cin >> a >> b;
            ADJLST[b].push_back(a);
            ADJLST[a].push_back(b);
        }
        bool bipar = true;
        for(int i=1;i<=N;++i){
            if(!COL[i]){
                bipar = isBipartite(i,1);
            }
            if(bipar == false)
                break;
        }
        cout<<((bipar)?"yes":"no")<<'\n';
        ADJLST.clear();
        COL.clear();
    }
}
