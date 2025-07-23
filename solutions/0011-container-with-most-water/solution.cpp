class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() < 2) return 0;
        int l = 0;
        int r = height.size()-1;
        int maxar = 0;

        while(l < r){
            int leftH = height[l];
            int rightH = height[r];
            maxar = max(maxar, (r - l) * min(leftH, rightH));
            if(height[l] < height[r]){
                l++;
            } else {
                r--;
            }
        }

        return maxar;
    }
};