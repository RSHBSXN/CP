/*
    Author: Rishabh Saxena
    All the best!!
*/
#include <bits/stdc++.h>
#include <unistd.h>
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
#define SIZE 8
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
unordered_set<int> LDIAG,RDIAG;
unordered_set<int> ROW;
MATRIX SOL;
pii start;
vi Queen(8);
void Lock(unordered_set<int> &SET,int r){
    SET.insert(r);
}
void Unlock(unordered_set<int> &SET,int r){
    SET.erase(r);
}
bool checkValid(unordered_set<int> &SET,int r){
    return SET.find(r) == SET.end();
}
void backTrack(int col){
    if(col == 8){
        SOL.push_back(Queen);
        return;
    }
    if(col != start.second){
        for(int r=0;r<8;++r){
            if(checkValid(ROW,r) && checkValid(LDIAG,r-col) && checkValid(RDIAG,r+col)){
                Lock(ROW,r);
                Lock(LDIAG,r-col);
                Lock(RDIAG,r+col);
                Queen[col] = r;
                backTrack(col+1);
                Unlock(ROW,r);
                Unlock(LDIAG,r-col);
                Unlock(RDIAG,r+col);
            }
        }
    }
    else
        backTrack(col+1);
}
int main(){
    // FASTIO;
    int t;
    cin >> t;
    cout<<'\n';
    while(t--){
        cin >> start.first >> start.second;
        cout<<'\n';
        start.first--,start.second--;
        Lock(ROW,start.first);
        Lock(LDIAG,start.first-start.second);
        Lock(RDIAG,start.first+start.second);
        Queen[start.second] = start.first;
        backTrack(0);
        Unlock(ROW,start.first);
        Unlock(LDIAG,start.first-start.second);
        Unlock(RDIAG,start.first+start.second);
        cout<<"SOLN       COLUMN\n";
        cout<<" #      1 2 3 4 5 6 7 8\n\n";
        for(int i=0;i<SOL.size();++i){
            cout<<setw(2)<<i+1<<"      ";
            for(int j=0;j<8;++j)
                cout<<SOL[i][j]+1<<' ';
            cout<<'\n';
        }
        SOL.clear(); 
        if(t != 0)
            cout<<'\n';
    }
}