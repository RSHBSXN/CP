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
int getSum(vi &ARR,int L,int R){
    if(R >= 0){
        int sum = ARR[R];
        if(L != 0)
            sum -= ARR[L-1];
        return sum;
    }
    return 0;
}
int main(){
    int n;
    cin >> n;
    vi PRFXE(n,0);
    vi PRFXO(n,0);
    vi ARR(n);
    for(int i = 0;i<n;++i){
        cin >> ARR[i];
        if(i & 1){
            PRFXE[i] = ARR[i];
        }
        else{
            PRFXO[i] = ARR[i];
        }
        if(i != 0){
            PRFXE[i] += PRFXE[i-1];
            PRFXO[i] += PRFXO[i-1];
        }
    }
    int count = 0;
    for(int i=0;i<n;++i){
        int prevOdd = getSum(PRFXO,0,i-1);
        int nextOdd = getSum(PRFXO,i+1,n-1);
        int prevEven = getSum(PRFXE,0,i-1);
        int nextEven = getSum(PRFXE,i+1,n-1);
        if(i == 0 && nextEven == nextOdd)
            count++;
        else if(i == n-1 && prevEven == prevOdd)
            count++;
        else if(i > 0 && i < n-1 && prevOdd + nextEven == prevEven + nextOdd){
            count++;
        }
    }
    cout<<count<<'\n';

}
