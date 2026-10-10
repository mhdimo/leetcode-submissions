class Solution {
public:
    bool canEat(vector<int> &piles, int h, int k){
        long long hours = 0;
        for(auto pile:piles){
            hours += (pile + k - 1) / k;
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int ans = r;

        while ( l < r ) {
            int mid = l + (r - l) / 2;
            if (canEat(piles, h, mid)){
                ans = mid;
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};