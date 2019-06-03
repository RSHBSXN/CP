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
    int s;
    cin >> s;
    string cows;
    cin >> cows;
    int ins[s] = {0};
    int total = 0;
    for(int i=0;i<s;i++){
        if(cows[i] == 'I')
            total++;
        ins[i] = total;
    }
    total = 0;
    for(int i=0;i<s;i++){
        bool leftI = false;
        bool rightI = false;
        if(i != 0){
            leftI = ins[i-1] != 0   ;
        }
        if(i+1 < s && ins[s-1] > 0){
            rightI = ((ins[s-1] - ins[i]) != 0);
        }
        if(cows[i] != 'F' && !leftI && !rightI)
            total++;
    }
    cout<<total<<'\n';
}
