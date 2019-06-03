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
int main(){
    int n,m,h;
    cin >> n >> m >> h;
    vi front(m);
    vi left(n);
    for(int &i : front)
        cin >> i;
    for(int &i : left)
        cin >> i;
    MATRIX MAT(n,vi(m));
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin >> MAT[i][j];
    MATRIX result(n,vi(m,INT32_MAX));
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(MAT[j][i])
                result[j][i] = min(result[j][i],front[i]);
            else
                result[j][i] = 0;
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(MAT[i][j])
                result[i][j] = min(result[i][j],left[i]);
            else
                result[i][j] = 0;
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)
            cout<<result[i][j]<<' ';
        cout<<'\n';
    }
}
