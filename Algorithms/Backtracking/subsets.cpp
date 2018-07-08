#include <vector>
void Subsets(vector<int> &A,vector<int> &subset,vector<vector<int>> &Res,int index){
    for(int i=index;i<A.size();i++){
        subset.push_back(A[i]);
        Res.push_back(subset);

        Subsets(A,subset,Res,index+1);

        subset.pop_back();
    }
}
