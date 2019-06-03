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
#define vi vector<int>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<ll>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
vi val(10);
int Max,Min;
vector<pair<int,int>> Numbers;
void build(){
    /*
            0
        1       5
            6
        2       4
            3
    */

    val[0] = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
    val[1] = (1 << 5) | (1 << 4);
    val[2] = (1 << 0) | (1 << 5) | (1 << 6) | (1 << 2) | (1 << 3);
    val[3] = (1 << 0) | (1 << 5) | (1 << 6) | (1 << 4) | (1 << 3);
    val[4] = (1 << 1) | (1 << 6) | (1 << 5) | (1 << 4);
    val[5] = (1 << 0) | (1 << 1) | (1 << 6) | (1 << 4) | (1 << 3);
    val[6] = (1 << 0) | (1 << 1) | (1 << 6) | (1 << 4) | (1 << 3) | (1 << 2);
    val[7] = (1 << 0) | (1 << 5) | (1 << 4);
    val[8] = 127;
    val[9] = 123;
}
void solve(int state){
    //State can only be possible if it can be true for all tests which are mentioned in the question 
    for(int i=0;i<Numbers.size();++i){
        int onCount = 0;
        int digit = Numbers[i].first;
        for(int j=0;j<7;++j){
            //if that segment is lit in idle condition and is also lit on testing
            if((val[digit] & (1 << j)) && (state & (1 << j)))
                onCount++;
        }
        //If number of segments which are on is not equal to the segments which are on in testing part then the state is not possible 
        if(onCount != Numbers[i].second)
            return;
    }
    //If control comes here that means this state is valid and can be attained by all conditions described in Numbers array
    // Now check how many segments are working
    int working = 0;
    for(int i = 0;i<7;++i){
        if(state & (1 << i))
            working++;
    }
    //Non working segments will be total - working
    Min = min(Min,7 - working);
    Max = max(Max,7 - working);
    return;
}
int main(){
    int t;
    cin >> t;
    build();
    while(t--){
        int n;
        cin >> n;
        Numbers = vector<pair<int,int>>(n);
        for(int i=0;i<n;++i){
            cin >> Numbers[i].first >> Numbers[i].second;
        }
        Max = 0,Min = 8;
        //Check all possible states that can happen
        for(int i=0;i<=127;++i){
            solve(i);
        }
        if(Min != 8)
            cout<<Min<<' '<<Max;
        else
            cout<<"invalid";
        cout<<'\n';
    }
}
