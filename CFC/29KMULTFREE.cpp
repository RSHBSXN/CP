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
int returnDiv(unordered_map<int,int> &MAP,int x,int k){
    if(MAP[x] == -1)
        return 0;
    else if(x < k || x % k != 0){
        MAP[x] = -1;
        return 1;
    }
    else if(MAP.find(x/k) == MAP.end()){
        MAP[x] = -1;
        return 1;
    }
    else{
        MAP[x] = -1;
        return 1 + returnDiv(MAP,x/k,k);
    }
}
int main(){
    FASTIO;
    int n,k;
    cin >> n >> k;
    vi ARR(n);
    unordered_map<int,int> MAP;
    for(int &x : ARR){
        cin >> x;
        MAP[x] = 1;
    }
    int count = 0;
    sort(ARR.begin(),ARR.end(),[](int a,int b){return a>b;});
    for(int i=0;i<n;++i){
        int countCurr = returnDiv(MAP,ARR[i],k);
        if(countCurr > 0 && (countCurr & 1)){
            ++countCurr;
        }
        count += countCurr/2;
    }
    cout<<count<<'\n';
}
