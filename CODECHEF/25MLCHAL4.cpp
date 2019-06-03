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
#define vll vector<LL>
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
        int N,K;
        cin >> N >> K;
        vi ARR(N);
        for(int &i : ARR)
            cin >> i;
        int count = 0;
        for(int i=0;i<N;++i){
            int MAP[2001] = {0};
            int L = INT32_MAX,R = INT32_MIN;
            for(int j=i;j<N;++j){
                MAP[ARR[j]]++;
                LL times = 1;
                if(ARR[j] < L)
                    L = ARR[j];
                if(ARR[j] > R)
                    R = ARR[j];
                LL k = K;
                int len = j - i + 1;
                if(len < K){
                    times = K / len;
                    if((K % len) != 0)
                        times++;
                }
                LL finalLen = len * (times);
                bool goFromLeft = true;
                int X;
                if((finalLen - K + 1) <= K){
                    goFromLeft = false;
                }
                if(goFromLeft){
                    for(int x = L; x <= R;++x){
                        if(MAP[x] != 0){
                            k -= (MAP[x])*times;
                            if(k <= 0){
                                X = x;
                                break;
                            }
                        }
                    }
                }
                else{
                    k = finalLen - K + 1;
                    for(int x = R;x >= L;--x){
                        if(MAP[x] != 0){
                            k -= (MAP[x]) * times;
                            if(k <= 0){
                                X = x;
                                break;
                            }
                        }
                    }
                }
                int freq = MAP[X];
                if(MAP[freq] != 0){
                    count++;
                }
            }
        }
        cout<<count<<'\n';
    }
}
