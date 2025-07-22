class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combination;
        makecombination(candidates, target, 0, combination, 0, res);

        return res;
    }

private:
    void makecombination(vector<int>& candidates, int target, int idx, vector<int>& combination, int total, vector<vector<int>>& res) {
        if (total == target) {
            res.push_back(combination);
            return;
        }

        if(total > target || idx >= candidates.size()) return;

        combination.push_back(candidates[idx]);
        makecombination(candidates, target, idx, combination, total + candidates[idx], res);
        combination.pop_back();
        makecombination(candidates, target, idx +1, combination, total, res);
    }
};