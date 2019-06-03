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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ind = s.find('G');
    int indT = s.find('T');
    bool canEat = true;
    if(abs(indT - ind) % k != 0){
        cout<<"NO\n";
    }
    else{
        bool reachable = true;
        int dir = (ind < indT)?1:-1;
        for(int i=ind +(k * dir);i != indT;i += (k*dir)){
            if(s[i] == '#'){
                reachable = false;
                break;
            }
        }
        cout<<((reachable)?"YES":"NO")<<'\n';
    }
}
