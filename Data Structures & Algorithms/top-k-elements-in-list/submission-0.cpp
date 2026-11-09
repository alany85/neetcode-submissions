class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // set<pair> sett;
        // map<int, int> mapp;
        vector<pair<int, int>> v(2020);
        vector<int> res;
        for (int i : nums) {
            v[i + 1000].first = i;
            v[i + 1000].second++;
            // int times = mapp[i];
            // set.remove()
            // auto p = make_pair(mapp)
            // sett.insert(<i, )
        }
        sort(v.begin(), v.end(), [](const auto& a, const auto& b) { return a.second > b.second; });
        for (int i = 0; i < k; i++) {
            res.push_back(v[i].first);
        }
        return res;
    }

    // bool operator<(const pair<int, int>& other) const { return second < other.second; }
};
