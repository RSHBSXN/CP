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
bool checkPrime(int x){
    for(int i=2;i*i<= x;++i){
        if((x % i) == 0)
            return false;
    }
    return true;
}
int main(){
    FASTIO;
    int t;
    cin >> t;
    while(t--){
        int x,y;
        cin >> x >> y;
        x += y;
        int z;
        for(z=x+1;!checkPrime(z);z++);
        z -= x;
        cout<<z<<'\n';
    }
}
