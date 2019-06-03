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
    int n,d;
    cin >> n >> d;
    vi arr(n);
    for(int i=0;i<n;i++)    
         cin >> arr[i];
    LL res = 0;
    for(int i=0,j=2;j<n;){
        bool smaller = false;
        if(arr[j] - arr[i] <= d){
            LL x = j - i - 1;
            res += (x * (x+1))/2;
            smaller = true;
        }
        while(i+2 <= j && arr[j] - arr[i] > d){
            i++;
        }
        if(i+2 > j)
            j++;
        else if(smaller)
            j++;
    
    }    
    cout<<res<<'\n';
}
