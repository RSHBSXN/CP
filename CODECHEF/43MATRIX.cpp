/*
    Author: Rishabh Saxena
    All the best!!
*/
#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
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
void buildPrfx(MATRIXC &MAT,MATRIX &PRFX,int N, int M){
    for(int i=N-1;i>=0;--i){
        for(int j=0;j<M;++j){
            if(MAT[i][j] == '1'){
                PRFX[i][j] += 1;
                if(i > 0)
                    PRFX[i-1][j] += PRFX[i][j];
            }
            else
                PRFX[i][j] = 0;
        }
    }
}
int main(){
    int N,M;
    cin >> N >> M;
    MATRIXC MAT(N,vector<char>(M));
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j)
            cin >> MAT[i][j];
    }
    MATRIX PRFX(N,vi(M,0));
    MATRIX DP(N,vi(M,0));
    buildPrfx(MAT,PRFX,N,M);
    ll count = 0;
    int prevSize = 0;
    for(int i=0;i<N;i++){
        if(MAT[i][0] == '1')
            DP[i][0] = 1;
    }
    for(int j=0;j<M;++j){
        if(MAT[N-1][j] == '1')
            DP[N-1][j] = 1;
    }
    for(int i=0;i<N-1;++i){
        if(MAT[i][0] == '1')
            prevSize = 1;
        for(int j=1;j<M;++j){
            if(MAT[i][j] == '1'){
                if(PRFX[i][j] > prevSize){
                    DP[i][j] = DP[i][j-1] + 1;
                    prevSize++;
                }
                else{
                    DP[i][j] = PRFX[i][j];
                    prevSize = PRFX[i][j];
                }
            }
            else{
                prevSize = 0;
            }
        }
        prevSize = 0;
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            count += DP[i][j];
        }
    }
    cout<<count<<'\n';
}