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
    int n;
    cin >> n;
    vi arr(n);
    for(int &i : arr)
        cin >> i;
    sort(arr.begin(),arr.end());
    int minHex = 1;
    for(int i=0;i<n;++i){
        if(arr[i] > minHex){
            arr[i] = minHex;
            minHex++;
        }
        else if(arr[i] == minHex){
            minHex++;
        }
    }
    cout<<minHex<<'\n';
}
