class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int left , right;
        sort(nums.begin(), nums.end());
        
        for(int pin = 0; pin < nums.size(); pin++) {
            if(pin > 0 && nums[pin] == nums[pin-1]) continue;
            
            left = pin + 1;
            right = nums.size() - 1;
            
            while(left < right) {
                int sum = nums[pin] + nums[left] + nums[right];
                
                if(sum == 0) {
                    result.push_back({nums[pin], nums[left], nums[right]});
                    
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    
                    left++;
                    right--;
                }
                else if(sum > 0) {
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        return result;
    }
};