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
    int b,k;
    cin >> b >> k;
    bool radOdd = b & 1;
    int oddCount = 0;
    for(int i=k-1;i>=0;i--){
        int num;
        cin >> num;
        if(i > 0 && radOdd && (num & 1)){
            oddCount++;
        }
        else if(i == 0 && (num & 1))
            oddCount++;
    }
    if((oddCount & 1) != 0)
        cout<<"odd";
    else
        cout<<"even";
    cout<<'\n'; 
}
