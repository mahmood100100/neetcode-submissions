class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char , int> freq;
        if(s.length() != t.length()) return false;

        for(char str : s) {
            freq[str]++;
        }
        for(char str : t) {
            freq[str]--;
        }
        for(auto p : freq) {
            if(p.second != 0) return false;
        }
        return true;
    }
};
