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
    FASTIO;
    LL q;
    cin >> q;
    while(q--){
        LL N,a,b;
        cin >> N >> a >> b;
        LL ans = 0;
        if(a * 2 <= b){
            ans = a * N;
        }
        else {
            ans = (N/2) * b;
            if((N & 1))
                ans += a;
        }
        cout<<ans<<'\n';
    }
}
