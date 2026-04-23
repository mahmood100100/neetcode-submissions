class Solution {
public:
    
    string encode(vector<string>& strs) {
       string s = "";
       vector<int> lengths;
       for(string &str : strs) {
        lengths.push_back(str.length());
       }
       for(int &len : lengths) {
        s += to_string(len);
        s += ","; 
       }
       s += "#";
       for(string &str : strs) {
        s+= str;
       }
       return s;
    }

    vector<string> decode(string s) {
        vector<int> lengths;
        vector<string> result;
        int hashPos = s.find('#');
        string metadata = s.substr(0 , hashPos);
        string content = s.substr(hashPos +1);
        for(int i=0; i< metadata.length(); i++) {
             int sum = 0;
             while(metadata[i] != ',') {
                sum = sum*10 + (metadata[i] - '0');
                i++;
             }
             lengths.push_back(sum);
        }
        int start = 0;
        for(int i=0; i< lengths.size(); i++) {
          string str = content.substr(start , lengths[i]);
          result.push_back(str);
          start+= lengths[i];
        }
        return result;
    }
};
