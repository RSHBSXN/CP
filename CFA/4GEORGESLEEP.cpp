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
#define auto vector<float>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<LL>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
int getMin(string s){
    string scan;
    int Min = 0;
    bool count = false;
    stringstream sin(s);
    while(getline(sin,scan,':')){
        if(!count){
            Min = stoi(scan) * 60;
            count = true;
        }
        else
            Min += stoi(scan);
    }
    return Min;
}
int main(){
    int z;
    vecto
}