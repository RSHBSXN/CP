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
    unordered_map<char,string> bf = {
    {'>',"1000"}
    ,{'<',"1001"}
    ,{'+',"1010"}
    ,{'-',"1011"}
    ,{'.',"1100"}
    ,{',',"1101"}
    ,{'[',"1110"}
    ,{']',"1111"}
    };
    string s;
    cin >> s;
    string bin;
    for(int i=0;i<s.length();++i)
        bin += bf[s[i]];
    LL toDec = 0;
    LL pow2 = 1;
    LL MOD = 1000003;
    for(int i=bin.length()-1;i>=0;i--){
        toDec = (toDec + (pow2 * (bin[i] - '0'))%MOD)%MOD;
        pow2 = (pow2 * 2)%MOD;
    }
    cout<<toDec<<'\n';
}
