#include <iostream>
#include <vector>
using namespace std;
/*
    The question is two find the maximum area of sqaure from matrix of 1 and 0s
    Example:
        [1,0,1,0,0]
        [1,0,'1,1',1]
        [1,1,'1,1',1]
        [1,0,0,1,0]

    1 with " ' " is just to define the square 
    Answer: 2*2 = 4

    Note : We can change the given matrix also but in some questions it become important to make another matrix

    Approach :
        1.Make a matrix name dp initialize with 0
        2.If at any index of 0th row or 0th column is 1 store 1 at same index in dp matrix
        3.If value at any index is zero just continue
        4.If value is 1 get minimum from the neighbouring cells of that index but only in horizontal and vertical direction
        5.Add 1 + with minimum value and store it at the i and j index
        6.Find the max element from dp array and return it 


    =>We know the minimum area of square in matrix can be 1.
    =>If it is not 1 area cannot be 2 or 3 or so on.
    =>So we will basically make small 2*2 at every index if at that index value is 1 becoz then only there is probability
      that it can be square of area more than 1
    =>example 1: 1,0     here element with . is current index now minimum from neighbour is 0 we will store 0+1 in current index
               0,1.

    And it is correct that max size of this square is 1

    If we repeat this at every index we will get the right answer
    
*/
int maxSqArea(vector<vector<int>>maxo) {

    //defining the dp matrix and initialising it with 0 at every index 
    vector<vector<int>>dp(maxo.size(),vector<int>(maxo[0].size(),0));

    for (int i = 0; i < maxo.size(); i++) {
        for (int j = 0; j < maxo[0].size(); j++) {

            //to check whether we are at 0th row or 0th column or not
            if (i==0||j==0) {
                if (maxo[i][j]==1) {
                    dp[i][j] = 1;
                }
            }
            // if value is 1 get minimum value 
            else if(maxo[i][j]==1){
                dp[i][j] = min(dp[i-1][j-1], min(dp[i - 1][j], dp[i][j - 1]))+1;
            }
        }
    }
    int s = 0;
    // finding max value in dp matrix and returning it
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[0].size(); j++) {
            s = max(s, dp[i][j]);
        }
    }
    return s*s;
}
int main() {
    int n=0,m=0;
    cin >>n>>m;
    vector<vector<int>>maxo(n,vector<int>(m));
    for (int i = 0; i<n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            maxo[i][j] = x;
        }
    }
    cout<<maxSqArea(maxo);
    return 0;
};
