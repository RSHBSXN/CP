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
    int n,s,t,pos;
    cin >> n >> s >> t;
    vi Moves(n);
    for(int &i : Moves)
        cin >> i;
    if(s == t)
        cout<<0;
    else{
        vector<bool> VIS(n,false);
        pos = s;
        int moves = 0;
        while(!VIS[pos-1] && pos != t){
            VIS[pos-1] = true;
            pos = Moves[pos-1];
            moves++;
        }  
        if(pos != t)
            moves = -1;
        cout<<moves;
    } 
    cout<<'\n';
}
