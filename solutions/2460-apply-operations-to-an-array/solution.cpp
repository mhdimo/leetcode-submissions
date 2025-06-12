class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        std::vector<int> result(nums.size());
        int count = 0;
        int i;

        for(i = 0; i< nums.size()-1;i++){
            if(nums[i] != 0){
                if(nums[i] == nums[i+1]){
                    result[count] = nums[i]*2;
                    i++;
                }else{
                    result[count] = nums[i];
                }
                count++;
            }
        }
        if(i != nums.size()){
            result[count] = nums[nums.size()-1];
        }
        return result;
    }
};