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
#define PREC 1e-9
struct item{
    int price,fav;
    item(){
        cin >> price >> fav;
    }
};
vector<item> arr;
MATRIX DP;
int m,n;
int main(){
    // FASTIO;
    while(cin >> m >> n){
        DP = MATRIX(n,vi(m+1,-1));
        arr = vector<item>(n);
        if(m < 2000 && m+200 > 2000){
            DP = MATRIX(n,vi(m+201,-1));
            m += 200;
        }
        for(int i=0;i<n;++i){
            for(int j=arr[i].price;j<=m;++j)
                DP[i][j] = arr[i].fav;
        }
    }
}
