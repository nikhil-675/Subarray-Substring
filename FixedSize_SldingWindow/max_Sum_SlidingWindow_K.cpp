#include <iostream>
#include <vector>
using namespace std;


int maxSumSubarrayOfSizeK(vector<int> &arr, int k){
    int n = arr.size();
    if(k > n) return 0;

    int maxSum = 0;
    int currSum = 0;

    // todo: first window
    for(int i=0;i<k;i++){
        currSum += arr[i];
    }

    maxSum = currSum;
    // todo: rest of windows
    for(int i=k;i<n;i++){
        maxSum -= arr[i-k];
        
    }

}

int main(){
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    cout<<"Maximum sum of subarray of size :"<<k<<" is "<<maxSumSubarrayOfSizeK(arr,k)<<"\n";
    return 0;
}