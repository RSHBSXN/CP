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
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n],prfx[n] = {0};
        for(int i=0;i<n;++i)
            cin >> arr[i];
        prfx[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            prfx[i] = 1;
            ll res = ((ll)arr[i+1]) * arr[i];
            if(res < 0)
                prfx[i] += prfx[i+1]; 
        }
        for(int i=0;i<n;++i)
            cout<<prfx[i]<<' ';
        cout<<'\n';
    }
}
