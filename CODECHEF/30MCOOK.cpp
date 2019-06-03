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
#define vll vector<LL>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<LL>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
int getMultiplier(int X,int size){
    int div = X/size;
    if((X % size) != 0)
        div++;
    return div;
}
LL getXor(vll &prfx,int l,int r){
    LL Xor = prfx[r];
    if(l > 0)
        Xor ^= prfx[l-1];
    return Xor;
}
int main(){
    FASTIO;
    int n,q;
    cin >> n >> q;
    vll prfx(n),arr(n);
    LL Xor = 0;
    for(int i = 0;i<n;++i){
        cin >> arr[i];
        Xor ^= arr[i];
        prfx[i] = Xor;
    }
    prfx.push_back(0);    
    while(q--){
        LL ind;
        cin >> ind;
        LL res;
        LL mult = getMultiplier(ind,n+1);
        bool leftOdd = mult & 1;
        int sep = ind % (n+1);
        if(sep == 0)
            sep = n+1;
        if(leftOdd){
            res = getXor(prfx,0,sep-1);
        }
        else
            res = getXor(prfx,sep,n);
        cout<<res<<'\n';
    }
}
