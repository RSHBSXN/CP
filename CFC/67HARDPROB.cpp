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
#define PREC 1e-9tr[i]
int n;
vi C;
vector<string> Str;
vector<string> Strr;
MATRIXLL DP;
int main(){
    cin >> n;
    C = vi(n);
    Str = vector<string> (n);
    Strr = vector<string> (n);
    DP = MATRIXLL(n,vll(2,0));
    for(int &i : C)
        cin >> i;
    for(int i=0;i<n;++i){
        cin >> Str[i];
        Strr[i] = Str[i];
        reverse(Strr[i].begin(),Strr[i].end());
    }
    DP[0][0] = 0;
    DP[0][1] = C[0];
    for(int i=1;i<n;++i){
        //Dont reverse the ith string
        if(Str[i-1] <= Str[i] && Strr[i-1] <= Str[i])
            DP[i][0] = min(DP[i-1][0],DP[i-1][1]);
        else if(Str[i-1] <= Str[i])
            DP[i][0] = DP[i-1][0];
        else if(Strr[i-1] <= Str[i])
            DP[i][0] = DP[i-1][1];
        else
            DP[i][0] = INT64_MAX;
        
        //Reverse the ith string
        if(Str[i-1] <= Strr[i] && Strr[i-1] <= Strr[i])
            DP[i][1] = min(DP[i-1][0],DP[i-1][1]);
        else if(Str[i-1] <= Strr[i])
            DP[i][1] = DP[i-1][0];
        else if(Strr[i-1] <= Strr[i])
            DP[i][1] = DP[i-1][1];
        else
            DP[i][1] = INT64_MAX;
        
        if(DP[i][1] != INT64_MAX)
            DP[i][1] += C[i];
    }
    ll res = min(DP[n-1][0],DP[n-1][1]);
    if(res == INT64_MAX)
        cout<<-1;
    else
        cout<<res;
    cout<<'\n';
}
