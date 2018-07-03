/*
 *  Given two sorted arrays. There is only 1 difference between the arrays.
 *  First array has one element extra added in between. Find the index of the extra element.
 */
int findExtra(int a[],int b[],int n){
    //Corner Cases
    if(a[0] != b[0])
        return 0;
    else if(a[n-1] != b[n-2])
        return n-1;
    else{
        int first = 0;
        int last = n-2;
        int middle = getMid(first,last);
        bool fndEx = false;
        while(!fndEx){
            if(a[middle] == b[middle])
                first = middle + 1;
            else if(a[middle] != b[middle] && a[middle] == b[middle - 1])
                last = middle - 1;
            else if(a[middle] != b[middle])
                fndEx = true;
            if(!fndEx)
                middle = getMid(first,last);
        }
        return middle;
    }
}
