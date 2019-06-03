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
int main(){
    int n,k;
    cin >> n >> k;
    int freq[k+1] = {0};
    while(n--){
        int num;
        cin >> num;
        freq[num]++;
    }
    int cost = 0;
    for(int i=1;i<k;++i){
        cost = max(cost,(k - i) * freq[i]); 
    }
    cout<<cost<<'\n';
}
