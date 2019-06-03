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
int main(){
    string s,t;
    cin >> s >> t;
    int diff = 0;
    for(int i=0;i<s.length();++i){
        diff += s[i] != t[i];
    }
    if(diff & 1) 
        cout<<"impossible";
    else{
        string res(s.length(),'0');
        bool firstTurn = true;
        for(int i=0;i<s.length();++i){
            if(s[i] != t[i]){
                if(firstTurn){
                    res[i] = s[i];
                }
                else
                    res[i] = t[i];
                firstTurn = !firstTurn;
            }
        }
        cout<<res;
    }
    cout<<'\n';
}
