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
    int n;
    cin >> n;
    vector<LL> arr(n);
    for(int i=0;i<n;++i){
        cin >> arr[i];
    } 
    int maxLen = (arr.size()>1)?2:1;
    for(int i=0,j=i+2;j<n;){
        if(arr[j] == arr[j-1] + arr[j-2]){
            maxLen = max(maxLen,j - i + 1);
            j++;
        }
        else{
            i = j-1;
            j = i+2;
        }
    }
    cout<<maxLen<<'\n';
}
