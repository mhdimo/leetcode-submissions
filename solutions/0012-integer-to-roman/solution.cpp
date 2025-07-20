class Solution {
public:
    string intToRoman(int num) {
        if(num == 0) return "0";

        static constexpr std::array<int, 13> arr = {1000, 900, 500, 400, 100, 90 ,50 ,40 ,10, 9, 5, 4, 1};
        static constexpr std::array<const char*, 13> str = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};


        string result = "";

        for(int i = 0; i < arr.size(); i++){

            int times = num / arr[i];

            for(int j= 0; j < times; j++){
                result.append(str[i]);
            }

            num = num % arr[i];
        }
        return result;
    }
};