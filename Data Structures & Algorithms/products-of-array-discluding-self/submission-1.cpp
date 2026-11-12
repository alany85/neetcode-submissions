class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int num_0 = 0;
        int prod = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                num_0++;
                if (num_0 == 2) return allZero(nums.size());
                continue;
            }

            prod *= nums[i];
        }
        vector<int> res(nums.size());
        for (int i = 0; i < res.size(); i++) {
            if (nums[i] == 0)
                res[i] = prod;
            else {
                res[i] = (num_0) ? 0 : prod / nums[i];
            }
        }
        return res;
    }
    vector<int> allZero(int num) {
        vector<int> z(num, 0);
        return z;
    }
};
