/*
    Author: Rishabh Saxena
    All the best!!
    UVA 193
        for every point check whether you can color black
        before coloring black check all adjc that no one of them is black
        after coloring black move to next vertex

        apply same with white coloring but you dont need to check..
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
#define BLACK 1
#define WHITE 2
#define NONE 0
MATRIX ADJLST;
vi color;
vi maxBlacks,currBlacks;
int n;
bool canPaintBlack(int id){
    for(int adjc : ADJLST[id]){
        if(adjc == id || color[adjc] == BLACK)  
            return false;
    }
    return true;
}
void backTrack(int curr){
    if(curr == n){
        if(maxBlacks.size() < currBlacks.size())
            maxBlacks = currBlacks;
        return;
    }
    int maxPoss = n - curr;
    if(currBlacks.size() + maxPoss <= maxBlacks.size())
        return;
    if(canPaintBlack(curr)){
        color[curr] = BLACK;
        currBlacks.push_back(curr);
        backTrack(curr+1);
        color[curr] = NONE;
        currBlacks.pop_back();
    }
    color[curr] = WHITE;
    backTrack(curr+1);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> n >> m;
        ADJLST = MATRIX(n);
        color = vi(n,NONE);
        while(m--){
            int a,b;
            cin >> a >> b;
            a--,b--;
            ADJLST[a].push_back(b);
            ADJLST[b].push_back(a);
        }
        backTrack(0);
        cout<<maxBlacks.size()<<'\n';
        string sp = "";
        for(int i : maxBlacks)
            cout<<sp<<i+1,sp=" ";
        cout<<'\n';
        maxBlacks.clear();
    }
}