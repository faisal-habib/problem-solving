/*
Idea:
- if last position is 0,0 then there's circle
Otherwise
- if last direction is north(up), there's no circle. Cause it'll keep going up from last position
- else there's a circle. Cause after turing around 1 or 3 times, it'll come to it's previous position
*/

class Solution {
public:
    bool isRobotBounded(string instructions) {
        // up, right, down, left
        int dirX[4] = {0, 1, 0, -1};
        int dirY[4] = {1, 0, -1, 0};

        int instructionsSz = instructions.size();

        int currX = 0, currY = 0;
        int dirInd = 0; // facing north (up)


        for(int i = 0; i < instructionsSz; i++) {
            if(instructions[i] == 'G') {
                currX += dirX[dirInd];
                currY += dirY[dirInd];
            }
            else if(instructions[i] == 'L') {
                dirInd += 3;
                dirInd %= 4;
            }
            else {
                dirInd += 1;
                dirInd %= 4;
            }
        }

        if((currX == 0 && currY == 0) || dirInd != 0) return true;

        return false;
    }
};
