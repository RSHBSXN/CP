/*
    Author: Rishabh Saxena
    All the best!!
*/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define XLL __int128
#define pii pair<int,int>
#define pll pair<LL,LL>
#define vi vector<int>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<LL>>
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
    for(int i=0;i<n;++i){
        for(int j=0;j<n-1-i;j++){
            if(arr[j] > arr[j+1]){
                cout<<j+1<<' '<<j+2<<'\n';
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
