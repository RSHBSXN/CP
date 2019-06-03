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
MATRIXB MAT,VIS;
bool isSafe(pii move){
    return move.first >= 0 && move.first < MAT.size() && move.second >=0 && move.second < MAT.size() && MAT[move.first][move.second] != 1 && !VIS[move.first][move.second];
}
void move(pii s,vector<pii> &ARR){
    ARR.push_back(s);
    int rdir[] = {0,0,+1,-1};
    int cdir[] = {+1,-1,0,0};
    for(int i=0;i<4;i++){
        pii newMove = {s.first + rdir[i],s.second + cdir[i]};
        if(isSafe(newMove)){
            VIS[newMove.first][newMove.second] = true;
            move(newMove,ARR);
        }
    }
}
int main(){
    int n;
    cin >> n;
    MAT.resize(n,vector<bool>(n));
    VIS.resize(n,vector<bool>(n,false));
    pii s,d;
    cin >> s.first >> s.second;
    s.first--;
    s.second--;
    cin >> d.first >> d.second;
    d.first--;
    d.second--;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char lnd;
            cin >> lnd;
            if(lnd == '0')
                MAT[i][j] = false;
            else
                MAT[i][j] = true;
        }
    }
    vector<pii> ARRS;
    vector<pii> ARRD;
    move(s,ARRS);
    if(VIS[d.first][d.second])
        cout<<0;
    else{
        move(d,ARRD);
        int minD = INT32_MAX;
        for(int i=0;i<ARRS.size();i++){
            for(int j=0;j<ARRD.size();j++){
                int x = ARRS[i].first - ARRD[j].first;
                int y = ARRS[i].second - ARRD[j].second;
                int d = (x * x) + (y * y);
                if(d < minD)
                    minD = d; 
            }
        }
        cout<<minD<<'\n';
    }
}
