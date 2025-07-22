class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // Sort by numberOfUnitsPerBox in descending order
        std::sort(boxTypes.begin(), boxTypes.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] > b[1];
        });
    
        int totalUnits = 0;
    
        for (const auto& box : boxTypes) {
            int boxes = box[0];
            int unitsPerBox = box[1];
    
            int take = std::min(truckSize, boxes);
            totalUnits += take * unitsPerBox;
            truckSize -= take;
    
            if (truckSize == 0) break;
        }
    
        return totalUnits;
    }
};