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
    string s;
    cin >> s;
    unordered_map<char,int> Possible = {{'0',2},{'1',7},{'2',2},{'3',3},{'4',3},{'5',4},{'6',2},{'7',5},{'8',1},{'9',2}};
    int count = 1;
    for(int i=0;i<s.length();++i){
        count *= Possible[s[i]];
    }
    cout<<count<<'\n';
}
