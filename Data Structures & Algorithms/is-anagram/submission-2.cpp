class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int ascii_bucket_s[200] = {};
        int abt[200] = {};
        for (int i = 0; i<s.length();i++) {
            ascii_bucket_s[s[i]]++;
            abt[t[i]]++;
        }
        for (int i = 0;i<200;i++){
            if(ascii_bucket_s[i]!=abt[i])return false;
        }
        return true;
    }
};
