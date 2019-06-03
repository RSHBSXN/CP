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
vector<int> MEMO;
int minSmoke(vi &arr,int h,int i,int j,int smoke){
    if(i == arr.size())
        return smoke;
    else{
        if(MEMO[i] == -1){
            int &ref = MEMO[i];
            int val = arr[i] + arr[h];
            int leftSmoke= arr[i] * arr[h];
            arr[i] = val%100;
            leftSmoke = minSmoke(arr,i,j,j+1,smoke + leftSmoke);
            arr[i] = val - arr[h];
            if(j < arr.size()){
                val = arr[i] + arr[j];
                int del = arr[j];
                int rightSmoke = arr[i] * arr[j];
                arr[i] = val%100;
                rightSmoke = minSmoke(arr,h,i,j+1,smoke + rightSmoke);
                arr[i] = val - del;
                ref =  min(leftSmoke,rightSmoke);
            }
            ref =  leftSmoke;
            return ref;
        }
        else
            return MEMO[i];
    }
}
int main(){
    int n;
    while(cin >> n){
        MEMO.resize(n,-1);
        vi arr(n);
        for(int &i : arr)
            cin >> i;
        cout<<minSmoke(arr,0,1,2,0)<<'\n';
        MEMO.clear();
    }
}
