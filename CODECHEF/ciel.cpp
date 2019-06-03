#include <iostream>
#include <map>
#include <utility>
using namespace std;
#define pii pair<int,int>
struct statement{
    int val,pr;
};
map<pii,statement> MAP;
int main(){
    int N,M;
    cin >> N >> M;
    while(N--){
        statement cs;
        pii key;
        cin >> key.first >> key.second;
        cin >> cs.val >> cs.pr;
        if(MAP.find(key) == MAP.end())
            MAP[key] = cs;
        else if(MAP[key].pr <= cs.pr)
            MAP[key] = cs;
    }
    while(M--){
        pii q;
        cin >> q.first >> q.second;
        cout<<MAP[q].val<<'\n';
    }
}