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
    bool gotNonZero = false;
    LL total = 0;
    LL prev = 0;
    for(int i=0;i<n;++i){
        if(gotNonZero || arr[i] != 0){
            total += abs(arr[i] - prev);
            prev = arr[i];
            if(!gotNonZero)
                gotNonZero = true;
        }
    }
    cout<<total<<'\n';
}
