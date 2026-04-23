class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> pairer;
        for(auto &str : strs) {
            string s = str;
            sort(s.begin() , s.end());
            pairer[s].push_back(str);
        }
        vector<vector<string>> result;
        for(auto &pair : pairer) {
            result.push_back(pair.second);
        }
        return result;
    }
};