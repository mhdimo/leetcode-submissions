class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> m;
        m.reserve(nums.size()); // avoid rehashing

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int complement = target - nums[i];
            auto found = m.find(complement);
            if (found != m.end())
                return {found->second, i};
            m[nums[i]] = i;
        }
        return {};
    }
};