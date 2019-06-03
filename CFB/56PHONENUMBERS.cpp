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
//XX-XX-XX
int Type(string s){
    bool dec = true;
    bool same = true;
    char c = s[0];
    for(int i=1;i<s.length();++i){
        if(i != 2 && i != 5){
            if(c != s[i])
                same = false;
            if(c <= s[i])
                dec = false;
            else
                c = s[i];
        }
    }
    if(same)    
        return 0;
    else if(dec)
        return 1;
    else 
        return 2;
}
void disp(MATRIX &DETAILS,vector<string> &Name,int ind,int Max){
    bool first = true;
    for(int i=0;i<DETAILS.size();++i){
        if(DETAILS[i][ind] == Max){
            if(!first){
                cout<<",";
            }
            cout<<" ";
            first = false;
            cout<<Name[i];
            
        }
    }
    cout<<".\n";
}
int main(){
    FASTIO;
    int n;
    cin >> n;
    vector<string> Name(n);
    MATRIX DETAILS(n,vi(3,0));//0-taxi,1-pizza,2-girls
    int Max[3] = {0,0,0};
    for(int i=0;i<n;++i){
        int numbers;
        cin >> numbers >> Name[i];
        for(int j=0;j<numbers;++j){
            string phn;
            cin >> phn;
            int type = Type(phn);
            DETAILS[i][type]++;
            Max[type] = max(Max[type],DETAILS[i][type]);
        }
    }
    cout<<"If you want to call a taxi, you should call:";
    disp(DETAILS,Name,0,Max[0]);
    cout<<"If you want to order a pizza, you should call:";
    disp(DETAILS,Name,1,Max[1]);
    cout<<"If you want to go to a cafe with a wonderful girl, you should call:";
    disp(DETAILS,Name,2,Max[2]);

}
