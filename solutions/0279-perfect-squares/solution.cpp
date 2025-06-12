class Solution {
public:
    int numSquares(int n) {
        if (n <= 0 ) return 0;

       static vector<int> cntperfectsquare({0});

       while(cntperfectsquare.size() <=n){
        int cntsquare = INT_MAX;

        for(int i = 1; i*i <= cntperfectsquare.size(); i++){
            cntsquare = min(cntsquare, cntperfectsquare[cntperfectsquare.size()-i*i] +1);
        }
        cntperfectsquare.push_back(cntsquare);
       }

       return cntperfectsquare[n];
    }
};