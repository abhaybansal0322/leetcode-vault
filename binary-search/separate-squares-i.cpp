class Solution {

    bool check(double mid,vector<vector<int>>& squares,double tot) {
        
        double bott = 0;
        for(auto& sq : squares) {

            double x = sq[0];
            double y = sq[1];
            double l = sq[2];

            double topy = y+l;

            if(mid >= topy) {

                bott += l*l;
            }
            else if(mid>y) {

                bott += l*(mid-y);
            }
        }

        return (bott >= tot/2.0);
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        
        double l = INT_MIN;
        double h = INT_MAX;
        double total = 0;

        for(auto& sq : squares) {

            double l = sq[2];
            total += l*l;
        }

        double result = 0;

        while(h-l > 0.00001) {

            double mid = l + (h-l)/2.0;

            result = mid;
            if(check(mid,squares,total)) {

                h = mid;
            }
            else {

                l = mid;
            }
        }

        return result;
    }
};