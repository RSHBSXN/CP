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
//1524
ll getNumWithoutZero(ll a){
    if(a == 0)
        return 0;
    else if(a % 10 == 0)
        return  getNumWithoutZero(a/10);
    else
        return a % 10 + (10 * getNumWithoutZero(a/10));
}
int main(){
    ll a,b;
    cin >> a >> b;
    ll c = a + b;
    ll a1 = getNumWithoutZero(a),b1 = getNumWithoutZero(b),c1 = getNumWithoutZero(c);
    cout<<((a1 + b1 == c1)?"YES":"NO")<<'\n';
}                                                                                                                   
