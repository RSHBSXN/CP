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
int main(){
    FASTIO;
    MATRIX GARMENTS;
    MATRIXB MEMO;
    int N;
    cin >> N;
    while(N--){
        int M,C;
        cin >> M >> C;
        GARMENTS = MATRIX(C);
        MEMO = MATRIXB(C,vector<bool>(M+1,false));
        for(int i=0;i<C;++i){
            int k;
            cin >> k;
            GARMENTS[i] = vi(k);
            for(int j=0;j<k;++j)
                cin >> GARMENTS[i][j];
        }
        for(int j=0;j<GARMENTS[0].size();++j){
            if(GARMENTS[0][j] <= M){
                MEMO[0][M - GARMENTS[0][j]] = true;
            }
        }
        for(int i=1;i<C;++i){
            for(int j=0;j<=M;++j){
                if(MEMO[i-1][j]){
                    for(int k=0;k<GARMENTS[i].size();++k){
                        if(GARMENTS[i][k] <= j){
                            MEMO[i][j - GARMENTS[i][k]] = true;
                        }
                    }
                }
            }
        }
        int res = -1;
        for(int i=0;i<=M;++i){
            if(MEMO[C-1][i]){
                res = i;
                break;
            }
        }
        cout<<((res == -1)?"no solution":to_string(M-res))<<'\n';
        
    }
}
