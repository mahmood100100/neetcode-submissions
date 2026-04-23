class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int > freq;
        for(auto &num : nums) freq[num]++;
        int maxFreq = 0;
        for(auto &pair : freq) {
            if(pair.second > maxFreq) maxFreq = pair.second;
        }
        vector<vector<int>> reversed(maxFreq + 1);
        for(auto &pair : freq) {
            reversed[pair.second].push_back(pair.first);
        }
        vector<int> result;
        for(int i=maxFreq ; i>= 0 && k>0 ; i--) {
           for(auto num : reversed[i]) {
                if(k > 0) {
                   result.push_back(num);
                   k--;
                }
           }
        }
        return result;
    }
}; 