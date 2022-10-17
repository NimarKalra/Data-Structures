//Nimarpreet Singh 
//ECE SID:21105075
#include <iostream>           
using namespace std;         

/*

QUESTION:How would you search for an element in an array/list whose size is unknown?

SOLUTION: We can search an element in an array whose size is unknown in O(logn) time complexity provided that the array is in sorted order (I am considering ascending order).We can modify the binary search.

The concept behind this approach is:
  ->Take inital value of i as 0 and j as 1.
  ->Now increase j to j*2 until arr[j] exceed the key to be searched.
  ->Now search the key using binary search between i and j.

*/

//Simple Binary Search Function
int binary_search(int arr[],int i,int j,int key){
    int m=(i+j)/2; //m=middle element
    while(i<=j){   //i=starting index j=ending index
    if(arr[m]==key){
    return m;
    }  // if key to be searched is present we will return index of the key
    else{
        if(arr[m]<key){i=m+1;}
        else{j=m-1;}
    }
    m=(i+j)/2;
    }
    return -1;  // when element is not present we will return -1
}
//Enhanced binary search function or Binary search for array with unknown length
int binary_search_unknown(int arr[],int key){
    //Initializing i as 0 and j as 1.
    int i=0,j=1;
    //We will increase j until arr[j] exceeds key to be searched.
    while(arr[j]<key){
        i=j;
        j=2*j;
    }

    //Now making call for Simple Binary Search on range i to j.
    return binary_search(arr,i,j,key);
}
int main()
{
    int arr[5]={1,2,3,4,5};
    int key=3;
    cout<<binary_search_unknown(arr,key)<<endl;
    return 0;
}
