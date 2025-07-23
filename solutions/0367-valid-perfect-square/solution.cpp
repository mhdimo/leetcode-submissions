class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;

        long long n = 1;
        while(n*n <= num){
            if(n*n == num){
                return true;
            }
            n++;
        }
        return false;
    }
};