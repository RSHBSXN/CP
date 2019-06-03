/*
    Author: Rishabh Saxena
    All the best!!
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define xll __int128
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define vi vector<int>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<ll>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
vi res;
bool isPossible(vector<pii> &Schedule,int day,int totalTime){
    if(totalTime == 0 && day == Schedule.size()){
        return true;
    }
    else if(totalTime < 0)
        return false;
    else{
        for(int i=Schedule[day].first;i<=Schedule[day].second;++i){
            if(i > totalTime)
                return false;
            else{
                if(isPossible(Schedule,day+1,totalTime - i)){
                    res[day] = i;
                    return true;
                }
            }
        }
        return false;
    }
}
int main(){
    FASTIO;
    int d,Sum;
    cin >> d >> Sum;
    res = vi(d,0);
    vector<pii> Schd(d);
    int maxS=0,minS=0;
    for(int i=0;i<d;++i){
        cin >> Schd[i].first >> Schd[i].second;
        maxS += Schd[i].second;
        minS += Schd[i].first;
    }
    if(minS > Sum || maxS < Sum){
        cout<<"NO";
    }
    else if(isPossible(Schd,0,Sum)){
        cout<<"YES\n";
        for(int i=0;i<d;++i)
            cout<<res[i]<<' ';
    }
    cout<<'\n';
}
