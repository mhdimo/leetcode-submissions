class Solution {
public:
    inline vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = 0;

        right = numbers.size() -1;

        while (left < right){
            int total = numbers[left] + numbers[right];
            
            if (total == target){
                return {left + 1, right +1};
            }
            
            if(total > target){
                right--;
            } else {
                left++;
            }

            
        }

        return {-1,-1};
        }
};