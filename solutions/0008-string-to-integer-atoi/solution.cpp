#include <cstring>

class Solution {
public:
    int myAtoi(string s) {

        int i = 0, n = s.size();
        while (i < n && s[i] == ' ') i++; // skip leading spaces

        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            if (sign * result >= INT32_MAX)
                return INT32_MAX;
            if (sign * result <= INT32_MIN)
                return INT32_MIN;
            i++;
        }

        return static_cast<int>(sign * result);
    }
};