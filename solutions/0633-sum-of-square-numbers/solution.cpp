class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 1) return true;
        long long a = 0;
        long long b = (long long)sqrt(c);

        while(a <=b){
            long long sum = a*a + b*b;
            
            if(sum == c){
                return true;
            } else if(sum < c){
                a++;                
            } else { 
                b--;
            }
        }
        
        return false;
    }
};