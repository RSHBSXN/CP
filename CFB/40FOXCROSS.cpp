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
bool isSafe(MATRIXB &MAT,int row,int col){
    return row >= 0 && row < MAT.size() && col >= 0 && col < MAT.size() && MAT[row][col]; 
}
bool drawCross(MATRIXB &MAT,int Vi,int Vj){
    int Hi = Vi+1;
    int Hj = Vj-1;
    for(int i=0;i<3;++i){
        if(isSafe(MAT,Vi+i,Vj) && isSafe(MAT,Hi,Hj+i)){
             MAT[Vi+i][Vj] = false;
             MAT[Hi][Hj+i] = false;
        }
        else
            return false;
    }
    return true;
}
int main(){
    FASTIO;
    int n;
    cin >> n;
    MATRIXB MAT(n,vector<bool>(n,false));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;j++){
            char x;
            cin >>x;
            if(x == '#')
                MAT[i][j] = true;
        }
    }
    bool canDraw = true;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(MAT[i][j] && !drawCross(MAT,i,j)){
                canDraw = false;
                break;
            }
        }
    }
    cout<<((canDraw)?"YES":"NO")<<'\n';
}
