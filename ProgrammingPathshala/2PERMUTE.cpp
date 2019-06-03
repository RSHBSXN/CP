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
int getMin(int coins){
    if(coins == 0){
        return 0;
    }
    else{
        int min4 = INT32_MAX,min3 = INT32_MAX,min1 = INT32_MAX;
        if(coins >= 4){
            min4 = 1 + getMin(coins - 4);
        }
        if(coins >= 3){
            min3 = 1 + getMin(coins - 3);
        }
        min1 = 1 + getMin(coins-1);
        return MIN(min4,min3,min1);
    }
}
int main(){
    int n;
    cin >> n;
    cout<<getMin(n)<<'\n';
}
