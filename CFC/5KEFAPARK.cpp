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
#define vb vector<bool>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<LL>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
MATRIX ADJLST;
vb VIS;
vi Cats;
int dfs(int ind,int cats,int m){
    VIS[ind] = true;
    int count = 0;
    bool leaf = true;
    for(int i=0;i<ADJLST[ind].size();i++){
        int adjc = ADJLST[ind][i];
        if(!VIS[adjc]){
            leaf = false;
            if(!Cats[adjc])
                count += dfs(adjc,0,m);
            else if(Cats[adjc] + cats <= m){
                count += dfs(adjc,cats + 1,m);
            }
        }
    }
    if(leaf){
        return 1;
    }
    else
        return count;
}
int main(){
    FASTIO;
    int n,m;
    cin >> n >> m;
    Cats.resize(n);
    ADJLST.resize(n);
    
    VIS.resize(n,false);
    for(int i=0;i<n;i++)
        cin >> Cats[i];
    for(int i=1;i<n;i++){
        int x,y;
        cin >> x >> y;
        x--,y--;
        ADJLST[x].push_back(y);
        ADJLST[y].push_back(x);
    }
    cout<<dfs(0,Cats[0],m)<<'\n';
}
