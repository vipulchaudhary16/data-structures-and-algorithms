### [Sort an array of 0’s 1’s 2’s](https://leetcode.com/problems/sort-colors/description/)

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid <= high){
            if(nums[mid] == 0){ //0 hai to aage thoko, low aage badhega, mid bhi aage badhega
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            } else if(nums[mid] == 1){ //1 hai to chupchap aage badh jao
                mid++;
            } else { //2 hai to pichhe le jao, high pichhe aayega, par mid waha hi rahega, kyun ki hame pata nhi swap karne hamne high se kya laya h
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};