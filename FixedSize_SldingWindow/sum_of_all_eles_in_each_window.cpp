#include <iostream>
#include <vector>
using namespace std;

vector<int> sumOfElementsInWindow(vector<int> arr, int k){
    vector<int> result;
    int windowSum = 0;

    for(int i=0;i<k;i++)
        windowSum += arr[i];

    result.push_back(windowSum);
    for(int i=k;i<arr.size();i++){
        windowSum += arr[i] - arr[i-k];
        result.push_back(windowSum);
    }

    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = sumOfElementsInWindow(nums, k);
    for (int sum : result) {
        cout << sum << " ";
    }
    return 0;
}