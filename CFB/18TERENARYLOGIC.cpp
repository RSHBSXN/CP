/*
    Author: Rishabh Saxena
    All the best!!
*/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define XLL __int128
#define pii pair<int,int>
#define pll pair<LL,LL>
#define vi vector<int>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<LL>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
string getTerenary(LL num){
    string res;
    while(num > 0){
        res += ((num % 3) + '0');
        num /= 3;
    }
    reverse(res.begin(),res.end());
    return res;
}
LL convertNum(string s){
    LL number = 0;
    int p = 1;
    for(int i=s.length()-1;i>=0;--i){
        number = number + (p * (s[i] - '0'));
        p*=3;
    }
    return number;
}
int main(){
    MATRIX MAT = {{0,3},{1,4},{2}};
    LL a,c;
    cin >> a >> c;
    string ta = getTerenary(a),tc = getTerenary(c);
    int len = max(ta.length(),tc.length());
    ta = string(len - ta.length(),'0') + ta;
    tc = string(len - tc.length(),'0') + tc;
    string tb(len,'0');
    for(int i=0;i<len;++i){
        int rem = tc[i] - '0'; //0,1,2
        int b = 3;
        int part = ta[i] - '0';
        for(int s=0;s<MAT[rem].size();++s){
            int bpart = MAT[rem][s] - part;
            if(bpart >= 0 && bpart < 3){
                b = bpart;
                break;
            }
        }
        tb[i] = b + '0';
    }
    cout<<convertNum(tb)<<'\n';
}
