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
#define PREC 1e-9
int diff(char a,char b){
    if(b < a)
        swap(a,b);
    return min(b-a,(a - 'a' + 1 )+ ('z' - b));
}
int main(){
    int n,st;
    cin >> n >> st;
    st--;
    string str;
    cin >> str;
    if(str.length() == 1)
        cout<<0;
    else{
        int vert = 0,hor = 0;
        int Start[2]={-1,-1},End[2] = {-1,-1};
        int size = (n/2)-1;
        for(int i=0;i<n;++i){
            if(str[i] != str[n-1-i]){
                if(i <= size){
                    vert += diff(str[i],str[n-1-i]);
                    if(Start[0] == -1)   
                        Start[0] = i;
                    End[0] = i;
                }
                else{
                    if(Start[1] == -1)
                        Start[1] = i;
                    End[1] = i;
                }
            }
        }
        if(Start[0] == -1){
            cout<<0;
        }
        else{
            int posP;
            if(st <= size)
                posP = 0;
            else
                posP = 1;
                
            if(st <= Start[posP]){
                hor = Start[posP] - st;
                
                if(posP == 0){
                    hor = min(hor,st+1+(n-1) - End[!posP]);
                }
                else{
                    hor = min(hor,st - End[!posP]);
                }
                hor += End[posP] - Start[posP];
            }
            else if(st > Start[posP] && st < End[posP]){
                hor = End[posP] - Start[posP] + min(End[posP] - st,st - Start[posP]);
            }
            else{
                hor = st - End[posP];
                if(posP == 0)
                    hor = min(hor,Start[!posP] - st);
                else
                    hor = min(hor,(n-1) - st + 1 + Start[!posP]);
                hor += End[posP] - Start[posP];
            }
            cout<<vert+hor;
        }
    }
    cout<<'\n';
}
