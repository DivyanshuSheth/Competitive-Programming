class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int, int> hashmap;
        for (int i : nums) {
            hashmap[i]++;
        }
        for (auto &x : hashmap) {
            if (x.second > (nums.size() / 2)) {
                return x.first;
            }
        }
        return -1;
    }
};
