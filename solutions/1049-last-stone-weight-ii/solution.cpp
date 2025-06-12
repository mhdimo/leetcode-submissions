class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
            // --- Step 1: Calculate the total weight of all stones ---
    int totalWeight = std::accumulate(stones.begin(), stones.end(), 0);

    // --- Step 2: Define the target for one of the two piles ---
    // Our goal is to find a subset of stones whose sum is as close
    // as possible to half of the total weight.
    int targetSum = totalWeight / 2;

    // --- Step 3: Find all achievable subset sums up to the target ---
    // `canAchieveSum[j]` will be true if a sum of `j` is possible.
    std::vector<bool> canAchieveSum(targetSum + 1, false);
    
    // It's always possible to achieve a sum of 0 (by picking no stones).
    canAchieveSum[0] = true;

    // For each stone, update the sums we can now achieve.
    for (int stoneWeight : stones) {
        // We loop backward to ensure each stone is used at most once per subset.
        for (int j = targetSum; j >= stoneWeight; j--) {
            if (canAchieveSum[j - stoneWeight]) {
                canAchieveSum[j] = true;
            }
        }
    }

    // --- Step 4: Find the largest sum we achieved that is closest to our target ---
    int closestSumToOnePile = 0;
    for (int j = targetSum; j >= 0; j--) {
        if (canAchieveSum[j]) {
            // Since we are looping down from the target, the first sum we
            // find is the largest possible one. This is our best fit.
            closestSumToOnePile = j;
            break;
        }
    }
    
    // --- Step 5: Calculate the final minimum difference ---
    // The other pile's weight is (totalWeight - closestSumToOnePile).
    // The difference is (totalWeight - closestSumToOnePile) - closestSumToOnePile.
    return totalWeight - 2 * closestSumToOnePile;
    }
};