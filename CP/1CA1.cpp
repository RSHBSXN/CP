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

int main(){
    int n;
    cin >> n;
    vi ARR(n);
    for(int &i : ARR)
        cin >> i;
    int pow2 = 1;
    int limit = 1;
    int count = 0;
    vector<int> A;
    for(int i=0;i<n;i++){
        A.push_back(ARR[i]);
        if(i == limit -1 || i == n-1){
            if(count & 1){
                for(int j = A.size()-1;j>=0;j--)
                    cout<<A[j]<<' ';
            }
            else{
                for(int j=0;j<A.size();j++)
                    cout<<A[j]<<' ';
            }
            pow2 *= 2;
            limit += pow2;
            A.clear();
            count++;
        }
    }  
}
