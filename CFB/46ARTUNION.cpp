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
    FASTIO;
    int m,n;
    cin >> m >> n;
    MATRIX DP(m,vi(n,0));
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            int t;
            cin >> t;
            DP[i][j] = t;
            int left = INT32_MIN,up = INT32_MIN;
            if(i != 0){
                up = DP[i-1][j];
            }
            if(j != 0){
                left = DP[i][j-1];
            }
            if(left != INT32_MIN || up != INT32_MIN)
                DP[i][j] += max(left,up);
        }
    }
    for(int i=0;i<m;++i){
        cout<<DP[i][n-1]<<' ';
    }
    cout<<'\n';
}
