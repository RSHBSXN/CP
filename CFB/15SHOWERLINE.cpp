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
MATRIX MAT(5,vi(5));
int getMaximum(vi ARR){
    int part1 =  (MAT[ARR[0]][ARR[1]] + MAT[ARR[1]][ARR[0]]);
    int part2 =  (MAT[ARR[1]][ARR[2]] + MAT[ARR[2]][ARR[1]]);
    int part3 = 2 * (MAT[ARR[2]][ARR[3]] + MAT[ARR[3]][ARR[2]]);
    int part4 = 2 * (MAT[ARR[3]][ARR[4]] + MAT[ARR[4]][ARR[3]]);
    return part1+part2+part3+part4;
}
int getMaxPerm(vi &ARR,int index){
    if(index == ARR.size()-1){
        return getMaximum(ARR);
    }
    else{
        int Max = 0;
        for(int i=index;i<ARR.size();++i){
            swap(ARR[i],ARR[index]);
            Max = max(Max,getMaxPerm(ARR,index+1));
            swap(ARR[i],ARR[index]);
        }
        return Max;
    }
}
int main(){
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j)
            cin >> MAT[i][j];
    }
    vi ARR = {0,1,2,3,4};
    cout<<getMaxPerm(ARR,0)<<'\n';
}
