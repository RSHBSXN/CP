#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define vector2 vector<vector<int>>
void DispMEMO(vector2 MEMO){
    for(int i=1;i<MEMO.size();i++){
        for(int j=1;j<MEMO.size();j++)
            cout<<MEMO[i][j]<<' ';
        cout<<'\n';
    }
}
int MinMul(vector<int> Dim){
    vector2 MEMO(Dim.size(),vector<int>(Dim.size()));
    for(int i = 1;i<Dim.size();i++){
        //No operation needed for single matrix
        MEMO[i][i] = 0;
    }
    for(int diff=1;diff<MEMO.size();diff++){
        for(int i=1;diff + i <MEMO.size();i++){
            //Here find the mininum of A[i][i+diff]
            int MIN = INT32_MAX;
            for(int k=i;k<diff+i;k++){
                MIN = min(MIN,MEMO[i][k]+MEMO[k+1][diff+i]+(Dim[i-1] * Dim[k] * Dim[i+diff]));
            }
            MEMO[i][i+diff] = MIN;
        }
    }    
    return MEMO[1][MEMO.size()-1];
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        vector<int> Dim(N);
        for(int &i : Dim)
            cin >> i;
        cout<<MinMul(Dim)<<'\n';
    }
}
