class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string snum = to_string(num);
        int count = 0;

        for (int i = 0; i <= snum.length() - k; i++) {
            string sub = snum.substr(i, k);
            int val = stoi(sub);

            if (val != 0 && num % val == 0) {
                count++;
            }
        }

        return count;
    }
};
