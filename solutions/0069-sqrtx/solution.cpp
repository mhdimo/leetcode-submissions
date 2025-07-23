class Solution {
public:
    int mySqrt(int x) {
        long long L =1;
        long long R = x;

        while( L<=R){
            long long M = (L+R)/2;
            long long M_Squared = M*M;

            if(M_Squared == x){
                return M;
            } else if(M_Squared < x){
                L = M+1;
            } else{
                R = M-1;
            }
        }
        return R;
    }
};