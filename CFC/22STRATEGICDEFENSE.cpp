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
//Longest Increaing subsequence
vector<int> ARR;
pair<int,string> LIS(){
    pair<int,string> DP[ARR.size()];
    for(int i=0;i<ARR.size();i++){
        string r(ARR.size(),'0');
        r[i] = '1';
        DP[i] = {1,r};
    }
    pair<int,string> Max;
    Max.first = 0;
    for(int i=1;i<ARR.size();i++){
        for(int j=0;j<i;j++){
            if(ARR[i] > ARR[j]){
                pair<int,string> t = DP[j];
                DP[i].first = t.first + 1;
                t.second[i] = '1';
                DP[i].second = t.second;              
                if(DP[i].first > Max.first){
                    Max = DP[i];
                }  
            }
        }
    }
    return Max;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        while(n--){
            int num;
            cin >> num;
            ARR.push_back(num);
        }
        pair<int,string> res = LIS();
        cout<<res.first<<'\n';
        for(int i=0;i<ARR.size();i++){
            if(res.second[i] == '1'){
                cout<<ARR[i]<<'\n';
            }
        }
    }
}