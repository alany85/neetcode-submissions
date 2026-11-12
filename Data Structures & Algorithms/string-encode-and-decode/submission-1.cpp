class Solution {
   public:
    string encode(vector<string>& strs) {
        string res;
        for (string s : strs) {
            res += to_string(s.length());
            res += "#";
            res += s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int cur;
        for (cur = 0; cur < s.length();) {
            size_t digits;
            int num_char = stoi(s, &digits);
            cur += digits + 1;
            // if(num_char==0)continue;
            res.push_back(s.substr(cur, num_char));
            cur += num_char;
            s = s.substr(cur, s.length() - cur);
            cur = 0;
        }
        return res;
    }
};
