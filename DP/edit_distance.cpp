// Name : Altaf Ahmad , Github : altafDevRev
// Question taken from the sheet : https://practice.geeksforgeeks.org/problems/edit-distance3702/1

#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2)
{
    vector<vector<int>> cost;
    int minim;
    int m = word1.size(), n = word2.size();
    for (int i = 0; i <= m; i++)
    {
        vector<int> c;
        for (int j = 0; j <= n; j++)
        {
            c.push_back(0);
        }
        cost.push_back(c);
    }
    for (int i = 0; i <= m; i++)
    {
        cost[i][0] = i;
    }
    for (int i = 0; i <= n; i++)
    {
        cost[0][i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                cost[i][j] = cost[i - 1][j - 1];
            }
            else
            {
                minim = min(cost[i][j - 1], cost[i - 1][j]);
                minim = min(minim, cost[i - 1][j - 1]);
                cost[i][j] = minim + 1;
            }
        }
    }
    return cost[m][n];
}
int main()
{
    string w1 = "kindergarten";
    string w2 = "gardening";
    cout << minDistance(w1, w2) << "\n";
    return 0;
}