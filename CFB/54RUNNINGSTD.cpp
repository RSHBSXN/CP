/*
    Author: Rishabh Saxena
    All the best!!
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
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
ld dist(pll A,pll B){
    ld a = A.first - B.first;
    ld b = A.second - B.second;
    return sqrt((a*a) + (b*b));
}
int main(){
    FASTIO;
    ld n,vs,vb;
    cin >> n >> vb >> vs;
    vector<ld> arr(n);
    for(ld &i : arr)
        cin >> i;
    pair<ld,ld> d;
    cin >> d.first >> d.second;
    ld minTime = INT32_MAX;       
    ld minDist = INT32_MAX;
    int ind = -1;
    for(int i=1;i<n;++i){
        ld busTime = arr[i]/vb;
        ld stopToSchool = dist({arr[i],0},d); 
        ld walkTime = stopToSchool/vs;
        ld Time = busTime + walkTime;
        if(Time < minTime){
            minTime = Time;
            ind = i+1;
            minDist = stopToSchool;
        }
        else if(Time == minTime && stopToSchool < minDist){
            ind = i+1;
            minDist = stopToSchool;
        }
    }
    cout<<ind<<'\n';
}
