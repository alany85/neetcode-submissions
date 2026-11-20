class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        sort(numbers.begin(), numbers.end());
        for (int i = 0; i < numbers.size(); i++) {
            int idx = index(numbers, i, numbers.size()-1, target-numbers[i]);
            if(idx != -1) return {i+1, idx+1};
        }
        return {0,0};
    }

    // We try to find the target number, with binary search
    // We build an interval, excluding left and including right
    int index(vector<int>& num, int left, int right, int target) {
        if (right == left) return -1; 
        if (right - left == 1){
            if (num[right] == target) return right;
            else return -1;
        }
        int mid = (left + right) / 2;  // Simulate with your keyboard
        if (num[mid] == target) return mid;
        if (target < num[mid]) return index(num, left, mid - 1, target);
        else return index(num, mid, right, target);
    }
};
