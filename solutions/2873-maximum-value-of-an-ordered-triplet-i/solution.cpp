class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxvalue = 0;

        for(int i = 0; i < nums.size()-2; i++){
            for(int j = i+1; j < nums.size()-1; j++){
                for(int k = j+1; k < nums.size(); k++){
                    if(i!=j && j!=k && i!=k){
                        long long val = (1LL* nums[i] - nums[j]) * nums[k];
                        maxvalue = std::max(maxvalue, val);
                    }
                }
            }
        }
        return maxvalue;
    }
};