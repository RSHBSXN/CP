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
    FASTIO;
    int n;
    cin >> n;
    vector<int> Num(n);
    vector<int> F(n+1,0);
    for(int &i : Num){
        cin >> i;
    }
    int res = 0;
    for(int i=1;i<=n;i++){
        F[i] = F[i-1] ^ (i-1);
        res ^= Num[i-1] ^ (F[(n % i)+1]);
        if(((n/i) & 1) != 0){
            res ^= F[i];
        }
    }
    cout<<res<<'\n';

}
