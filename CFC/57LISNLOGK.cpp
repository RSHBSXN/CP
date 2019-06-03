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
#define vll vector<ll>
#define vi vector<int>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<ll>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PREC 1e-9
void binarySearch(vi &LIS,int key){
    int L = 0,R = LIS.size()-1;
    while(R - L >= 1){
        int mid = (R + L) >> 1;
        if(LIS[mid] < key)
            L = mid+1;
        else if(LIS[mid] > key)
            R = mid;
        else
            return;
    }
    if(LIS[L] > key)
        LIS[L] = key;
    else if(LIS[R] > key)
        LIS[R] = key;
    else if(LIS[R] < key)
        LIS.push_back(key);
}
int main(){
    FASTIO;
    int t;
    string number;
    getline(cin,number);
    t = stoi(number);
    while(t--){
        vi LIS;
        while(getline(cin,number) && number.length() != 0){
            int num = stoi(number);
            if(LIS.size() == 0)
                LIS.push_back(num);
            else
                binarySearch(LIS,num);
        }
        cout<<"Max hits: "<<LIS.size()<<'\n';
        for(int i : LIS)
            cout<<i<<'\n';
        if(t > 0)
            cout<<'\n';
    }
}
