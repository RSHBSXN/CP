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
string repl(string x,char a,char b){
    string res = x;
    for(char &i : res)
        if(i == a)
            i = b;
    return res;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        string a,b;
        cin >> a >> b;  
        if(n != m)
            cout<<"NO";
        else if(a == b)
            cout<<"YES";
        else{
            bool res = true;
            unordered_map<char,vi> MAP;
            for(int i=0;i<n;++i){
                MAP[a[i]].push_back(i);
            }
            for(auto x : MAP){
                vi VECT = x.second;
                bool same = true;
                char c = b[VECT[0]];
                for(int i=0;i<VECT.size();++i){
                    if(b[VECT[i]] != c){
                        same = false;
                        break;
                    }
                }
                if(!same){
                    res = false;
                    break;
                }
            }
            cout<<((res)?"YES":"NO");
        }
        cout<<'\n';
    }
}
