/*
    Author: Rishabh Saxena
    All the best!!
    Search the number in sorted rotated array
        
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
int binarySearch(vi ARR){
    int left = 0,right = ARR.size()-1;
    while(right - left > 1){
        int mid = (left + right)/2;
        if(ARR[mid] >= ARR[0])
            left = mid;
        else
            right = mid-1;
    }
    if(ARR[left] >= ARR[right])
        return left;
    else
        return right;
}
int binarySearch(vi ARR,int L,int R,int k){
    while(L <= R){
        int mid = (L + R)/2;
        if(ARR[mid] == k)
            return mid;
        else if(ARR[mid] > k)
            R = mid - 1;
        else
            L = mid + 1;
    }
    return -1;
}
int main(){
    int N,k;
    cin >> N >> k;
    vi ARR(N);
    for(int &i : ARR)
        cin >> i;
    int pivot = binarySearch(ARR);
    int left = binarySearch(ARR,0,pivot,k);
    if(left != -1)
        cout<<left;
    else{
        cout<<binarySearch(ARR,pivot+1,ARR.size()-1,k);
    }
    cout<<'\n';
}
