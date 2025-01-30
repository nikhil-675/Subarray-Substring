#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> countDistinctInWindow(vector<int>& arr, int k){
    vector<int> result;
    unordered_map<int,int> freqMap;

    for(int i=0;i<k;++i){
        freqMap[arr[i]]++;
    }
    result.push_back(freqMap.size());

    for(int i=k;i<arr.size();++i){
        if(--freqMap[arr[i-k]] == 0){
            freqMap.erase(arr[i-k]);
        }
        freqMap[arr[i]]++;
        result.push_back(freqMap.size());
    }
    return result;
}

int main(){
    vector<int> arr = {1, 2, 1, 3, 4, 3, 5};
    int k=3;
    vector<int> result = countDistinctInWindow(arr, k);
    for(int distinctCount :result){
        cout<<distinctCount<<" ";
    }
    return 0;
}