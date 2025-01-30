#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dq;  // Deque to store indices of array elements

    for (int i = 0; i < nums.size(); i++) {
        // Remove elements that are out of this window
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        // Maintain decreasing order in deque, remove smaller elements
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        // Add the current element index
        dq.push_back(i);

        // Store result after first k elements
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);  // The front of deque is the max
    }
    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    
    vector<int> result = maxSlidingWindow(nums, k);
    
    // Print the result
    for (int num : result)
        cout << num << " ";
    
    return 0;
}
