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
    int count = 0;
    char curr = 'P';
    int total = 0;
    for(char x : s){
        if(curr != x){
            curr = x;
            total += count / 5;
            if((count % 5) != 0){
                total++;
            }
            count = 1;
        }
        else{
            count++;
        }
    }
    total += count/5;
    if((count % 5) != 0)
        total++;
    cout<<total<<'\n';
}
