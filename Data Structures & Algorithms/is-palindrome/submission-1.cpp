class Solution {
   public:
    bool isPalindrome(string s) {
        string str;
        for (char c : s) {
            if (isalnum(c)) str += tolower(c);
        }
        for (int i = 0; i < str.length() / 2; i++) {
            if (str[i] != str[str.length() - i - 1]) return 0;
        }
        return 1;
    }
};
