/*
    Author: Rishabh Saxena
    All the best!!
*/
#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
#define LL long long
#define XLL __int128
#define pii pair<int,int>
#define pll pair<LL,LL>
#define vi vector<int>
#define vll vector<LL>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<LL>>
#define MATRIX3D vector<vectoro<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
int main(){
    int N;
    cin >> N;
    vector<string> Str(N);
    vi Pos(N,0);
    vi Res;
    for(string &s : Str)
        cin >> s;
    vector<unordered_set<int>> MAPS(10);
    int prev = N-1;
    for(int i=0;i<N-1;++i){
        int pos = Str[i][0] - '0';
        MAPS[pos].insert(i);
    }
    bool done = true;
    while(done){
        if(Pos[prev] < Str[prev].length()){
            int pos = Str[prev][Pos[prev]] - '0';
            MAPS[pos].insert(prev);
        }
        done = false;
        for(int i=0;i<10;++i){
            if(MAPS[i].size() == 1){
                Res.push_back((*MAPS[i].begin())+1);
                prev = *MAPS[i].begin();
                done = true;
                MAPS[i].erase(MAPS[i].begin());
                Pos[prev]++;
                break;    
            }
            else if(MAPS[i].size() > 1){
                unordered_set<int> :: iterator itr = MAPS[i].begin(),itr2;
                for(itr2 = MAPS[i].begin();itr2 != MAPS[i].end();++itr2){
                    int pos = *itr2;
                    if(Pos[pos] == Str[pos].length()-1){
                        itr = itr2;
                        break;
                    }
                }
            }
        }
    }
    for(int i : Res)
        cout<<i<<' ';
    cout<<'\n';
    
}
