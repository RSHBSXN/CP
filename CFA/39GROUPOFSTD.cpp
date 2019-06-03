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
#define vll vector<ll>
#define vi vector<int>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<ll>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
int getSum(vi &prfx,int l,int r){
    if(r < l)
        return 0;
    int sum = prfx[r];
    if(l > 0)
        sum -= prfx[l-1];
    return sum;
}
int main(){
    FASTIO;
    int m;
    cin >> m;
    vi prfx(m);
    for(int i=0;i<m;++i){
        cin >> prfx[i];
        if(i > 0)
            prfx[i] += prfx[i-1];
    }
    int x,y;
    cin >> x >> y;
    int result = 0;
    for(int i=0;i<m;++i){
        int left = getSum(prfx,0,i-1);
        int right = getSum(prfx,i,m-1);
        if(left >= x && left <= y && right >= x && right <= y){
            result = i+1;
            break;
        }
    }
    cout<<result<<'\n';
}
