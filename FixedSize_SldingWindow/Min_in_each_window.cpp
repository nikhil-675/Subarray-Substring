#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> minInSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dq;

    for (int i = 0; i < nums.size(); ++i) {
        while (!dq.empty() && nums[dq.back()] >= nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        
        if (dq.front() == i - k) {
            dq.pop_front();
        }
        
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    
    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = minInSlidingWindow(nums, k);
    for (int minElem : result) {
        cout << minElem << " ";
    }
    return 0;
}
