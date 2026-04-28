class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int size = nums.size();
        sort(nums.begin() , nums.end());  // [-4 , -1 , -1 , 0 , 2]
        for(int i=0; i < size; i++) {
            int left = i+1 , right = size -1;
            if(i > 0 && nums[i] == nums[i -1]) continue;
            while(left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if(sum == 0) {
                    result.push_back({nums[i],nums[left],nums[right]});
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                } else if(sum > 0) {
                    right--;
                    while(left < right && nums[right] == nums[right+1]) right--;
                } 
                else {
                    left++;
                    while(left < right && nums[left] == nums[left-1]) left++;
                }
            }
        }
        return result;
    }
};
