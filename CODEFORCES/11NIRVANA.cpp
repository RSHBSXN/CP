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
ll getMul(string s){
    ll mul = 1;  
    for(char x : s)
        mul *= x - '0';
    return mul;
}
int main(){
    
    string s;
    cin >> s;
    ll one = getMul(s);
    if(s.length() == 1)
        cout<<one;
    else{
        ll Max = one;
        string s2 = s;
        for(int i = s2.length()-1;i>0;){
            s2[i] = '9';
            int j = i-1;
            while(j > 0 && s2[j] == '0'){
                s2[j] = '9';
                j--;
            }
            if(j >= 0){
                s2[j]--;
                i = j;
                if(j == 0 && s2[j] == '0')
                    s2 = s2.substr(1,s2.length()-1);
            }
            Max = max(Max,getMul(s2));   
        } 
        cout<<Max;
    }
    cout<<'\n';
}
