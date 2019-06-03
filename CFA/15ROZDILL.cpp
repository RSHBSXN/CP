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
    int count = 0;
    int ind = -1;
    int Min = INT32_MAX;
    for(int i=1;i<=n;++i){
        int num;
        cin >> num;
        if(num < Min){
            count = 1;
            Min = num;
            ind = i;
        }
        else if(num == Min)
            count++;
    }
    cout<<((count == 1)?to_string(ind):"Still Rozdil")<<'\n';
}
