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
vi SUM(6,0);
vi VIS(6,0);
int getCycle(MATRIX &ADJLST,int index,int par,int count){
    if(VIS[index] == 1)
        return count - SUM[index];
    else{
        VIS[index] = 1;
        SUM[index] = count;
        int len = 0;
        for(int i=0;i<ADJLST[index].size();++i){
            int adjc = ADJLST[index][i];
            if(adjc != par){
                if(VIS[adjc] != 2){
                    if(getCycle(ADJLST,adjc,index,count+1) == 3)
                        return 3;
                }
            }
        }
        VIS[index] = 2;
        return 0;
    }
}
int main(){
    int m;
    cin >> m;
    MATRIX FRIEND(6),NOTFRIEND(6);
    while(m--){
        int a,b;
        cin >> a >> b;
        FRIEND[a].push_back(b);
        FRIEND[b].push_back(a);
    }
    for(int i=1;i<6;++i){
        vector<bool> Frnd(6,false);
        for(int j=0;j<FRIEND[i].size();++j){
            Frnd[FRIEND[i][j]] = true;
        }
        for(int j=1;j<6;++j){
            if(j != i && !Frnd[j]){
                NOTFRIEND[i].push_back(j);
                NOTFRIEND[j].push_back(i);
            }
        }
    }
    bool possible = false;
    for(int i=1;i<6;++i){
        if(!VIS[i] && getCycle(FRIEND,i,-1,0) == 3){
            possible = true;
            break;
        }
        else
            VIS = vi(6,0);
    }
    if(!possible){
        VIS = vi(6,0);
        SUM = vi(6,0);
        for(int i=1;i<6;++i){
            if(!VIS[i] && getCycle(NOTFRIEND,i,-1,0) == 3){
                possible = true;
                break;
            }
            else{
                VIS = vi(6,0);
                
            }
        }
    }

    cout<<((possible)?"WIN":"FAIL")<<'\n';
}
