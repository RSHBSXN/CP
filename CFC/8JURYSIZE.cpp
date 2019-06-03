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
/*
    0:2012
    1:2013
    0:jan
    1:feb
    ...
    11:dec
    max 31 days
    for feb 28
*/
int dayMon[12] ={31,28,31,30,31,30,31,31,30,31,30,31};
int YMD[2][12][32];
void sub(int &day,int &month,int &year){
    if(day == 1){
        if(month == 0){
            year--;
            month = 11;
        }
        else    
            month--;
        day = dayMon[month];
    }
    else
        day--;
}
int main(){
    int q;
    fstream fin("input.txt",ios::in);
    fstream fout("output.txt",ios::out);
    fin >> q;
    while(q--){
        int year = 1;
        int olymMon,olymDat,memb,workDays;
        fin >> olymMon >> olymDat >> memb >> workDays;
        olymMon--;
        int days = 0;
        while(days < workDays){
            sub(olymDat,olymMon,year);
            YMD[year][olymMon][olymDat] += memb;
            days++;
        }
    }
    int maxJury = 0;
    for(int i=0;i<2;i++){
        for(int j=0;j<12;j++){
            for(int k=1;k<32;k++){
                maxJury = max(maxJury,YMD[i][j][k]);
            }
        }
    }
    fout<<maxJury<<'\n';
    fin.close();
    fout.close();
}
