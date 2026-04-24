class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int size = nums.size();
       vector<int> result;
       int product = 1;
       for(int &num : nums) {
         result.push_back(product);
         product *= num;
       }
       product = 1;
       for(int i= size -1 ; i>= 0 ; i--) {
         result[i] *= product;
         product *= nums[i];
       }
       return result;
    }
};
