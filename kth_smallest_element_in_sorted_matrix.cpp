/*
Leetcode Que : https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
Author : Prathamesh Patil
Solution : C++ Lang
*/

#include<iostream>
#include<btis/stdc++.h>

using namespace std;

// function provided , construct main and pass the parameters
int kthSmallest(vector<vector<int>>& matrix, int k)
{
  // getting the size of matrix i.e rows and columns specifically
  int n = matrix.size(), m = matrix[0].size();
	
  // creating a 1D array
  int arr[n*m];
	int c = 0;
  
  // iterating through the matrix while copying the data to array
  for(int i = 0; i < n; i++)
	{
    for(int j = 0; j < m; j++)
		{
      a[c] = matrix[i][j];
      c++;
    }
  }
  
  // sorting method : used to sort array in ascending order
  sort(arr, arr+(n*m));
  
  // returning the kth element 
  return a[k-1];
}
