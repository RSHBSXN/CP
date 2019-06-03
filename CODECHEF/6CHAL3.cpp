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
struct soldier{
    int atk,def;
};
int main(){
    FASTIO;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<soldier> S(n);
        for(int i=0;i<n;i++)
            cin >> S[i].atk;
        for(int i=0;i<n;i++)
            cin >> S[i].def;
        int shield = -1;
        for(int i=0;i<n;i++){
            int left = n-1;
            int right = 1;
            if(i == 0){
                left = n-1;
                right = 1;
            }
            else if(i == n-1){
                left = i-1;
                right = 0;
            }
            else{
                left = i-1;
                right = i+1;
            }
            if(S[i].def > (S[left].atk + S[right].atk)){
                shield = max(shield,S[i].def);
            }
        }
        cout<<shield<<'\n';
    }
}
