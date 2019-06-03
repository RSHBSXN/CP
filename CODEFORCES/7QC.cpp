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
    MATRIX MAT(n,vi(n));
    map<int,int> MAP;
    for(int i = 0;i < n*n;++i){
        int Num;
        cin >> Num;
        MAP[Num]++;
    }
    bool notPos = false;
    bool matDone = true;
    bool hasMid = false;
    int mid = (n/2) -1;
    if(n & 1){
        hasMid = true;
        mid = n/2;
    }
    for(int i=0;i<=mid;i++){
        for(int j=0;j<=mid;j++){
            int &one = MAT[i][j],&two = MAT[n-i-1][j],&three = MAT[i][n-j-1],&four = MAT[n-i-1][n-j-1];
            int Max = MAP.begin()->first;
            int Max2 = 0;
            for(auto x : MAP){
                if(x.second > MAP[Max])
                    Max = x.first;
                if(x.second <= 2 && MAP[Max2])
                    Max2 = x.first;
            }
            if(!hasMid){
                if(MAP[Max] > 4 || MAP[Max] == 4){
                    one = Max;
                    two = Max;
                    three = Max;
                    four = Max;
                    MAP[Max] -= 4;
                    if(MAP[Max] == 0)
                        MAP.erase(Max);
                }
                else{
                    notPos = true;
                    matDone = false;
                    break;
                }
            }
            else if(i != mid && j != mid){
                if(MAP[Max] > 4 || MAP[Max] == 4){
                    one = Max;
                    two = Max;
                    three = Max;
                    four = Max;
                    MAP[Max] -= 4;
                    if(MAP[Max] == 0)
                        MAP.erase(Max);
                }
                else{
                    notPos = true;
                    matDone = false;
                    break;
                }
            }
            else{
                if(MAP[Max2] == 2){
                    Max = Max2;
                }
                if(MAP[Max] >= 4 || MAP[Max] == 2){
                    if(i == mid){
                        one = Max;
                        four = Max;
                    }
                    else if(j == mid){
                        one = Max;
                        two = Max;
                    }
                    MAP[Max] -= 2;
                    if(MAP[Max] == 0)
                        MAP.erase(Max);       
                }
                else if(MAP[Max] == 1 && i == j){
                    one = Max;
                    MAP[Max]--;
                    if(MAP[Max] == 0)
                        MAP.erase(Max);
                }
                else{
                    notPos = true;
                    matDone = false;
                    break;
                }
            }
        }
        if(notPos)
            break;
    }
    if(!matDone)
        cout<<"NO\n";
    else{
        cout<<"YES\n";        
        for(int i=0;i<n;++i){
            for(int j=0;j<n;j++)
                cout<<MAT[i][j]<<' ';
            cout<<'\n';
        }
    }
}
