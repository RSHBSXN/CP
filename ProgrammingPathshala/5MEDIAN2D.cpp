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
int binarySearch(vi &ARR,int K){
    int L = 0;
    int R = ARR.size()-1;
    while(R - L > 1){
        int mid = (L + R)/2;
        if(ARR[mid] < K)
            L = mid;
        else
            R = mid-1;
    }
    if(ARR[R] < K)
        return R+1;
    else if(ARR[L] < K) 
        return L+1;
    else
        return 0;
}
int binarySearch(vi &ARR,int K,bool low){
    int l = 0,r = ARR.size()-1;
    while(r - l > 1){
        int mid = (r + l)/2;
        if(ARR[mid] < K){
            l = mid+1;
        }
        else if(ARR[mid] > K)
            r = mid-1;
        else{
            if(low)
                r = mid;
            else
                l = mid;
        }
    }
    if(!low)
        swap(l,r);
    if(ARR[l] == K)
        return l;
    else if(ARR[r] == K)
        return r;
    else 
        return -1;
}
int main(){
    int n,m;
    cin >> n >> m;
    MATRIX MAT(n,vi(m));
    int Min = INT32_MAX,Max = INT32_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;++j){
            cin >> MAT[i][j];
            Max = max(MAT[i][j],Max);
            Min = min(MAT[i][j],Min);
        }
    }
    int l = Min,r = Max;
    bool median = false;
    int med = -1;
    while(!median){
        int mid = (l + r)/2;
        int less = 0,equal = 0;
        for(int i=0;i<n;++i){
            less += binarySearch(MAT[i],mid);
            int eq = binarySearch(MAT[i],mid,false) - binarySearch(MAT[i],mid,true);
            if(eq != 0)
                eq++;
            equal += eq;
        }
        int part = (n * m)/2;
        if((less == part)||(less < part && less + equal >= part)){
            med = mid;
            median = true;
        }
        else if(less < part)
            l = mid+1;
        else if(less > part)
            r = mid-1;
    }
    cout<<(l + r)/2<<'\n';
}
