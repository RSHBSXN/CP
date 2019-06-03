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

void removeNotCommon(unordered_map<char,int> &MAP1,unordered_map<char,int> &MAP2){
    string del;
    for(auto &x : MAP1){
        if(MAP2.find(x.first) == MAP2.end())
            del += x.first;
    }
    for(char x : del)
        MAP1.erase(x);
}
int main(){
    FASTIO;
    int t;
    cin >>  t;
    while(t--){
        int n;
        cin >> n;
        vector<string> Str(n);
        for(int i=0;i<n;i++)
            cin >> Str[i];
        unordered_map<char,int> MMAP;
        for(char c : Str[0]){
            MMAP[c]++;
        }
        for(int i=1;i<n;i++){
            unordered_map<char,int> MAP;
            for(char x : Str[i])
                MAP[x]++;
            removeNotCommon(MMAP,MAP);
        }
        cout<<MMAP.size()<<'\n';   
    }
}
