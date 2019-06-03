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
int main(){
    ll n;
    cin >> n;
    ll num = 9;
    ll count = 0;
    int dig = 1;
    while(n > 0){
        if(n < num){
            count += n * dig;
            n = 0;
        }
        else{
            count += num * dig;
            dig++;
            n -= num;
            num *= 10;
        }
    }
    cout<<count<<'\n';
}
