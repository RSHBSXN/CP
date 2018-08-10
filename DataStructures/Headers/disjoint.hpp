#include <vector>

int Find(std::vector<int> ARR,int index){
    if(ARR[index] < 0)
        return index;
    else
        return Find(ARR,ARR[index]);
}
void Union(std::vector<int> &ARR,int indexOne,int indexTwo){
    int parentOne = Find(ARR,indexOne);
    int parentTwo = Find(ARR,indexTwo);
    if(ARR[parentOne] > ARR[parentTwo]){
        ARR[parentOne] += ARR[parentTwo];
        ARR[parentTwo] = parentOne;
    }
    else if(ARR[parentOne] != ARR[parentTwo]){
        ARR[parentTwo] += ARR[parentOne];
        ARR[parentOne] = parentTwo;
    }
}
