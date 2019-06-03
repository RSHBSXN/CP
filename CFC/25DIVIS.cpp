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
vi arr;
vector<unordered_map<LL,bool>> MEMO;
bool div(int index,int K,LL res){
    if(index == arr.size())
            return res == 0;
    else if(MEMO[index].find(res) == MEMO[index].end()){
        bool &ref = MEMO[index][res];
        bool add = false,sub = false;
        add = div(index+1,K,((res + arr[index])% K));
        if(!add){
            sub = div(index+1,K, ((res - arr[index])% K + K ) % K );
        }
        ref =  add || sub;
        return ref;
    }
    else
        return MEMO[index][res];
}
int main(){
    FASTIO;
    int n;
    cin >> n;
    while(n--){
        int size,K;
        cin >> size >> K;
        arr.resize(size);
        MEMO.resize(size);
        for(int &i : arr)
            cin >> i;
        bool ans = div(1,K,(arr[0])%K);
        cout<<((ans)?"Divisible":"Not divisible")<<'\n';
        arr.clear();
        MEMO.clear();
    }
}