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
int main(){
    int v,e;
    cin >> v >> e;
    MATRIX ADJMAT(v+1,vi(v+1));
    while(e--){
        int a,b;
        cin >> a >> b;
        ADJMAT[a][b] = 1;
        ADJMAT[b][a] = 1;
    } 
    int vertex = 1;
    for(vertex = 1;vertex <= v; vertex++){
        bool possCand = true;
        for(int j=1;j<=v;++j){
            if(ADJMAT[vertex][j]){
                possCand = false;
                break;
            }
        }
        if(possCand)
            break;
    }
    cout<<v-1<<'\n';
    for(int i=1;i<=v;++i){
        if(i != vertex)
            cout<<vertex<<' '<<i<<'\n';
    }
}
