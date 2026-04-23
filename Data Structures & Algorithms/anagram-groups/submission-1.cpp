class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> pairer;
        for(int i=0; i< strs.size(); i++) {
            string s = strs[i];
            sort(s.begin() , s.end());
            pairer[s].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for(auto pair : pairer) {
            result.push_back(pair.second);
        }
        return result;
    }
};