#include <iostream>
#include <vector>
using namespace std;

vector<double> averageOfElementsInWindow(vector<int>& nums, int k) {
    vector<double> result;
    double windowSum = 0;
    
    for (int i = 0; i < k; ++i) {
        windowSum += nums[i];
    }
    result.push_back(windowSum / k);
    
    for (int i = k; i < nums.size(); ++i) {
        windowSum += nums[i] - nums[i - k];
        result.push_back(windowSum / k);
    }
    
    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<double> result = averageOfElementsInWindow(nums, k);
    for (double avg : result) {
        cout << avg << " ";
    }
    return 0;
}
