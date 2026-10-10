class Solution {
public:
    string longestPalindrome(string &s) {
        if(s.empty()){
            return "";
        }

        int start = 0;
        int end   = 0;

        for(int i = 0; i < s.length(); i++){
            int odd = expand(s, i ,i );
            int even = expand(s, i ,i+1);
            int maxlen =  max(odd, even);

            if(maxlen > end-start){
                start = i - (maxlen - 1) /2;
                end = i + maxlen /2;
            }
        }

        return s.substr(start, end-start+1);
    }


    int expand(string &s, int r, int l){
        while(l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;
    }
};