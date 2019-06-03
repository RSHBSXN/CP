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
    string prfx;
    cin >> prfx;
    int n;
    cin >> n;
    string res = prfx;
    bool first = false;
    while(n--){
        string str;
        cin >> str;
        if(str.length() >= prfx.length() && str.substr(0,prfx.length()) == prfx){
            if(!first){
                res = str;
                first = true;
            }
            else if(res > str)
                res = str;
        }
    }
    cout<<res<<'\n';
}
