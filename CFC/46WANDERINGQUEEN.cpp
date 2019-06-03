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
struct coord{
    int x,y;
    bool operator ==(coord b){
        return this->x == b.x && this->y == b.y;
    }
};
coord s,e;
MATRIXC MAT;
MATRIX VIS,DIST;
coord moves[] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1}};
inline bool safe(coord move,int i){
    return move.x >= 0 && move.x < MAT.size() && move.y >=0 && move.y < MAT[0].size() && MAT[move.x][move.y] != 'X' && !(VIS[move.x][move.y] & (1 << i));
}
int minMoves(){
    queue<coord> Que;
    Que.push(s);
    VIS[s.x][s.y] = 255;
    DIST[s.x][s.y] = 0;
    while(Que.size()){
        coord frnt = Que.front();
        Que.pop();
        if(frnt == e){
            return DIST[frnt.x][frnt.y];
        }
        for(int i=0;i<8;++i){
            int d = 1;
            while(true){
                coord New = {frnt.x + moves[i].x * d,frnt.y + moves[i].y * d};
                if(safe(New,i)){
                    if(!VIS[New.x][New.y]){
                        DIST[New.x][New.y] = DIST[frnt.x][frnt.y] + 1;
                        Que.push(New);
                    }
                    VIS[New.x][New.y] |= (1 << i);
                    
                }
                else
                    break;
                ++d;
            }
        }
    }
    return -1;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        MAT = MATRIXC(n,vector<char>(m));
        VIS = MATRIX(n,vi(m,0));
        DIST = MATRIX(n,vi(m,0));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin >> MAT[i][j];
                if(MAT[i][j] == 'S')
                    s = {i,j};
                else if(MAT[i][j] == 'F')
                    e = {i,j};
            }
        }
        cout<<minMoves()<<'\n';
        VIS.clear();
        DIST.clear();
        MAT.clear();
    }
}
