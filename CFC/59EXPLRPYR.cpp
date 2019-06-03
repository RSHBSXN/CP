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
#define MOD 1000000000
string str;
MATRIXLL MEMO;
ll solve(int l,int r){
    if(l == r)
        return 1;
    else if(str[l] != str[r])
        return 0;
    else if(MEMO[l][r] != -1)
        return MEMO[l][r];
    else{
        ll &ref = MEMO[l][r];
        ref = 0;
        for(int k=l+2;k<=r;++k){
            ref = (ref + (solve(l+1,k-1) * solve(k,r))%MOD)%MOD;
        }
        return ref;
    }
}
int main(){
    while(cin >> str){
        MEMO = MATRIXLL(str.length(),vll(str.length(),-1));
        cout<<solve(0,str.length()-1)<<'\n';
    }
}
