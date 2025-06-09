#include <string>

using namespace std;

class Solution {
public:
    int minimumLength(string &s) {
        int arr[26] = {0}; // C-style array for character frequency

        // Count the frequency of each character
        for (char ch : s) {
            arr[ch - 'a']++;
        }

        int result = 0;

        // Process the frequency array
        for (int i = 0; i < 26; i++) {
            int count = arr[i];
            if (count > 1) {
                result += (count % 2 == 0) ? 2 : 1; // Add 2 for even, 1 for odd
            } else {
                result += count;
            }
        }

        return result;
    }
};
