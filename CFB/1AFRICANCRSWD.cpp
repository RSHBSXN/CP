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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
int main(){
    int n,m;
    cin >> n >> m;
    MATRIXC MAT(n,vector<char>(m));
    vector<unordered_map<char,int>> PRFXC(m),PRFXR(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> MAT[i][j];
            PRFXR[i][MAT[i][j]]++;
            PRFXC[j][MAT[i][j]]++;
        }
    }
    string s;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(PRFXC[j][MAT[i][j]] == 1 && PRFXR[i][MAT[i][j]] == 1)
                s += MAT[i][j]; 
        }
    }
    cout<<s<<'\n';
}
