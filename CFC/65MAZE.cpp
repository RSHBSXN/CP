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
#define PREC 1e-9
MATRIXC MAT;
MATRIXB VIS;
int rdir[4] = {1,-1,0,0};
int cdir[4] = {0,0,1,-1};
int n,m,k;
bool safe(int r,int c){
    return r >= 0 && r < MAT.size() && c >= 0 && c < MAT[0].size() && !VIS[r][c] && MAT[r][c] != '#' && MAT[r][c] != 'X';
}
void dfs(int r,int c,int &count){
    VIS[r][c] = true;
    if(count <= k)
        MAT[r][c] = 'X';
    for(int i=0;i<4;++i){
        int newR = r + rdir[i];
        int newC = c + cdir[i];
        if(safe(newR,newC)){
            dfs(newR,newC,--count);
        }
    }
}
int main(){
    FASTIO;
    cin >> n >> m >> k;
    MAT = MATRIXC(n,vector<char>(m));
    VIS = MATRIXB(n,vector<bool>(m));
    int count = 0;
    int row,col;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin >> MAT[i][j];
            if(MAT[i][j] == '.'){
                count++;
                row = i;col=j;
            }
        }
    }
    dfs(row,col,count);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)
            cout<<MAT[i][j];
        cout<<'\n';
    }
}
