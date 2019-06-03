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
int binarySearch(vi ARR,int &L,int &R,int X){
    while(L <= R){
        int mid = (L + R)/2;
        if(ARR[mid] == X)
            return mid;
        else if(ARR[mid] < X)
            L = mid+1;
        else
            R = mid-1;
    }
    return -1;
}
void findKClosest(vi ARR,int L,int R,int x,int k){
    int count = 0;
    while(count < k){
        int print;
        if(L >= 0 && R < ARR.size()){
            if(abs(x - ARR[L]) <= abs(x - ARR[R])){
                print = L;
                L--;
            }
            else{
                print = R;
                R++;
            }
        }
        else if(L < 0){
            print = R;
            R++;
        }
        else{
            print = L;
            L--;
        }
        cout<<ARR[print]<<' ';
        count++;
    }
    cout<<'\n';
}
int main(){
    int n,x,k;
    cin >> n >> x >> k;
    vi ARR(n);
    for(int &i : ARR)   
        cin >> i;
    int L = 0,R = n-1;
    int ind = binarySearch(ARR,L,R,x);
    if(ind != -1){
        L = ind-1;
        R = ind+1;
    }
    else
        swap(L,R);
    findKClosest(ARR,L,R,x,k); 
}
