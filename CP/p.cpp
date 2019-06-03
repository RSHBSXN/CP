#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<string> Str(n);
    for(string &x : Str)
        cin >> x;
    unordered_map<pair<int,int>,int> COUNT;
    int Max = 0;
    for(string &x : Str){
        COUNT[x]++;
        if(COUNT[x] > Max)
            Max = COUNT[x];
    }
    unordered_map<string,int> :: iterator itr;
    for(itr = COUNT.begin();itr != COUNT.end();++itr){
        cout<<itr->first<<'\n';
    }
}