#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define xll __int128
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<ll>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
MATRIXLL DP;
string str;
ll getAllPoss(int i,int j){
    DP = MATRIXLL(str.length(),vll(str.length(),0));
    for(int i=0;i<str.length();++i)
        DP[i][i] = 1;
    for(int i=str.length()-2;i>=0;--i){
        for(int j=i+1;j<str.length();++j){
            DP[i][j] = DP[i+1][j] + DP[i][j-1] - DP[i+1][j-1];
            if(str[i] == str[j])
                DP[i][j] += 1 + DP[i+1][j-1];
        }
    }
    return DP[0][str.length()-1];
}
int main(){
    FASTIO;
    int t;
    cin >> t;
    while(t--){
        cin >> str;
        cout<<getAllPoss(0,str.length()-1)<<'\n';
    }
}