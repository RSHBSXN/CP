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
#define MOD 1000000007
ll powMod(ll x,ll y){
    if(y == 0)
        return 1;
    else{
        ll half = ((xll)powMod(x,y/2))%MOD;
        half = (((xll)half) * half)%MOD;
        if(y & 1){
            return (((xll)half) * x)%MOD;
        } 
        else
            return half;
    }
} 
ll gcd(ll a,ll b){
    if(a == 0)
        return b;
    else if(b == 0){
        return a;
    }
    else
        return gcd(b,a % b);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        ll a,b,N;
        cin >> a >> b >> N;
        ll A = powMod(a,N);
        ll B = powMod(b,N);
        ll res = (((xll)A)+B)%MOD;
        xll diff = ((xll)a) - b;
        if(diff < 0)
            diff *= -1;
        cout<<gcd(res,(ll)(diff%MOD))<<'\n';
    }
}