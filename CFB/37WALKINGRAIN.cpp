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
#define vll vector<ll>
#define vi vector<int>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<ll>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
int main(){
    int n;
    cin >> n;
    vi arr(n);
    for(int &i : arr)
        cin >> i;
    int Min = arr[n-1];
    for(int i=n-1;i>=0;){
        Min = min(Min,arr[i]);
        if(i > 0){
            int stepOne = (i > 0)?arr[i-1]:INT32_MIN;
            int stepTwo = (i > 1)?arr[i-2]:INT32_MIN;
            if(stepOne > stepTwo)
                i--;
            else
                i-=2;
        }
        else
            break;
    }
    cout<<Min<<'\n';
}
