#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string a,b;
        unordered_set<char> SET;
        cin >> a >> b;
        for(char c : a){
            SET.insert(c);
        }
        int count = 0;
        for(char x : b){
            if(SET.find(x) != SET.end()){
                count++;
            }
        }
        cout<<count<<'\n';
    }
}