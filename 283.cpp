class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        while( i <nums.size()) {
            while(i < nums.size() && nums[i] != 0) i++;
            j = i + 1;
            while(j < nums.size() && nums[j] == 0) j++;
            swap(nums[i], nums[j]);
            i++;
        }
    }
};