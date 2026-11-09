class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> mapp;
        vector<vector<string>> res;

        int count = 0;
        for (string s : strs) {
            string newS = convertS(s);
            if (mapp.contains(newS)) {
                res[mapp[newS]].push_back(s);
            } else {
                mapp[newS] = count++;
                res.push_back({s});
            }
        }
        return res;
    }
    string convertS(string str) {
        string s(26, 0);
        for (char c : str) {
            s[c - 'a']++;
        }
        return s;
    }
};
