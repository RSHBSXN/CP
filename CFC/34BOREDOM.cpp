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
#define LIMIT 100001
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
int Count[LIMIT] = {0};
unordered_map<int,LL> MEMO;
LL getMax(LL n,int Max){
    if(MEMO.find(n) == MEMO.end()){
        LL &ref = MEMO[n];
        if(n == 0)
            ref = 0;
        else if(n == 1)
            ref = Count[1];
                //Either current number is deleted so previous number must be selected
        else    //or current number is selected so previous one is deleted and we need to check for previous to previous
            ref = max(getMax(n-1,Max),getMax(n-2,Max) + Count[n] * n);
        
        return ref;
    }
    else
        return MEMO[n];
    
}
int main(){
    int n;
    cin >> n;
    int Max = 0;
    while(n--){
        int num;
        cin >> num;
        Count[num]++;
        Max = max(num,Max);
    }
    cout<<getMax(Max,Max)<<'\n';
}
