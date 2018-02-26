#include<iterator>
#include<map>
#include<iostream>

using namespace std;
class Graph{
private:
    map<int,int>ID;
public:
    void join(int a,int b){
        if(ID.find(a) == ID.end() and ID.find(b) == ID.end()){
            ID[a] = a;
            ID[b] = ID[a];
        }
        else if(ID.find(a) != ID.end() and ID.find(b) == ID.end()){
            ID[b] = ID[a];
        }
        else if(ID.find(a) == ID.end() and ID.find(b) != ID.end()){
            ID[a] = ID[b];
        }
        else{
            map<int,int>::iterator it;
            for(it = ID.begin();it != ID.end();it++){
                if(it->second == ID[b])
                    it->second = ID[a];
            }
        }
    }
    bool isConnected(int a,int b){
        return ID[a] == ID[b];
    }
    void DisplayAll(){
        map<int,int>::iterator it;
        for(it = ID.begin();it != ID.end();it++){
            cout<<it->first<<'\t'<<it->second<<'\n';
        }
    }
};
int main(){
    Graph G;
    G.join(3,4);
    G.join(2,3);
    G.join(1,2);
    G.join(0,6);
    G.join(4,5);
    G.join(5,6);
    G.DisplayAll();
}
