class Solution {
public:
    string makeFancyString(string s) {
        if (s.empty()) return s;
        int write = 1;
        int count = 1;

        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i - 1]){
                ++count;
            }else{
                count = 1;
            }

            if(count <=2){
                s[write++] = s[i];
            }
        }

        s.resize(write);
        return s;
    }
};