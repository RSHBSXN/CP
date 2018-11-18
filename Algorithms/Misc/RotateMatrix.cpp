#include <iostream>
#include <vector>
using namespace std;
#define vector2 vector<vector<int>>
void stateIncrement(int state,int &i,int &j){
    switch(state){
        case 0:
            j++;
            break;
        case 1:
            i++;
            break;
        case 2:
            j--;
            break;
        case 3:
            i--;
            break;
    }
}
bool stateUpd(int state,int &i,int &j,int &L,int &R,int &T,int &B){
    bool chk = false;
    switch(state){
        case 0:
            if(j == R){
                T++;
                chk = true;
            }
            break;
        case 1:
            if(i == B){
                R--;
                chk = true;
            }
            break;
        case 2:
            if(j == L){
                B--;
                chk = true;
            }
            break;
        case 3:
            if(i == T){
                L++;
                chk = true;
            }
            break;
    }
    return chk;
}

void Rotate(int dir,vector2 &MAT,vector2 &RES){
    int stateM,stateR;
    int L = 0,R = MAT[0].size()-1,T = 0,B = MAT.size()-1;
    int LR = 0,RR = RES[0].size()-1,TR = 0,BR = RES.size()-1;
    int i,j,iR = 0,jR = 0;
    if(dir == 1){
        stateM = 3;
        stateR = 0;
        i = B;
        j = 0;
    }
    else if(dir == 0){
        stateM = 1;
        stateR = 0;
        i = 0,j = R;   
    }
    while(L <= R && T <= B){
        RES[iR][jR] = MAT[i][j];
        stateIncrement(stateM,i,j);
        if(stateUpd(stateM,i,j,L,R,T,B)){
            stateM = ((stateM + 1) % 4);
        }
        stateIncrement(stateR,iR,jR);
        if(stateUpd(stateR,iR,jR,LR,RR,TR,BR)){
            stateR = (stateR + 1) % 4;    
        }  
    }
    RES[iR][jR] = MAT[i][j];
}
int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> MAT(N,vector<int>(M));
    vector<vector<int>> RMAT(M,vector<int>(N));
    for(vector<int> &a : MAT){
        for(int &x : a)
            cin >> x;
    }
    int dir;
    cin >> dir;
    Rotate(dir,MAT,RMAT);
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cout<<RMAT[i][j]<<'\t';
        }
        cout<<'\n';
    }    
}
