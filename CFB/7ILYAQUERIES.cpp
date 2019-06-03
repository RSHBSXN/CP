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
vi calPreArr(string s){
    vi prfxArr(s.length());
    int total = 0;
    for(int i=0;i<s.length();++i){
        if(i < s.length()-1 && s[i] == s[i+1])
            total++;
        prfxArr[i] = total;
    }
    return prfxArr;
}
int getChars(vi &prfx,int l,int r){
    int result = prfx[r-1];
    if(l > 0)
        result -= prfx[l-1];
    return result;
}
int main(){
    FASTIO;
    string s;
    cin >> s;
    vi prfx = calPreArr(s);
    int m;
    cin >> m;
    while(m--){
        int l,r;
        cin >> l >> r;
        l--,r--;
        int numbers = getChars(prfx,l,r);
        cout<<numbers<<'\n';
    }
}
