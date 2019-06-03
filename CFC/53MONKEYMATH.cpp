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
vi rungs;
bool canReach(int k){
    int curr = 0;
    for(int i=0;i<rungs.size();++i){
        if(rungs[i] - curr > k)
            return false;
        else{
            if(rungs[i] - curr == k)
                k--;
            curr = rungs[i];
        }
    }
    return true;
}
ll bisection(ll L){
    ll R = INT32_MAX;
    while(R - L > 1){
        ll mid = (R + L) >> 1;
        bool can = canReach(mid);
        if(can) 
            R = mid;
        else
            L = mid;
    }
    if(canReach(L))
        return L;
    else
        return R;
}
int main(){
    FASTIO;
    int t;
    cin >> t;
    for(int j=1;j<=t;++j){
        int n;
        cin >> n;
        rungs = vi(n);
        int minK = rungs[0];
        for(int i=0;i<n;++i){
            cin >> rungs[i];
            if(i > 0)
                minK = max(minK,rungs[i] - rungs[i-1]);
        }
        cout<<"Case "<<j<<": "<<bisection(minK)<<'\n';
    }
}
