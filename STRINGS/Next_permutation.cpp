#include <bits/stdc++.h>
using namespace std;

// user function Template for C++
class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        // Traverse from the back in the array loop and find the element which is lesser                 
        // then the ith element and thats a break point
        int i; int l;
        for(i = n-2; i>=0 ; i--){
            if(arr[i]  < arr[i+1]){
                break;
            }
        }
        // After finding the break point check whether i
		// will go till the 0 index if yes it                   
        // means its the last permutation so just reverse it

        if(i < 0) {
            reverse(arr.begin(),arr.end());
        }
        // if not then find the larger  number form 
		// the right to left and swap then after                      
        else{
            for(l = n-1; l>i; l--){
                if(arr[l] > arr[i]){
                    break;
                }
            }
        swap(arr[i],arr[l]);   
        reverse(arr.begin() + i + 1, arr.end());
        }
        return arr;   

    }
};
// main function 
int main()
{
	int t;  // no. of test cases
	cin>>t;
	while(t--)
	{
		int N;  // size of array
		cin>>N;
		vector<int> arr(N);
		for(int i=0;i<N;i++)
		  cin>>arr[i];
		Solution ob;
		vector<int> ans= ob.nextPermutation(N,arr)
		for(int u:ans)
		  cout<<u<<" ";
	}
	return 0;
}
