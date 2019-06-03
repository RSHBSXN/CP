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
int binarySearch(vi &arr,int num){
    int l = 0,r = arr.size()-1;
    while(r - l > 1){
        int mid = (l + r)/2;
        if(arr[mid] >= num)
            r = mid;
        else 
            l = mid + 1;
    }
    if(arr[l] >= num)
        return l;
    else
        return r;
}
int main(){
    FASTIO;
    int n;
    cin >> n;
    vi prfx(n);
    for(int i=0;i<n;++i){
        cin >> prfx[i];
        if(i > 0)
            prfx[i] += prfx[i-1];
    }
    int m;
    cin >> m;
    while(m--){
        int worm;
        cin >> worm;
        cout<<binarySearch(prfx,worm)+1<<'\n';
    }
    
}
