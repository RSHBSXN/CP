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
void buildPrfxArr(MATRIX &PRFX,MATRIXC &MAT,int N,int M){
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            if(MAT[i][j] == '1'){
                PRFX[i][j] = 1;
            }
            if(j > 0)
                PRFX[i][j] += PRFX[i][j-1];
        }
    }
}
int cut(MATRIX &PRFX,int i,int j,int R){
    if(i == -1 || j == -1)
        return 0;
    else{
        int ones = PRFX[i][R];
        if(j > 0)       
            ones -= PRFX[i][j-1];
        if(ones == R - j + 1)
            return cut(PRFX,i-1,j-1,R);
        else
            return i+1;   
    }
}
int main(){
    int N,M;
    cin >> N >> M;
    MATRIXC MAT(N,vector<char>(M));
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            cin >> MAT[i][j];
        }
    }
    MATRIXLL DP(N,vector<ll>(M,0));
    MATRIX PRFX(N,vi(M,0));
    buildPrfxArr(PRFX,MAT,N,M);
    for(int i=0;i<N;++i){
        if(MAT[i][0] == '1')
            DP[i][0] = 1;
    }
    for(int j=0;j<M;++j){
        if(MAT[0][j] == '1')
            DP[0][j] = 1;
    }
    for(int i=1;i<N;++i){
        for(int j=1;j<M;++j){
            if(MAT[i][j] != '1')
                DP[i][j] = 0;
            else{
            
                DP[i][j] = min(i+1,j+1);
                int c = cut(PRFX,i-1,j-1,j);
                DP[i][j] -= c;
                if(i > j && c > 0)
                    DP[i][j] += i - j;
            }
        }
    }
    int count = 0;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            count += DP[i][j];
        }
    }
    cout<<count<<'\n';
}
