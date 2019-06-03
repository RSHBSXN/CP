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
    int n,m,d;
    cin >> n >> m >> d;
    bool poss = true;
    int minMoves = 0;
    MATRIX MAT(n,vi(m));
    int Min = INT32_MAX;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin >> MAT[i][j];
            Min = min(Min,MAT[i][j]);
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            int num = MAT[i][j] - Min;
            if(num % d != 0){
                poss = false;
            }
            else{
                minMoves += num / d;
            }
        }
    }
    if(poss)
        cout<<minMoves;
    else
        cout<<-1;
    cout<<'\n';
}
