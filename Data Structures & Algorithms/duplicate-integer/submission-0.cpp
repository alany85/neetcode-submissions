class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> contained;
        for(int i = 0; i < nums.size();i++) {
            if(contained.contains(nums[i])) return true;
            contained.insert(nums[i]);
        }
        return false;
    }
};