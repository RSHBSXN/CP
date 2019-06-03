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
    FASTIO;
    int n,k;
    cin >> n >> k;
    vi arr(n);
    for(int &i : arr)
        cin >> i;
    vector<pii> Power(k,{0,INT32_MAX});
    for(int i=0;i<n;++i){
        Power[i % k].first += arr[i];
        Power[i % k].second = min(i+1,Power[i%k].second);
    }
    pii res = Power[0];
    for(int i=0;i<k;++i){
        if(Power[i].first < res.first)
            res = Power[i];
    }
    cout<<res.second<<'\n';

}
