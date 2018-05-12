#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <iterator>
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
        for(pair<UGraph*,int> vertices : AdjVerts){
            if(vertices.first == vert){
                return;
            }
        }
        AdjVerts.push_back({vert,edge});
    }
    string ShowAdj(){
        string result;
        for(pair<UGraph*,int> Vertex : AdjVerts){
            result += Vertex.first->Name();
            result += " " + to_string(Vertex.second)+" ";
        }
        return result;
    }
    static void InitGraph(){
        int vertices;
        cout<<"enter number of vertices\n";
        cin>>vertices;
        for(int i=0;i<vertices;i++){
            UGraph *vertex = new UGraph('A'+i);
        }
        map<char,UGraph*> :: iterator itr,itr2;
        for(itr = UGraph::Graph.begin();itr != UGraph::Graph.end();itr++){
            bool check = true;
            string otherVertices("");
            for(itr2 = UGraph::Graph.begin();itr2 != UGraph::Graph.end();itr2++){
                //if(itr2 != itr){
                    otherVertices += itr2->second->Name();
                    otherVertices += " ";
                
            }
            while(check){
                cout<<"Enter adjacent Edges out of ";
                cout<<otherVertices;
                cout<<"\nAnd enter its length:";
                char x;
                cin>>x;
                for(int charInd = 0;charInd < otherVertices.length();charInd++){
                    if(otherVertices[charInd] == x){
                        otherVertices.erase(charInd,1);
                        break;
                    } 
                }
                int edge;
                if(x == '0')
                    check = false;
                else{
                    cin>>edge;
                    itr->second->AddAdj(UGraph::Graph[x],edge);
                    UGraph::Graph[x]->AddAdj(itr->second,edge);
                }
            }
        }
    }
};
map <char,UGraph*> UGraph :: Graph;
//void UGraph :: InitGraph();
int main(){
    /*
    UGraph :: InitGraph();
    map<char,UGraph*> :: iterator itr;
    for(itr = UGraph::Graph.begin();itr != UGraph::Graph.end();itr++){
        cout<<itr->first<<" has "<<itr->second->ShowAdj()<<endl;
    }
    */
}
