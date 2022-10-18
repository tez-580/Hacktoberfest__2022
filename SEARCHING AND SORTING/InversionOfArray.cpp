/* 
This code is given by:
SNEHA JAISWAL
GitHub link: https://github.com/Sneha-jais

Problem Statement: Given an array of integers. Find the Inversion Count in the array.
Inversion Count: For an array, inversion count indicates how far (or close) the array is from
being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the
reverse order then the inversion count is the maximum.
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
Input: n=5
       arr[]={2,4,1,3,5}
       Output: 3
       Explanation: It has three inversion (2,1), (4,1), (4,3).
*/


//Approach: Divide and Conquer 
#include<bits/stdc++.h>
using namespace std;

//Function for merging the elements

int merge(int arr[],int low,int mid,int high){
    //initialize i and j with low and mid respectively
    int i=low,j=mid,k=0;
    //At first inversion count is 0
    int count=0;
    //initializing a temporary array
    int temp[high+low-1];


  while ((i < mid) && (j <= high)) {
    if (arr[i] <= arr[j]) {
      temp[k] = arr[i];
      ++k;
      ++i;
    } 
    else {
      temp[k] = arr[j];
      count += (mid - i);
      ++k;
      ++j;
    }
  }
 
 //if there are some elements left of subarray 1 (low to mid)
  while (i < mid) {
    temp[k] = arr[i];
    ++k;
    ++i;
  }
 //if there are some elements left of subarray 2 (mid to high) 
  while (j <= high) {
    temp[k] = arr[j];
    ++k;
    ++j;
  }

 int m=0;

 //copying the elements from temporary array to original arrat
  for (i = low; i <= high; i++) {
    arr[i] = temp[m];
    m++;
  }   
  //retrun the inversion count 
  return count;  
}

//function for sorting a problem into sub problems
int merge_sort(int arr[],int low,int high){
    //initialize count as 0
    int count=0;
    
    if(low<high){

        int mid=(low+high)/2;
        //first call for the subarray 1 that will be low to mid
        count=merge_sort(arr,low,mid);
         //second call for the subarray 2 that will be mid+1 to high
        count+=merge_sort(arr,mid+1,high);
        //function call for merging
        count+=merge(arr,low,mid,high);
        
    }
    return count;
}

int main(){
    int n;
    cout<<"Enter number of elements:\n";
    //taking input from user for number of elements
    cin>>n;
    int arr[n];

        cout<<"Enter the elements:\n";
          //taking input from user for elements of array
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

  //calling the function for inversion count  
   int invCount=merge_sort(arr,0,n-1);
   cout<<"Inversion count is:\n";
   //print the inversion count
      cout<<invCount;    
    return 0;
 }