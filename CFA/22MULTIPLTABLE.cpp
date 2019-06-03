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
    ll n,x;
    cin >> n >> x;
    int count = 0;
    if(x == 1)
        cout<<1;
    else{
        for(int i=1;(i*i)<=x && i <= n;++i){
            if((x % i == 0) && (x/i) <= n){
                count++;
                if((x/i) != i)
                    count++;
            }
        }
        cout<<count;
    }
    cout<<'\n';
}
