#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;
class UGraph{
    char name;
    vector <pair<UGraph*,int>> AdjVerts;
    public:
    static map <char,UGraph*> Graph;
    UGraph(char name){
        this->name = name;
        Graph[name] = this;
    }
    char Name(){
        return name;
    }
    void AddAdj(UGraph *vert,int edge){
        AdjVerts.push_back({vert,edge});
    }
    void ShowAdj(){
        for(pair<UGraph*,int> Vert : AdjVerts){
            cout<<"Name:"<<Vert.first->Name()<<endl<<'\t';
            cout<<"Edge length:"<<Vert.second<<endl;
        }
    }
};
map <char,UGraph*> UGraph :: Graph;

int main(){
    int vertices;
    cout<<"enter number of vertices\n";
    cin>>vertices;
    for(int i=0;i<vertices;i++){
        UGraph *vertex = new UGraph('A'+i);
    }
    //cout<<UGraph::Graph['A']->Name();
    map<char,UGraph*> :: iterator itr,itr2;
    for(itr = UGraph::Graph.begin();itr != UGraph::Graph.end();itr++){
        bool check = true;
        string otherVertices("");
        for(itr2 = UGraph::Graph.begin();itr2 != UGraph::Graph.end();itr2++){
            if(itr2 != itr){
                otherVertices += itr2->second->Name();
                otherVertices += " ";

            }
        }
        while(check){
            cout<<"Enter adjacent Edges out of ";
            cout<<otherVertices;
            cout<<"\nAnd enter its length:";
            //check = false;
            char x;
            int edge;
            cin>>x;
            if(x == '0')
                check = false;
            else{
                cin>>edge;
                itr->second->AddAdj(UGraph::Graph[x],edge);
                UGraph::Graph[x]->AddAdj(itr->second,edge);
            }
        }
        itr->second->ShowAdj();
    }
}
