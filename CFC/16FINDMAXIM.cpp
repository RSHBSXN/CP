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
    int arr[n];
    int prfx[n] = {0};
    for(int i=0;i<n;i++){
        cin >> arr[i];
        prfx[i] = arr[i];
        if(i > 0)
            prfx[i] += prfx[i-1];
    }
    string s;
    cin >> s;
    int sum = 0,maxVal = 0;
    for(int i=n-1;i>=0;i--){
        if(s[i] == '1'){
            if(i > 0)
                maxVal = max(maxVal,sum + prfx[i-1]);
            sum += arr[i];
            maxVal = max(maxVal,sum);
        }
    }
    cout<<maxVal<<'\n';
}