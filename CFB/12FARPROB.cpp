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
    int boys[367] = {0};
    int girls[367] = {0};
    while(n--){
        char g;
        int l,r;
        cin >> g >> l >> r;
        int *ref;
        if(g == 'M'){
            ref = boys;
        }
        else{
            ref = girls;
        }
        ref[l] += 1;
        ref[r+1] -= 1;
    }
    int sumb = 0,sumg = 0;
    for(int i=1;i<=366;++i){
        sumb += boys[i];
        sumg += girls[i];
        boys[i] = sumb;
        girls[i] = sumg;
    }
    int res = 0;
    for(int i=1;i<=366;i++){
        res = max(res,2*min(boys[i],girls[i]));
    }
    cout<<res<<'\n';
}
