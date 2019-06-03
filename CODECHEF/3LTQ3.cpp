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
int moves(int i,int N,int s){
    if(s == -1){
        return 1;
    }
    else {
        int count = 0;
        for(int j=i;j<=N;j++){
            count += moves(j,N,s-1);
        }
        return count;
    }
}
int main(){
    /*
        PHOD DE JAAKE
    */
   int n,s;
   cin >> n >> s;   
   cout<<moves(1,n,s)<<'\n';
}
