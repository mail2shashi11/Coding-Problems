class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> occupied;
        
        // Map reserved seats to a bitmask per row
        for (const auto& seat : reservedSeats) {
            occupied[seat[0]] |= (1 << seat[1]);
        }
        
        // Base count for rows with zero reservations
        int totalGroups = (n - occupied.size()) * 2;
        
        // Process only rows with reserved seats
        for (const auto& [row, mask] : occupied) {
            bool left   = !(mask & (1 << 2 | 1 << 3 | 1 << 4 | 1 << 5)); // seats 2..5
            bool middle = !(mask & (1 << 4 | 1 << 5 | 1 << 6 | 1 << 7)); // seats 4..7
            bool right  = !(mask & (1 << 6 | 1 << 7 | 1 << 8 | 1 << 9)); // seats 6..9
            
            if (left && right) {
                totalGroups += 2;
            } else if (left || right || middle) {
                totalGroups += 1;
            }
        }
        
        return totalGroups;
    }
};