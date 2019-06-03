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
int main(){
    int n;
    cin >> n;
    map<int,int> MAP;
    while(n--){
        int num;
        cin >> num;
        MAP[num]++;
    }
    int pairs = 0;
    int curr = 0;
    vector<int> Freq;
    for(auto itr = MAP.begin();itr != MAP.end();itr++){
        Freq.push_back(itr->second);
    }
}
/*
    2   1   1
    12123
*/