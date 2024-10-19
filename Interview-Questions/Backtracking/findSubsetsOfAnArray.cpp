/*
Given an array Arr[] of size N, print all the subsets of the array.

Example:

Input: N = 3, Arr = [1, 2, 3]
Output: {}
        {1}
        {1, 2}
        {1, 2, 3}
        {1, 3}
        {2}
        {2, 3}
        {3}

Reference: https://www.geeksforgeeks.org/backtracking-to-find-all-subsets/
Practise: https://www.geeksforgeeks.org/problems/subsets-1613027340/1
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void calcSubset(vector<int>& arr,
    vector<int>& subset,
    vector<vector<int>>& result,
    int idx) {
    result.push_back(subset);
    for (int i = idx; i < arr.size(); i++) {
        // Include the current element in the subset
        subset.push_back(arr[i]);
        // Recursively generate subsets with the current element included
        calcSubset(arr, subset, result, i + 1);
        // Exclude the current element from the subset (backtracking)
        subset.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& arr) {
    vector<int> subset;
    vector<vector<int>> result;
    auto idx = 0;
    calcSubset(arr, subset, result, idx);
    sort(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> arr = { 1, 2, 3 };
    vector<vector<int>> result = subsets(arr);
    for (const auto& subset : result) {
        for (auto num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}