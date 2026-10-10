class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        size_t count = 0;
        if (words.empty()) return 0;
    
        for (const auto& word : words) {
            // Bottleneck: We are checking every single string in a large array
            // even though it is sorted. This is O(N * L).
            if (word.compare(0, pref.size(), pref) == 0) {
                count++;
            }
        }
        return count;
        }
};