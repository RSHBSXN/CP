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
int l;
int n;
vi arr;
MATRIX MEMO;
int solve(int l,int r){
    if(l+1 == r)
        return 0;
    else if(MEMO[l][r] != -1)
        return MEMO[l][r];
    else{
        int &ref = MEMO[l][r];
        ref = INT32_MAX;
        for(int k=l+1;k<r;++k){
            ref = min(ref,solve(l,k) + solve(k,r) + (arr[r] - arr[l]));
        }
        return ref;
    }
}
int main(){
    while(cin >> l && l != 0){
        cin >> n;
        arr = vi(n+2);
        arr[n+1] = l;
        MEMO = MATRIX(n+2,vi(n+2,-1));
        for(int i=1;i<=n;++i)
            cin >> arr[i];
        cout<<"The minimum cutting is "<<solve(0,arr.size()-1)<<".\n";
    }
}
