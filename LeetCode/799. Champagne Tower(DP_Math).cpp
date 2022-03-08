/*
Problem link:
https://leetcode.com/problems/champagne-tower/
*/

/*
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double champagneInGlass[101][101] = {0.0};
        champagneInGlass[0][0] = (double) poured;   // all champagne will be poured in top glass first
        
        for(int row = 0; row < 100; row++) {
            for(int glass = 0; glass <= row; glass++) {
                // it'll keep 1 glass, then devide the rest in 2 glass of below row
                
                if (champagneInGlass[row][glass] >= 1) {
                    champagneInGlass[row+1][glass] += (champagneInGlass[row][glass] - 1.0) / 2.0;
                    champagneInGlass[row+1][glass+1] += (champagneInGlass[row][glass] - 1.0) / 2.0;
                    
                    champagneInGlass[row][glass] = 1.0; // can't contain more than 1 glass, rest will flow to below glasses
                }
            }
        }
        
        return champagneInGlass[query_row][query_glass];
    }
};
*/

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double champagneInGlass[101][101] = {0};
        champagneInGlass[0][0] = (double) poured;   // all champagne will be poured in top glass first
        
        for(int row = 0; row < 100; row++) {
            for(int glass = 0; glass <= row; glass++) {
                double remainingChampagne = (champagneInGlass[row][glass] - 1.0) / 2.0;    // it'll keep 1 glass, then devide the rest in 2 glass of below row
                
                if (remainingChampagne > 0) {
                    champagneInGlass[row+1][glass] += remainingChampagne;
                    champagneInGlass[row+1][glass+1] += remainingChampagne;
                }
            }
        }
        
        // can't contain more than 1 glass, restl will flow to below glasses
        return min(1.0, champagneInGlass[query_row][query_glass]);
    }
};
