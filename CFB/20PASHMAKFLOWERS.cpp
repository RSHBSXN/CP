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
    LL n;
    cin >> n;
    vi ARR(n);
    int Min = INT32_MAX,Max = INT32_MIN;
    for(int &i : ARR){
        cin >> i;
        Min = min(i,Min);
        Max = max(i,Max);
    }
    LL maxCount = 0,minCount = 0;
    for(int i=0;i<n;++i){
        if(ARR[i] == Min){
            minCount++;
        }
        if(ARR[i] == Max){
            maxCount++;
        }
    }
    if(Max == Min)
        maxCount = (n * (n-1))/2;
    else
        maxCount *= minCount;
    cout<<Max - Min<<' '<<maxCount<<'\n';
}
