class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) return s;
        vector<string> rows(numRows);
        int index = 0;
        int d = 1;

        

        for (int i = 0; i < s.size(); i++){
            rows[index].push_back(s[i]);
            if(index == 0){
                d = 1;
            } else if (index == numRows -1){
                d = -1;
            }
            index +=d;
        }

        string result = "";
        for(const string& row : rows) {
            result += row;
        }

        return result;
    }
};