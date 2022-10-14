/*
This code is given by:
SNEHA JAISWAL
GitHub link: https://github.com/Sneha-jais

Problem Statement:
Given an array of N integers where each value represents the number of chocolates in a packet. 
Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that:
1. Each student gets one packet.
2. The difference between the number of chocolates in the packet with maximum chocolates 
and the packet with minimum chocolates given to the students is minimum.
*/

#include <bits/stdc++.h>
using namespace std;

// Function for returning the minimum difference which is the difference between minimum and maximum value

int Min_difference(int arr[], int n, int m)
{
	// If there are no chocolates then return 0
	if (n == 0)
		return 0;
	// If there are no students then return 0
	if (m == 0)
		return 0;

	// Firstly Sort the given packets for achieving minimum and maximum values
	// sort is a direct function in c++ to sort the elements of array
	sort(arr, arr + n);

	// if students is more in comparison of packets then we will simply return -1

	if (m > n)
		return -1;

	// initialize minimum difference i.e. ans with maximum value
	int ans = INT_MAX;
	//d refers to the difference,initialize with 0
	int d = 0;

	for (int i = 0; i + m - 1 < n; i++)
	{
		//finding the difference between two elements of array
		d = arr[i + m - 1] - arr[i];
		// if new difference is less than ans then put it in ans variable
		if (d < ans)
			ans = d;
	}
	// return the ans which is minimum difference
	return ans;
}

int main()
{
	// Declaring the size of array
	int n;
	cout << "Enter the size of array:\n";
	// taking input from user for size of array
	cin >> n;
	// declaring the array of size given by user
	int arr[n];
	cout << "Enter the elements of array:\n";
	// taking inputs for elements of array
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int m;
	cout << "Enter the number of students:\n";
	// taking inputs for number of students
	cin >> m;
	cout << "Minimum difference is: "
		 << Min_difference(arr, n, m);
	return 0;
}
