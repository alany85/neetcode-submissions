class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        set<string> sett;
        unordered_map<string, vector<string>> mapp;
        for (string s : strs) {
            sett.insert(convertS(s));
            mapp[convertS(s)].push_back(s);
        }

        vector<vector<string>> res;

        for (string s : sett) {
            res.push_back(mapp[s]);
        }
        // for (const auto& pair : mapp) {
        //     res.push_back(pair.second);
        // }
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

// Idea now: use string to store the converted info.
// Use unordered_map as a hashtable to do O(1) search.
// How do we do the insert now then?
// Key: hash of the strings
// Val: vector<string>