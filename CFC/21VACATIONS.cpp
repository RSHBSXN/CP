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


int LonSub(string a,string b){
    int DP[a.length()+1][b.length()+1];
    for(int i=0;i<=a.length();i++){
        for(int j=0;j<=b.length();j++){
            DP[i][j] = 0;
        }
    }
    for(int i=1;i<=a.length();i++){
        for(int j=1;j<=b.length();j++){
            DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
            if(a[i-1] == b[j-1])
                DP[i][j] += 1;
        }
    }
    return DP[a.length()][b.length()];
}
int main(){
    string scan;
    getline(cin,scan);
    int counter = 1;
    while(scan !=  "#"){
        string b;
        getline(cin,b);
        cout<<"Case #"<<counter++<<": you can visit at most "<< LonSub(scan,b)<<" cities.\n";
        getline(cin,scan);
    }
}
