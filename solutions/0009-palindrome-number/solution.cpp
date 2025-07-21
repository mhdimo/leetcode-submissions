class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10==0 && x!=0)) return false;
        string s = to_string(x);

        string sr = s;

        reverse(sr.begin(), sr.end());

        return s == sr ? true : false;
    }
};