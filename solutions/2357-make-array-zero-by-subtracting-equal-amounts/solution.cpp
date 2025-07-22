class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> us;

        for( int it : nums){
            if(it > 0){
                us.insert(it);
            }
        }

        return us.size();
    }
};