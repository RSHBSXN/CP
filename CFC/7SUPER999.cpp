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
    string p;
    LL d;
    cin >> p >> d;
    LL cost = 0;
    int ind = p.length()-1;
    while(ind > 0 && cost <= d){
        if(p[ind] != '9'){
            int POW = p[ind] - '0';
            POW++;
            cost += POW * pow(10,p.length() - ind - 1); 
            if(cost > d)
                break;
            p[ind] = '9';   
            int j = ind-1;
            while(j >= 0 && p[j] == '0'){
                p[j] = '9';
                j--;
            }
            if(j >= 0)
                p[j]--;
        }
        ind--;
    }
    if(p[0] == '0')
        p = p.substr(1,p.length()-1);
    cout<<p<<'\n';
}
