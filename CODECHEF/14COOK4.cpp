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
#define vll vector<LL>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<LL>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MAXSIZE 100000
array<int,MAXSIZE+1> ARR;
array<int,MAXSIZE+1> PRFXK;
array<int,MAXSIZE+1> PRFXKO;
int getCount(array<int,MAXSIZE+1> &ARR,int L,int R){
    return ARR[R] - ARR[L-1];
}
int main(){
    FASTIO;
    int t;
    cin >> t;
    while(t--){
        ARR.fill(0);
        PRFXK.fill(0);
        PRFXKO.fill(0);
        int N,K;
        cin >> N >> K ;
        int n=0;
        int sum = 0;
        vector<pii> Op(N);
        for(int i=0;i<N;i++){
            int L,R;
            cin >> L >> R;
            Op[i] = {L,R};
            if(R > n)
                n = R;
            ARR[L]++;
            if(R < MAXSIZE-1)
                ARR[R+1]--;
        }
        for(int i=1;i<=n;i++){
            sum += ARR[i];
            ARR[i] = sum;
        }
        int sumK = 0,sumKO = 0;
        for(int i=1;i<=n;i++){
            if(ARR[i] == K)
                sumK++;
            else if(ARR[i] == K+1)
                sumKO++;
            PRFXK[i] += sumK;
            PRFXKO[i] += sumKO; 
        }
        int totalCakes = PRFXK[n];
        bool gotProfit = false;
        bool gotLoss = false;
        int MAXP = 0,MINL = INT32_MAX;
        for(pii &x : Op){
            int totalK = getCount(PRFXK,x.first,x.second);
            int totalKO = getCount(PRFXKO,x.first,x.second);
            if(totalK < totalKO && MAXP < (totalKO - totalK)){
                MAXP = totalKO - totalK;
                gotProfit = true;
            }
            else if(totalK >= totalKO && MINL > (totalK - totalKO)){
                MINL = totalK - totalKO;
                gotLoss = true;
            }
        }
        if(gotProfit)
            totalCakes += MAXP;
        else if(gotLoss)
            totalCakes -= MINL;
        cout<<totalCakes<<'\n';
    }
}
