/*
    Author: Rishabh Saxena
    7All the best!!
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
int main(){
    int n;
    cin >> n;
    int x = n;
    for(int i=2;i*i<=n && x > 1;++i){
        while(x % i == 0){
            cout<<i<<' ';
            x /= i;
        }
    }    
    if(x > 1)
        cout<<x<<'\n';
}
