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
    string n,m;
    cin >> n >> m;
    unordered_map<char,int> cCount,reqCount;
    for(char i : n)
        cCount[i]++;
    for(char i : m)
        reqCount[i]++;
    bool valid = true;
    int area = 0;
    for(auto x : reqCount){
        if(cCount.find(x.first) == cCount.end()){
            valid = false;
            break;
        }
        else if(cCount[x.first] >= x.second){
            area += x.second;
        }
        else{
            area += cCount[x.first];
        }
    }
    if(!valid)
        area  = -1;
    cout<<area<<'\n';
    
}
