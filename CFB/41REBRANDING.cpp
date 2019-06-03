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
void change(unordered_map<char,char> &CHANGE,char X, char Y){
    for(auto &x : CHANGE){
        if(x.second == X)
            x.second = Y;
        else if(x.second == Y)
            x.second = X;
    }
}
int main(){
    FASTIO;
    int n,m;
    cin >> n >> m;
    string name;
    cin >> name;
    unordered_map<char,char> CHANGE;
    while(m--){
        char x,y;
        cin >> x >> y;
        change(CHANGE,x,y);
        if(CHANGE.find(x) == CHANGE.end())
            CHANGE[x] = y;
        if(CHANGE.find(y) == CHANGE.end())
            CHANGE[y] = x;
    }
    for(char &x : name){
        if(CHANGE.find(x) != CHANGE.end())
            x = CHANGE[x];
    }
    cout<<name<<'\n';
}
