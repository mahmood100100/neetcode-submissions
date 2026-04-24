class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int> leftProduct , result(nums.size());
       int size = nums.size();
       int product = 1;
       for(int &num : nums) {
         leftProduct.push_back(product);
         product *= num;
       }
       product = 1;
       for(int i= size -1 ; i>= 0 ; i--) {
         result[i] = product * leftProduct[i];
         product *= nums[i];
       }
       return result;
    }
};
