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
    vi arr(n),prfx(n);
    for(int &i : arr)
        cin >> i;
    for(int i=0;i<n;++i){
        prfx[i] = arr[i];
        if(i > 0)
            prfx[i] += prfx[i-1];
    }
    int res = 0;
    while(m--){
        int l,r;
        cin >> l >> r;
        l--,r--;
        int sum = prfx[r];
        if(l > 0)
            sum -= prfx[l-1];
        if(sum > 0) 
            res += sum;
    }
    cout<<res<<'\n';

}
