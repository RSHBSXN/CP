#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
#define MAX 7
typedef vector<vector<bool>> vvb;

class NODE{
    char data;
    bool isWord;
    public:
        unordered_map <char,NODE *> CHILDS;//MAP is having childs of a node which are accessible by the character 
        
        NODE(char data){
            this->data = data;
            isWord = false;
        }
        static void insert(NODE* ROOT,string word,int index = 0){
            //if the last character has been inserted then set that Node's isWord boolean variable to true
            if(index == word.size()){
                ROOT->isWord = true;
            }
            else{
                //check whether there exist a child whose value is same as that or word's index 
                NODE *CHILD = ROOT->CHILDS[word[index]];
                if(!CHILD){
                    //if there is no child present then create it and add to the child of parent node
                    CHILD = new NODE(word[index]);
                    ROOT->CHILDS[word[index]] = CHILD;
                }
                //Move further to insert the node in trie
                insert(CHILD,word,index+1);
            }
        }
};

void getWords(char boggle[MAX][MAX],int maxRows,int maxCols,int row,int col,NODE *ROOT,vvb visited,string word,vector<string> &Words){
    if(ROOT->isWord){
        if(find(Words.begin(),Words.end(),word) == Words.end())
            Words.push_back(word);
    }
    for(int i=row-1;i<=row+1;i++){
        for(int j = col-1;j<=col+1;j++){
            if((i >=0 and i < maxRows && j >=0 and j < maxCols) && visited[i][j] != true){
                if(ROOT->CHILDS[boggle[i][j]]){
                    visited[i][j] = true;
                    getWords(boggle,maxRows,maxCols,i,j,ROOT->CHILDS[boggle[i][j]],visited,word + boggle[i][j],Words);
                    visited[i][j] = false;  
                }
            }
        }
    }
}
void getWordsInit(char boggle[MAX][MAX],int maxRows,int maxCols,NODE *ROOT,vector<string> &Words){
    //initializing visited matrix
    vector<bool> v(maxCols);
    vvb visited(maxRows,v);
    for(int i=0;i<maxRows;i++){
        for(int j=0;j<maxCols;j++){
            
            if(ROOT->CHILDS[boggle[i][j]]){
                visited[i][j] = true;
                getWords(boggle,maxRows,maxCols,i,j,ROOT->CHILDS[boggle[i][j]],visited,(string)"" + boggle[i][j],Words);
                visited[i][j] = false;
            }
        }
    }
}
int main(){
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        int x;
        cin >> x;
        //Top most level has character ~
        NODE *ROOT = new NODE('~');
        for(int w=1;w<=x;w++){
            string word;
            cin >> word;
            //getting all words from input one by one then inserting them in TRIE
            NODE::insert(ROOT,word);
        }
        
        int N,M;
        cin >> N >> M;
        char boggle[MAX][MAX];
    
        for(int row=0;row<N;row++)
            for(int col=0;col<M;col++)
                cin >> boggle[row][col];
    
        vector<string>Words;
    
        getWordsInit(boggle,N,M,ROOT,Words);
    
    //  sorting string in asc order
        sort(Words.begin(),Words.end());
        if(Words.size() == 0)
            cout<<-1;
        else
            for(string word : Words){
                cout<<word<<' ';
            }
        cout<<endl;
    }
}
