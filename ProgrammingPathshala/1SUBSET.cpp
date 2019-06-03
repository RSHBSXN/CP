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
int subset(vi ARR,int S1,int S2,int index){
    if(index == ARR.size())
        return abs(S1-S2);
    else{
        return min(subset(ARR,S1 + ARR[index],S2,index+1),subset(ARR,S1,S2 + ARR[index],index+1));
    }
}
int main(){
    int n,key;
    cin >> n;
    vi ARR(n);
    for(int &i : ARR)
        cin >> i;
    cout<<subset(ARR,0,0,0)<<'\n';
}
