#include <iostream>
#include <vector>
using namespace std;
int mid(int first,int last){
    return (first + last) / 2;
}
int BinarySearch(vector<int> Arr,int num){
    int first = 0, last = Arr.size() - 1;
    while(first <= last){
        int middle = mid(first,last);
        if(Arr[middle] == num)
            return middle;
        else if(Arr[middle] > num)
            last = middle - 1;
        else if(Arr[middle] < num)
            first = middle + 1;
    }
    return -1;
}

int findLowerLimit(vector<int> Arr,int Mid){
    if(Mid != 0){
        int left = 0;
        int right = Mid - 1;
        int middle = mid(left, right);
        
        //Run till you find the index of the number which is just small than number
        while(Arr[middle + 1] != Arr[Mid] or Arr[middle] == Arr[Mid]){
            if(Arr[middle + 1] != Arr[Mid])
                left = middle + 1;
            else if(Arr[middle] == Arr[Mid])
                right = middle - 1;
            if(left <= right)
                middle = mid(left, right);
            else
                return -1;
        }
        return middle;
    }
    else
        return -1;
}
int findUpperLimit(vector<int> Arr,int Mid){
    if(Mid != Arr.size() - 1){
        int left = Mid+1;
        int right = Arr.size() - 1;
        int middle = mid(left,right);
        while(Arr[middle-1] != Arr[Mid] or Arr[middle] == Arr[Mid]){
            if(Arr[middle-1] != Arr[Mid]){
                right = middle - 1;
            }
            else if(Arr[middle] == Arr[Mid]){
                left = middle + 1;
            }
            if(left <= right){
                middle = mid(left, right);
            }
            else
                return Arr.size();
        }
        return middle;
    }
    else
        return Arr.size();
}
int CountOccur(vector<int> Arr,int num){
    int middle = BinarySearch(Arr, num);
    
    if(middle != -1)
        return findUpperLimit(Arr,middle) - findLowerLimit(Arr,middle) - 1;
    else
        return -1;
}
int main(){
    int T,N,X;
    cin >> T >> N >> X;
    vector<int> ARR(N);
    for (int c = 1; c <= T;c++){
        for (int i = 0; i < N; i++)
        {
            cin >> ARR[i];
        }
        cout<<CountOccur(ARR,X)<<'\n';
    }
}
