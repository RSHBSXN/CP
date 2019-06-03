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
#define vi vector<int>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<ll>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
int main(){
    FASTIO;
    int t;
    cin >> t;
    while(t--){
        unordered_set<int> VIS;
        int n,X;
        cin >> n >> X;
        int disCount = 1;
        VIS.insert(X);
        string move;
        cin >> move;
        for(char i : move){
            if(i == 'L'){
                if(VIS.find(X-1) == VIS.end()){
                    VIS.insert(X-1);
                    disCount++;
                }
                X--;
            }
            else if(i == 'R'){
                if(VIS.find(X+1) == VIS.end()){
                    VIS.insert(X+1);
                    disCount++;
                }
                X++;
            }
        }
        cout<<disCount<<'\n';

    }
}
