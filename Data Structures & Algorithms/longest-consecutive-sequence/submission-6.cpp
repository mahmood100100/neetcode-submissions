class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> seen;
        int maxCounter = 0;
        for(int &num : nums) seen.insert(num);
        for(int &num : nums) {
            if(seen.find(num-1) == seen.end()) {
                int counter = 1 , temp = num;
                while((seen.find(temp+1) != seen.end())){
                    counter++;
                    temp++;
                }
                if(counter > maxCounter) {
                    maxCounter = counter;
                }
            }
        }
        return maxCounter;

    }
};
