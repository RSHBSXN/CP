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
int findMax(vi arr,int index,int b,int value){
    if(index == arr.size())
        return 0;
    else{
        if(value < arr[index])
            return findMax(arr,index+1,b,value+b);
        else
            return max(findMax(arr,index+1,b,value+b),1 + findMax(arr,index+1,b,value - arr[index]));
    }
}
int main(){
    int n,k,b;
    cin >> n >> k >> b;
    vi ARR(n);
    for(int &o : ARR)
        cin >> o;
    cout<<findMax(ARR,0,b,k)<<'\n';
}
