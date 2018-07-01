#include <iostream>
#include <vector>
using namespace std;
int mid(int first,int last){
    return (first + last) / 2;
}
int Peak(vector<int> Arr){
    int left = 0, right = Arr.size() - 1;
    int middle = mid(left,right);
    int present, prev, next;
    bool isPeak = false;
    if(Arr.size()!= 1){
        while(!isPeak){
            if (middle == 0 or middle == Arr.size()-1){
                if(middle == 0){
                    if(Arr[middle + 1] < Arr[middle])
                        isPeak = true;
                    else
                        left = middle + 1;
                }
                else{
                    if(Arr[middle - 1] < Arr[middle])
                        isPeak = true;
                    else
                        right = middle - 1;
                }
            }
            else{
                //After this statement it is ensured that indices are neither 0 not last
                present = Arr[middle];
                prev = Arr[middle - 1];
                next = Arr[middle + 1];
                if(present > prev and present > next){
                    //peak number found
                    isPeak = true;
                }
                else if(present > prev and present < next){
                    //middle is in increasing portion
                    left = middle + 1;
                }
                else if(present < prev and present > next){
                    //middle is in decreasing portion
                    right = middle - 1;
                }
            }
            if(!isPeak)
                middle = mid(left, right);
        }
        return Arr[middle];
    }
    else
        return Arr[0];
}
int main(){
    int T,N;
    cin >> T;
    
    for (int c = 1; c <= T;c++){
        cin >> N;
        vector<int> ARR(N);
        for (int i = 0; i < N; i++)
        {
            cin >> ARR[i];
        }
        cout<<Peak(ARR)<<'\n';
    }
}
