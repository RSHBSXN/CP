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
#define vi vector<int>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<ll>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
MATRIX3D MEMO;
int minMoves(vi &arr,int i,int left,int right,int k){
    int j = (arr.size() - i - 1) - left + right;
    if(i >= j)
        return 0;
    else if(left + right > k)
        return 30;
    else if(MEMO[i][left][right] == -1){
        int &ref = MEMO[i][left][right];
        if(arr[i] == arr[j])
            ref = minMoves(arr,i+1,left,right,k);
        else
            ref = 1 + min(minMoves(arr,i,left+1,right,k),minMoves(arr,i+1,left,right+1,k));
        return ref;
    }
    else
        return MEMO[i][left][right];
}
int main(){ 
    FASTIO;
    int T;
    cin >> T;
    for(int t = 1;t<=T;++t){
        int n,k;
        cin >> n >> k;
        vi arr(n);
        for(int &i : arr)
            cin >> i;
        MEMO.resize(n,MATRIX(k+1,vi(k+1,-1)));
        cout<<"Case "<<t<<": ";
        int moves = minMoves(arr,0,0,0,k);
        if(moves > k)
            cout<<"Too difficult";
        else if(moves == 0)
            cout<<"Too easy";
        else
            cout<<moves;
        cout<<'\n';
        MEMO.clear();
    }
}
