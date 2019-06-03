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
int main(){
    int n;
    cin >> n;
    unordered_set<int> SET;
    int count = 0;
    int MaxCount = 0;
    while(n--){
        char sign;
        int id;
        cin >> sign >> id;
        if(sign == '+'){
            SET.insert(id);
            count++;
            MaxCount = max(MaxCount,count);
        }
        else{
            if(SET.find(id) == SET.end()){
                MaxCount++;
            }
            else{
                count--;
                SET.erase(id);
            }
        }

    }
    cout<<MaxCount<<'\n';
}
