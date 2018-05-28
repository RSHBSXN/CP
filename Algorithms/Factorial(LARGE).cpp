#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//int &viraj = abhiraj;
void facto(int n,vector<int> &digs){
    for(int i=1;i<=n;i++){
        if(i == 1){
            digs = {1};
        }
        else{
            unsigned long long carr = 0;
            int rem = 0;
            for(int j=0;j<digs.size();j++){
                unsigned long long num = digs[j] * i + carr;
                rem = num % 10;
                carr = num / 10;
                digs[j] = rem;
            }
            while(carr != 0){
                digs.push_back(carr%10);
                carr /= 10;
            }
            
            //cout<<endl;
        }
    }
    /*for(int c : digs){
                cout<<c<<' ';
            }
            cout<<endl;
*/}
string factorial(int factorial){
    vector<int>Digs;
    facto(factorial,Digs);
    reverse(Digs.begin(),Digs.end());
    string result("");
    for(int dig : Digs){
        result += to_string(dig);
    }
    return result;
}

int main(){
    int num;
    cin>>num;
    cout<<factorial(num);
}
