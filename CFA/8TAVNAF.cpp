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
unordered_map<char,pair<string,string>> FACE = {{'0',{"zero","ten"}},{'1',{"one","eleven"}},{'2',{"two","twelve"}},{'3',{"three","thir"}},{'4',{"four","four"}},{'5',{"five","fif"}},{'6',{"six","six"}},{'7',{"seven","seven"}},{'8',{"eight","eigh"}},{'9',{"nine","nine"}}};
unordered_map<char,string> PLACE = {{'2',"twenty"},{'3',"thirty"},{'4',"forty"},{'5',"fifty"},{'6',"sixty"},{'7',"seventy"},{'8',"eighty"},{'9',"ninety"}};
    
string getNumber(string num){
    string res;
    if(num.length() == 1){
        res = FACE[num[0]].first;
    }
    else{
        if(num[0] == '1'){
            res = FACE[num[1]].second;
            if(num[1] > '2')
                res += "teen";
        }
        else{
            res = PLACE[num[0]];
            if(num[1] > '0')
                res += "-" + FACE[num[1]].first;
        }
    }
    return res;
}
int main(){
    string num;
    cin >> num;
    cout<<getNumber(num)<<'\n';
}
