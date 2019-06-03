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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<string> Outside,Inside;
    string word;
    bool inBrack = false;
    int maxLen = 0,brackWords=0;
    for(int i=0;i<n;++i){
        if(s[i] == '_' || s[i] == '('){
            if(word.length() > 0){
                if(inBrack)
                    brackWords++;
                else{
                    maxLen = max(maxLen,(int)word.length());
                }
            }
            word = "";
            if(s[i] == '(')
                inBrack = true;
        }
        else if(s[i] == ')'){
            inBrack = false;
            if(word.length() > 0)
                brackWords++;
            word = "";
        }
        else{
            word += s[i];
        }
    }
    if(word.length() > 0)   
        maxLen = max(maxLen,(int)word.length());
    
    cout<<maxLen<<' '<<brackWords<<'\n';
}
