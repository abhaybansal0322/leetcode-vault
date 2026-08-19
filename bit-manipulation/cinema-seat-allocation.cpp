class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        for(auto& reservedSeat : reservedSeats) { 
            int row  = reservedSeat[0];
            int seat = reservedSeat[1];

            mp[row] |= (1 << seat);
        }

        int result = (n - mp.size()) * 2;

        int maskA = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5); 
        int maskB = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7); 
        int maskC = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        for(auto& [row, bookedSeatsMask] : mp) {
            bool graupA = (bookedSeatsMask & maskA) == 0;
            bool graupB = (bookedSeatsMask & maskB) == 0;
            bool graupC = (bookedSeatsMask & maskC) == 0;

            if(graupA && graupC)
                result += 2;
            else if(graupA || graupB || graupC)
                result += 1;

        }

        return result;
    }
};