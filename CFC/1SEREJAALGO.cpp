/*
    Author: Rishabh Saxena
    All the best!!
    if any substring is not of form zyx,xzy,yxz then we need to 
    shuffle in it such a way that we can make it of one of those forms
    if we can arrange then it algorithm will terminate else it will run forever
    
    Now,
        string of size 3 must have three distinct characters which is x,y,z
        string of size greater than three can be
        Max occurencce - Min occurence should be less than or equal to one
        and all characters should exist
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
    string s;
    cin >> s;
    //ZYXXXXXXYYZ
    int x[s.length()] = {0},y[s.length()] = {0},z[s.length()] = {0};
    for(int i=0;i<s.length();i++){
        switch(s[i]){
            case 'x':
                x[i]++;
                break;
            case 'y':
                y[i]++;
                break;
            case 'z':
                z[i]++;
                break;
        }
        if(i != 0){
            x[i] += x[i-1];
            y[i] += y[i-1];
            z[i] += z[i-1];
        }
    }
    int n;
    cin >> n;
    while(n--){
        int l,r;
        cin >> l >> r;
        l--,r--;
        int tx = x[r],ty = y[r],tz = z[r];
        if(l > 0)
            tx -= x[l-1],ty -= y[l-1],tz -= z[l-1];
        //if subseq is less than 3
        if(r - l + 1 < 3){
            cout<<"YES";
        }
        else{
            if(tx != 0 && ty != 0 && tz != 0 && MAX(tx,ty,tz) - MIN(tx,ty,tz) <= 1){
                cout<<"YES";
            }
            else    
                cout<<"NO";
        }
        cout<<'\n';
    }
}
