// /*
//     Author: Rishabh Saxena
//     All the best!!
// */
// #include <bits/stdc++.h>
// using namespace std;
// #define ULL unsigned long long
// #define LL long long
// #define XLL __int128
// #define pii pair<int,int>
// #define pll pair<LL,LL>
// #define vi vector<int>
// #define vll vector<LL>
// #define MATRIX vector<vector<int>>
// #define MATRIXB vector<vector<bool>>
// #define MATRIXC vector<vector<char>>
// #define MATRIXLL vector<vector<LL>>
// #define MATRIX3D vector<vector<vector<int>>>
// #define MAX(A,B,C) max(A,max(B,C))
// #define MIN(A,B,C) min(A,min(B,C))
// #define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
// #define MOD 1000000007
// inline int Count(vector<int> ARR,vector<bool> VIS,int index){
//     if(index == ARR.size()){
//         return 0;
//     }
//     else{
//         if(VIS[index]){
//             return 0;
//         }
//         else{
//             VIS[index] = true;
//             int count = 1;
//             if(ARR[index] == 1){
//                 if(index-1 >= 0 && !VIS[index-1])
//                     count = (count + Count(ARR,VIS,index-1))%MOD;
//                 if(index+1 < ARR.size() && !VIS[index+1])
//                     count = (count + Count(ARR,VIS,index+1))%MOD;
//             }
//             else{
//                 for(int i=1;i<=2;i++){
//                     if(index-i >= 0 && !VIS[index-i])
//                         count = (count + Count(ARR,VIS,index-i))%MOD;
//                     if(index+i < ARR.size() && !VIS[index+i])
//                         count = (count + Count(ARR,VIS,index+i))%MOD;
//                 }
//             }
//             return count;
//         }
//     }
// }
// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int N;
//         cin >> N;
//         vi ARR(N);
//         vector<bool> VIS(N,false);
//         for(int i=0;i<N;++i){
//             cin >> ARR[i];
//         }
//         cout<<Count(ARR,VIS,0)<<'\n';
//     }
// }
#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
#define LL long long
#define XLL __int128
#define pii pair<int,int>
#define pll pair<LL,LL>
#define vi vector<int>
#define vll vector<LL>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<LL>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MOD 1000000007
int Operation(int N){   
    if(N > 0){
        if(N & 1)
            return 1 + Operation(N-1);
        else
            return 1 + Operation(N/2);   
    }
    else
        return 0;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        cout<<Operation(N)<<'\n';
    }
}