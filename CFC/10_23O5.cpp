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
bool SEL[5] = {false};
bool backtrack(vi ARR,int result,int count){
    if(count == 5){
        return result == 23;
    }
    else{
        for(int i=0;i<5;i++){
            if(!SEL[i]){
                SEL[i] = true;
                bool add = backtrack(ARR,result + ARR[i],count+1);
                bool sub = backtrack(ARR,result - ARR[i],count+1);
                bool mul = backtrack(ARR,result * ARR[i],count + 1);
                if(add || sub || mul)
                    return true;
                else{
                    SEL[i] = false;
                }
            }
        }
        return false;
    }
}
int main(){
    FASTIO;
    int a,b,c,d,e;
    while(cin >> a >> b >> c >> d >> e && a != 0){
        vi ARR = {a,b,c,d,e};
        bool found23 = false;
        for(int i=0;i<5;i++){
            SEL[i] = true;
            if(backtrack(ARR,ARR[i],1)){
                found23 = true;
                break;
            }
            SEL[i] = false;
        }
        cout<<((found23)?"Possible":"Impossible")<<'\n';
        for(int i = 0;i<5;i++)
            SEL[i] = false;
    }
}