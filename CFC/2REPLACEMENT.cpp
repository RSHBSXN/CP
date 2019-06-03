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
string s;
void op(int n,int left,int right,int &totalSegs,bool isDot){
    if(left >= 0 && right < n){
        if(s[left] == '.' && s[right] == '.'){
            (isDot)?totalSegs--:totalSegs++;
        }
        else if(s[left] != '.' && s[right] != '.'){
            (isDot)?totalSegs++:totalSegs--;
        }
    }
    else if(left == -1 && s[right] != '.' || right == n && s[left] != '.'){
        (isDot)?totalSegs++:totalSegs--;
    }
}
int main(){   
    FASTIO;
    int n,m;
    cin >> n >> m;
    cin >> s;
    bool inSeg = false;
    int totalDots = 0,totalSegs = 0;
    for(char c : s){
        if(c == '.'){
            if(!inSeg){
                inSeg = true;
                totalSegs++;
            }
            totalDots++;
        }
        else if(inSeg){
            inSeg = false;
        }
    }
    while(m--){
        int ind;
        char c;
        cin >> ind >> c;
        ind--;
        int left = ind -1;
        int right = ind + 1;
        if(c == '.' && s[ind] != '.'){
            if(n > 1)
                op(n,left,right,totalSegs,true);
            else
                totalSegs++;
            totalDots++;
        }
        else if(c != '.' && s[ind] == '.'){
            if(n > 1)
                op(n,left,right,totalSegs,false);
            else
                totalSegs--;
            totalDots--;
        }
        cout<<totalDots - totalSegs<<'\n';
        s[ind] = c;
    }
}
