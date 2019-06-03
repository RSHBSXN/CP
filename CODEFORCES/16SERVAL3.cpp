#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define xll __int128
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<ll>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    string res;
    if(n & 1)
        res = ":(";
    else{
        if(s[0] == ')' || s[n-1] == '(')
            res = ":(";
        else{
            int bal = 0,canIn =  (n/2) - 1;
            s[0] = '(';
            s[n-1] = ')';
            for(int i=1;i<n-1;++i){
                if(s[i] == '(')
                    canIn--;
            }
            if(canIn < 0){
                res = ":(";
            }
            else{
                bool valid = true;
                for(int i=1;i<n-1;++i){
                    if(s[i] == '(')
                        bal++;
                    else if(s[i] == ')')
                        bal--;
                    else{
                        if(canIn > 0){
                            s[i] = '(';
                            bal++;
                            canIn--;
                        }
                        else{
                            s[i] = ')';
                            bal--;
                        }
                    }
                    if(bal < 0){
                        valid = false;
                        res = ":(";
                        break;
                    }
                }
                if(valid)
                    res = s;
            }
        }
    }
    cout<<res<<'\n';
}
