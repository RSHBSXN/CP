#include <bits/stdc++.h>
using namespace std;
map<int,int> Numbers;
int XOR(){
    map<int,int> :: iterator itr = Numbers.begin();
    int Xor = 0;
    for(int i=1;i<=4;i++,itr++){
        Xor ^= itr->first;
    }
    return Xor;
}
int getMax(){
    map<int,int> :: iterator itr = Numbers.begin();
    int Max = 0;
    for(int i=1;i<=4;i++,itr++){
        Max = max(Max,itr->first);
    }
    return Max;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> ARR(n);
        for(int &x : ARR)
            cin >> x;
        for(int i=0;i<4;i++)
            Numbers[ARR[i]]++;
        int MaxXor = XOR(),l=0,r=3;
        vector<int> VECT;
        for(int i=0,j=3;j<n;i++,j++){
            int Xor = XOR();
            if(Xor > MaxXor){
                if(VECT.size() > 0)
                    VECT.clear();
                else
                    VECT.push_back(i);
                MaxXor = Xor;
                l = i,j = i+3;
            }
            else if(Xor == MaxXor){
                VECT.push_back(i);
            }
            if(j+1 < n)
                Numbers[ARR[j+1]]++;
            Numbers[ARR[i]]--;
            if(Numbers[ARR[i]] == 0)
                Numbers.erase(ARR[i]); 
        }
        cout<<VECT[0]<<'\n';
    }
}
