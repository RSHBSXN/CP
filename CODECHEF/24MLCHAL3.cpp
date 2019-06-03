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
#define vll vector<LL>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<LL>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
int main(){
    FASTIO;
    int t;
    cin >> t;
    unordered_map<char,int> bitPos = {{'a',4},{'e',3},{'i',2},{'o',1},{'u',0}};
    while(t--){
        int Count[32] = {0};
        int N;
        cin >> N;
        vector<int>Strs(N);
        for(int i=0;i<N;++i){
            string s;
            cin >> s;
            for(char &x : s){
                Strs[i] |= (1 << bitPos[x]);
            }
            vector<int> Pos;
            for(int j=4;j>=0;j--){
                if((Strs[i] & (1 << j)) != 0){
                    Pos.push_back(j);
                }
            }
            int sz = Pos.size();
            int limit = pow(2,sz);
            for(int j = 1;j<limit;++j){
                int num = 0;
                for(int k=0;k<sz;++k){
                    if((j & (1 << k)) != 0){
                        num |= (1 << Pos[k]);
                    }
                }
                Count[num]++;
            }
        }
        LL count = 0;
        for(int i = 0;i<N;++i){
            int req = 0;
            for(int j=4;j>=0;--j){
                if((Strs[i] & (1 << j)) == 0)
                    req |= (1 << j);
            }
            if(req != 0){
                count += Count[req];
            }
            else{
                count += N-1;
            }
        }
        count /= 2;
        cout<<count<<'\n';  
    }
}
