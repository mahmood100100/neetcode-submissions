class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int > freq;
        vector<int> result;
        for(auto &num : nums) freq[num]++;
        /*int maxFreq = 0;
        for(auto &pair : freq) {
            if(pair.second > maxFreq) maxFreq = pair.second;
        }
        vector<vector<int>> reversed(maxFreq + 1);
        for(auto &pair : freq) {
            reversed[pair.second].push_back(pair.first);
        }
        for(int i=maxFreq ; i>= 0 && k>0 ; i--) {
           for(auto num : reversed[i]) {
                if(k > 0) {
                   result.push_back(num);
                   k--;
                }
           }
        }
        return result;*/
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> reversed;
        
        for(auto &pair : freq) {
           reversed.push({pair.second , pair.first});

           if(reversed.size() > k) {
                reversed.pop();
           }
        }

        for(int i=0; i<k; i++) {
            result.push_back(reversed.top().second);
            reversed.pop();
        }
        return result;
        
    }
}; 