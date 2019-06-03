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
vi KNAPSCK;
vector<unordered_map<int,int>> MEMO(100); 
int getMin(int index,int rem,int total){
    if(index < 0)
        return abs(rem - total);
    else{
        if(MEMO[index].find(rem) == MEMO[index].end()){
            int &ref = MEMO[index][rem];
            int incl = INT32_MAX,excl = INT32_MAX;
            if(rem >= KNAPSCK[index])
                incl = getMin(index-1,rem - KNAPSCK[index],total + KNAPSCK[index]);
            excl = getMin(index-1,rem,total);
            ref = min(incl,excl);
            return ref;
        }
        else{
            return MEMO[index][rem];
        }
    }
}
int main(){
    FASTIO;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        KNAPSCK.resize(n);
        int total = 0;
        for(int i=0;i<n;i++){
            cin >> KNAPSCK[i];
            total += KNAPSCK[i];
        }
        cout<<getMin(n-1,total,0)<<'\n';
        KNAPSCK.clear();
        for(int i=0;i<n;i++){
            MEMO[i].clear();
        }
    }
}