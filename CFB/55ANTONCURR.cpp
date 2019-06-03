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
int main(){
    string s;
    cin >> s;
    int farSm = s.length();
    int nearLg = -1;
    int last = s[s.length()-1] - '0';
    for(int i=s.length()-1;i>=0;--i){
        int num = s[i] - '0';
        if((num & 1) == 0){
            if(num > last)
                nearLg = max(nearLg,i);
            else if(num < last)
                farSm = min(farSm,i);
        }
    }
    string res = "-1";
    if(farSm != s.length()){
        swap(s[farSm],s[s.length()-1]);
        res = s;
    }
    else if(nearLg != -1){
        swap(s[nearLg],s[s.length()-1]);
        res = s;
    }
    cout<<res<<'\n';
}
