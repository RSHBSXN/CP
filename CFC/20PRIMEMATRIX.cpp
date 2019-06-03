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
#define MAXN 100100
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
vector<bool> Numbers(MAXN,true);
void build(){
    Numbers[0] = Numbers[1] = false;    
    for(int i = 2;i*i < MAXN;i++){
        if(Numbers[i]){
            for(int j=i*i;j<MAXN;j+=i){
                Numbers[j] = false; 
            }
        }
    }   
}
int countMoves(int num){
    int moves = 0;
    while(!Numbers[num]){
        moves++;
        num++;
    }
    return moves;
}
int main(){
    FASTIO;
    build();
    int n,m;
    cin >> n >> m;
    MATRIX MAT(n,vi(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> MAT[i][j];
    
    MATRIX MOVES(n,vi(m));
    int minRows = INT32_MAX;
    int minCols = INT32_MAX;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            MOVES[i][j] = countMoves(MAT[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        int rows = 0;
        for(int j=0;j<m;j++){
            rows += MOVES[i][j];
        }
        minRows = min(rows,minRows);
    }
    for(int i=0;i<m;i++){
        int cols = 0;
        for(int j=0;j<n;j++){
            cols += MOVES[j][i];
        }
        minCols = min(cols,minCols);
    }
    cout<<min(minRows,minCols)<<'\n';
       
}
