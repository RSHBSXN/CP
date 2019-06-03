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
#define vll vector<ll>
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
    ll n,a;
    cin >> n >> a;
    vll arr(n);
    ll Min = n-1;
    ll Max = 0;
    for(ll &x : arr){
        cin >> x;
        Max += x;
    }
    for(int i=0;i<n;++i){
        ll leftLimit,rightLimit;
        leftLimit = a - Max + arr[i];
        rightLimit = min(a - Min,arr[i]);
        if(leftLimit <= 0)
            leftLimit = 1;
        cout<<arr[i] - ((rightLimit - leftLimit) + 1)<<' ';
    }
    cout<<'\n';
}
