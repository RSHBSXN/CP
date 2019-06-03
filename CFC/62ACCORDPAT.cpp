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
#define PREC 1e-9
struct card{
    char face,suit;
};
bool hasCommon(card a,card b){
    return a.face == b.face || a.suit == b.suit;
}
vector<stack<card>> PILE(52);
// bool arrange(card a,int index,int &newInd){
//     int one = index-3;
//     int two = index-1;
//     if(one >= 0 && !PILE[one].empty() && hasCommon(a,PILE[one].top())){
//         if(!arrange(a,one,newInd)){
//             newInd = one;
//             PILE[one].push(a);
//         }
//         return true;
//     }
//     else if(two >= 0 && !PILE[two].empty() && hasCommon(a,PILE[two].top())){
//         if(!arrange(a,two,newInd)){
//             newInd = two;
//             PILE[two].push(a);
//         }
//         return true;
//     }
//     else
//         return false;
// }
bool canShift(int &size,int &ind){
    bool found = false;
    for(int i=0;i<=ind;++i){
        int one = i-3;
        int two = i-1;
        if(one >= 0 && hasCommon(PILE[i].top(),PILE[one].top())){
            PILE[one].push(PILE[i].top());
            PILE[i].pop();
            if(PILE[i].empty()){
                PILE.erase(PILE.begin()+i);
                size--;
                ind--;
            }
            return true;
        }
        if(two >= 0 && hasCommon(PILE[i].top(),PILE[two].top())){
            PILE[two].push(PILE[i].top());
            PILE[i].pop();
            if(PILE[i].empty()){
                PILE.erase(PILE.begin()+i);
                size--;
                ind--;
            }
            return true;
        }
    }
    return false;
}
// void recur(int index,int &size,int &i){
//     int one = index+1;
//     int two = index+3;
//     if(one < PILE.size() && !PILE[one].empty() && hasCommon(PILE[one].top(),PILE[index].top())){
//         PILE[index].push(PILE[one].top());
//         PILE[one].pop();
//         if(PILE[one].empty()){
//             PILE.erase(PILE.begin()+one);
//             size--;
//             i--;
//         }
//         recur(index,size,i);
//     }
//     else if(two < PILE.size() && !PILE[two].empty() && hasCommon(PILE[two].top(),PILE[index].top())){
//         PILE[index].push(PILE[two].top());
//         PILE[two].pop();
//         if(PILE[two].empty()){
//             PILE.erase(PILE.begin()+two);
//             size--;
//             i--;
//         }
//         recur(index,size,i);
//     }
// }
int main(){
    FASTIO;
    string str;
    while(cin >> str && str != "#"){
        PILE = vector<stack<card>>(52);
        PILE[0].push({str[0],str[1]});
        int size = 52;
        for(int i=1;i<size;++i){
            card c;
            cin >> c.face >> c.suit;
            PILE[i].push(c);
            while(canShift(size,i));
        }
        cout<<size<<" "<<((size > 1)?"piles":"pile")<<" remaining: ";
        for(int i=0;i<size;++i){
            cout<<PILE[i].size();
            if(i != size-1)
                cout<<' ';
        }
        cout<<'\n';
    }
}
