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
map<LL,LL> getCount(LL n){
    map<LL,LL> MAP = {{1,1}};
    while(n > 1){
        map<LL,LL> temp = MAP;
        for(auto &x : temp)
            x.second *= 4;
        //(1,4)
        temp.rbegin()->second--;
        temp[temp.rbegin()->first + 1] = 1;
        //(1,3)(2,1)
        MAP = temp;
        n /= 4;
    }
    return MAP;
}
int main(){
    FASTIO;
    LL n;
    cin >> n;
    vector<LL> ARR(n);
    for(LL &x : ARR)
        cin >> x;
    sort(ARR.begin(),ARR.end());
    map<LL,LL> MAP = getCount(n);
    LL i = 0;
    LL sum = 0;
    for(auto &x : MAP){
        for(int count = 0;count < x.second;count++){
            sum += x.first * ARR[i++];
        }
    }
    cout<<sum<<'\n';
}
