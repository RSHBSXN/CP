/*
    Author: Rishabh Saxena
    All the best!!
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define xll __int128
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<ll>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
MATRIX MEMO;
int minMoves(string s,int st,int en){
    if(st >= en)
        return 0;
    else{
        if(MEMO[st][en] == -1){
            int &ref = MEMO[st][en];
            int repl = minMoves(s,st+1,en-1) + (s[st] != s[en]);
            int remove = 1 + min(minMoves(s,st+1,en),minMoves(s,st,en-1));
            return ref = min(repl,remove);
        }
        else
            return MEMO[st][en];
    }
}
int main(){
    FASTIO;
    int n;
    cin >> n;   
    for(int i=1;i<=n;++i){
        string s;
        cin >> s;
        MEMO.resize(s.length(),vi(s.length(),-1));
        cout<<"Case "<<i<<": "<<minMoves(s,0,s.length()-1)<<'\n';
        MEMO.clear();
    }
}
