/*
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A subarray arr is good if it there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].

A subarray is a contiguous non-empty sequence of elements within an array

long long countGood(vector<int>& nums, int k) {
    // Write your code here
    long long count = 0;
    for(int i = 0; i < nums.size(); i++){
        int temp = 0;
        for(int j = i; j < nums.size(); j++){
            if(nums[i] == nums[j]){
                temp++;
            }
            if(temp == k){
                count++;
            }
        }
    }
    return count;
}
*/