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
    int len;
    cin >> len;
    string s;
    cin >> s;
    bool lucky = true;
    int sumL = 0,sumR = 0;
    for(int i=0;i<len;i++){
        if(s[i] != '4' && s[i] != '7'){
            lucky = false;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
            break;
        }
        if(i < len/2){
            sumL += s[i] - '0';
        }
        else
            sumR += s[i] - '0';
    }
    if(lucky && sumL == sumR)
        cout<<"YES";
    else
        cout<<"NO";
    cout<<'\n';
}
