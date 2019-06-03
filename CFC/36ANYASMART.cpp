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
    int n,m,k;
    cin >> n >> m >> k;
    unordered_map<int,pii> Loc;
    int rows = n/k;
    int lastCol;
    if(n % k != 0){
        rows++;
        lastCol = n % k;
    }
    else
        lastCol = k;
    MATRIX MAT(rows);
    for(int i=0;i<rows;++i){
        if(i < rows-1)
            MAT[i].resize(k);
        else
            MAT[i].resize(lastCol);
        for(int j=0;j<MAT[i].size();++j){
            cin >> MAT[i][j];
            Loc[MAT[i][j]] = {i,j};
        }
    }
    LL swaps = 0;
    while(m--){
        int num,val;
        cin >> num;
        pii loc = Loc[num],newLoc;
        swaps += loc.first + 1;
        
        if(loc.second == 0 && loc.first > 0){
            newLoc = {loc.first-1,MAT[loc.first-1].size()-1};
        }
        else if(loc.second > 0){
            newLoc = {loc.first,loc.second-1};
        }
        val = MAT[newLoc.first][newLoc.second];
        swap(Loc[val],Loc[num]);
        swap(MAT[loc.first][loc.second],MAT[newLoc.first][newLoc.second]);
    }
    cout<<swaps<<'\n';
}
