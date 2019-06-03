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
#define MOD 1000000007
int main(){
    FASTIO;
    vector<int> CYCLE;
    int one,two,n;
    cin >> one >> two >> n;
    n--;
    if(one < 0)
        one = MOD + one;
    if(two < 0)
        two = MOD + two;
    CYCLE.push_back(one%MOD);
    CYCLE.push_back(two%MOD);
    while(CYCLE.size() < 6){
        int res = two - one;
        if(res < 0)
            res = MOD + res;
        one = two;
        two = res%MOD;
        CYCLE.push_back(res % MOD);
    }
    cout<<CYCLE[n%6]<<'\n';
}
