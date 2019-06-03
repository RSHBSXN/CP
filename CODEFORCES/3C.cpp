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
    FASTIO;
    int t;
    cin >> t;
    while(t--){
        unsigned int num;
        cin >> num;
        bitset<26> toBit = num;
        int count = toBit.count();
        unsigned int ones = 0;
        unsigned int comp = 0;
        for(int i=0;i<26 && ones < count;i++){
            if(toBit[i] == 1)
                ones++;
            else
                comp |= (1 << i);
        }
        if(comp == 0){
            if(ones & 1)
                comp = 1;
            else{
                
            }
        }
        else
            comp ^= num;
        cout<<comp<<'\n';
    }
}
