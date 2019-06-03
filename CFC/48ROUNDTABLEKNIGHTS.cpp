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
bool solve(vi &arr){
    int n = arr.size();
    bool possible = false;
    //i represents length of edge of polygon
    //degenerate polygons are not allowed so total edges of polygon must be >=3

    for(int i=1;n/i >= 3;++i){
        if(n % i == 0){
            vector<bool> Poly(i,true);
            for(int j=0;j<n;++j){
                if(arr[j] == 0){
                    Poly[j % i] = false;
                }
            }
            for(int j=0;j<i;++j){
                if(Poly[j])
                    return true;
            }
        }
    }
    return false;
}
int main(){
    FASTIO;
    int n;
    cin >> n;
    vi arr(n);
    for(int &i : arr)
        cin >> i;
    cout<<((solve(arr))?"YES":"NO")<<'\n';
}
