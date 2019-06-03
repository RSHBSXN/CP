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
inline vector<int> Factors(int num){
    vector<int>fact;
    for(int i=1;i*i<=num;i++){
        if(num % i == 0){
            if(i <= 26)
                fact.push_back(i);
            else
                break;
        }
    }
    return fact;
}
int findMoves(vector<int> &S,int d,int N){
    if(d > 26)  
        return INT32_MAX;
    else{
        int dist = S.size();
        int count = 0;
        if(d >= dist){
            int d2 = N/d;
            for(int i=0;i<dist;i++){
                if(S[i] > d2){
                    count += S[i] - d2;
                }   
            }

        }
        else if(d < dist){
            int i;
            int d2 = N/d;
            int dst = dist;
            for(i=0;d < dst;i++){
                count += S[i];
                dst--;
            }
            for(;i<dist;i++){
                if(S[i] > d2)
                    count += S[i] - d2;
            }
        }
        return count;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int minMoves = INT32_MAX;
        int N = s.length();
        vector<int> Fact = Factors(N);
        vector<int> S;
        unordered_map<char,int> Count;
        for(char x : s)
            Count[x]++;
        for(auto &x : Count){
            S.push_back(x.second);
        }

        sort(S.begin(),S.end());
        int dist = S.size();
        for(int i=0;i<Fact.size();i++){
            int one=0,two=0;
            one = findMoves(S,Fact[i],N);
            two = findMoves(S,N/Fact[i],N);
            minMoves = MIN(minMoves,one,two);
        }
        cout<<minMoves<<'\n';
    }
}
