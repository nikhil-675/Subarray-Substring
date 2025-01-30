#include <iostream>
#include <vector>
using namespace std;

vector<int> countNegativesInWindow(vector<int>& nums, int k) {
    vector<int> result;
    int negativeCount = 0;
    
    // Count negatives in the first window
    for (int i = 0; i < k; ++i) {
        if (nums[i] < 0) {
            negativeCount++;
        }
    }
    result.push_back(negativeCount);
    
    // Slide the window and update count
    for (int i = k; i < nums.size(); ++i) {
        if (nums[i - k] < 0) {
            negativeCount--;
        }
        if (nums[i] < 0) {
            negativeCount++;
        }
        result.push_back(negativeCount);
    }
    
    return result;
}

int main() {
    vector<int> nums = {1, -3, -1, 3, -5, -3, 6, 7};
    int k = 3;
    vector<int> result = countNegativesInWindow(nums, k);
    for (int count : result) {
        cout << count << " ";
    }
    return 0;
}
