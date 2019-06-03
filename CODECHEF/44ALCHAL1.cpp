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
int main(){
    int n;
    cin >> n;
    int maxOne = -1,maxTwo = -1;
    while(n--){
        int num;
        cin >> num;
        if(num > maxOne){
            maxTwo = maxOne;
            maxOne = num;
        }
    }
    if(maxTwo == -1)  
        cout<<0<<'\n';
    else
        cout<<maxTwo<<'\n';
    
}
