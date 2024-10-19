/*
Find unique sets of integers that add up to '15' from the following array: [4, 5, 6, 89, 23, 5, 2, 3, 5].
For the above mentioned array, we should have:
output = [ 4, 5, 6 ],
         [ 2, 3, 4, 6 ],
         [ 2, 3, 5, 5 ],
         [ 5, 5, 5 ]
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findCombinations(vector<int>& arr,
    int target,
    int start,
    vector<int>& current,
    vector<vector<int>>& result) {

    if (target == 0) {
        result.push_back(current);
        return;
    }
    for (int i = start; i < arr.size(); ++i) {
        if (i > start && arr[i] == arr[i - 1]) continue; // Skip duplicates
        if (arr[i] > target) break; // Early termination
        current.push_back(arr[i]);
        findCombinations(arr, target - arr[i], i + 1, current, result);
        current.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    vector<std::vector<int>> result;
    vector<int> current;
    findCombinations(arr, target, 0, current, result);
    return result;
}

int main() {
    vector<int> arr = { 4, 5, 6, 89, 23, 5, 2, 3, 5 };
    int target = 15;
    vector<std::vector<int>> result = combinationSum(arr, target);
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}