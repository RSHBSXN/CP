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
struct Time{
    int t[2];
    int minutes;
    void calMin(){
        minutes = (t[0] * 60) + t[1];
    }
};
int main(){
    Time t1,t2;
    string scan;
    getline(cin,scan);
    stringstream sin(scan);
    for(int i=0;i<2;++i){
        getline(sin,scan,':');
        t1.t[i] = stoi(scan);
    }
    getline(cin,scan);
    sin = stringstream(scan);
    for(int i=0;i<2;++i){
        getline(sin,scan,':');
        t2.t[i] = stoi(scan);
    }
    t1.calMin();
    t2.calMin();
    int result = (t2.minutes - t1.minutes)/2;
    int hr = result / 60;
    int min = result % 60;
    t1.t[0]  = (t1.t[0] + hr)%24;
    t1.t[1] = (t1.t[1] + min);
    if(min != 0 && t1.t[1] % 60 == 0){
        t1.t[1] = 0;
        t1.t[0] = (t1.t[0] + 1)%24;
    }
    for(int i=0;i<2;++i){
        cout<<((t1.t[i] <10)?"0":"")<<t1.t[i];
        if(i < 1)
            cout<<':';
    }
    cout<<'\n';
}
