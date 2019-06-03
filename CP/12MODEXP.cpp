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
ll POW(ll A,ll B,ll mod){
    if(B == 0)
        return 1;
    else{
        ll r = POW(A,B/2,mod) % mod;
        if(B & 1)
            return (A * (r * r)%mod)%mod;
        return (r * r)%mod;  
    }
}
int main(){
    ll A,B,m;
    cin >> A >> B >> m;
    cout<<POW(A,B,m)<<'\n';
}
