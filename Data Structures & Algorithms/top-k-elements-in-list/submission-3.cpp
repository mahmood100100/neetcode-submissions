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
        for(int i=maxFreq ; k>0 ; i--) {
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
//                               3 1 3 1
// {3 , 7 , 2 , 9 , 2 , 3 , 2}   3 7 2 9     k=2   