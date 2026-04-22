class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int > check;
        int size = nums.size();
        for(int i=0; i< size ; i++) check[nums[i]] = i;

        for(int i=0; i< size ; i++) {
            int reminder = target - nums[i];
            if(check.find(reminder) != check.end() && check[reminder] != i) {
                return {i , check[reminder]}; 
                break;
            }
        }
        return {};
    }
};
