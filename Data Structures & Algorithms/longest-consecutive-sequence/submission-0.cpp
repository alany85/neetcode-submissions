class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int maxx = 0;
        unordered_map<int, pair<int, int>> maxmap;
        unordered_map<int, pair<int, int>> minmap;
        /**
         我们可以把每个已发现的 consecutive sequence 用 pair 表示，
         pr.first = 该 seq 的 min，pr.second = 该 seq 的 max。
         online 地处理逐个 int x：
         如果 x 属于某一 seq：无视。真的不需要更新。
         如果 x 恰好比某一 seq 大 1，即 maxmap.contains(x - 1)，
         则更新。x 恰比某一 seq 小 1 时同理。
         */
        for (int x : nums) {
            pair<int, int> agg;
            int newmin, newmax;
            if (maxmap.contains(x) || minmap.contains(x)) continue;
            if (maxmap.contains(x - 1) && minmap.contains(x + 1)) {
                newmin = maxmap[x - 1].first;
                newmax = minmap[x + 1].second;
                agg = {newmin, newmax};
                // Then we need to update 4 kv pairs.
                minmap[newmin] = agg;
                maxmap.erase(x - 1);
                minmap.erase(x + 1);
                maxmap[newmax] = agg;
            } else if (maxmap.contains(x - 1)) {
                newmin = maxmap[x - 1].first;
                newmax = x;
                agg = {newmin, newmax};
                minmap[newmin] = agg;
                maxmap.erase(x - 1);
                maxmap[newmax] = agg;
            } else if (minmap.contains(x + 1)) {
                newmin = x;
                newmax = minmap[x + 1].second;
                agg = {newmin, newmax};
                minmap[newmin] = agg;
                minmap.erase(x + 1);
                maxmap[newmax] = agg;
            } else {
                newmin = x;
                newmax = x;
                agg = {newmin, newmax};
                minmap[x] = agg;
                maxmap[x] = agg;
            }
            maxx = max(maxx, newmax - newmin + 1);
        }
        return maxx;
    }
};
