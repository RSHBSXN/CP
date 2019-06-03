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
    int n,m;
    cin >> n >> m;
    vector<string> MAT(n);
    for(string &s : MAT)
        cin >> s;
    vector<bool> isHigh(n);
    for(int i=0;i<m;++i){
        vi Maxs;
        char Max = '0';
        for(int j=0;j<n;++j){
            if(Max < MAT[j][i]){
                Max = MAT[j][i];
                Maxs.clear();
                Maxs.push_back(j);
            }
            else if(Max == MAT[j][i]){
                Maxs.push_back(j);
            }
        }
        for(int i : Maxs)
            isHigh[i] = true;
    }
    int count = 0;
    for(bool x : isHigh){
        if(x)
            count++;
    }
    cout<<count<<'\n';
}
