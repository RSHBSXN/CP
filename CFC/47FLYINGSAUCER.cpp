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
int power3(int n,int mod){
    if(n == 0)  
        return 1;
    else{
        int sq = power3(n/2,mod)%mod;
        if(n & 1){
            return (static_cast<ll>(3) * sq * sq)%mod;
        }
        else
            return (static_cast<ll>(sq)*sq)%mod;
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    int res = power3(n,m)-1;
    if(res < 0)
        res += m;
    cout<<res<<'\n'; 
}
