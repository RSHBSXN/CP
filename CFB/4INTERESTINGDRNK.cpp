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
#define LIMIT 100001
int main(){
    FASTIO;
    int n;
    cin >> n;
    vi Shops(LIMIT,0);
    for(int i=0;i<n;++i){
        int cost;
        cin >> cost;
        Shops[cost]++;
    }
    int sum = 0;
    for(int i=0;i<Shops.size();++i){
        sum += Shops[i];
        Shops[i] = sum;
    }
    int q;
    cin >> q;
    while(q--){
        int cost;
        cin >> cost;
        if(cost >= LIMIT)
            cout<<Shops[LIMIT-1];
        else
            cout<<Shops[cost];
        cout<<'\n';
    }
}
