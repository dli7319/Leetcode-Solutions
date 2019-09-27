class Solution {
private:
    int normalizeDir(int currentDir, int deltaDir) {
        return (currentDir + deltaDir + 10 * 4) % 4;
    }
    void moveForward(int *pos, int dir) {
        if (dir == 0) {
            pos[1]++;
        } else if (dir == 1) {
            pos[0]++;
        } else if (dir == 2) {
            pos[1]--;
        } else if (dir == 3) {
            pos[0]--;
        }
    }
    void moveForward(int *pos, int dir, int steps) {
        if (dir == 0) {
            pos[1]+=steps;
        } else if (dir == 1) {
            pos[0]+=steps;
        } else if (dir == 2) {
            pos[1]-=steps;
        } else if (dir == 3) {
            pos[0]-=steps;
        }
    }
public:
    bool isRobotBounded(string instructions) {
        int pos[2] = {0, 0};
        int dir = 0;
        for (int i = 0; i < instructions.length(); i++) {
            char instr = instructions.at(i);
            if (instr == 'G') {
                moveForward(pos, dir);
            } else if (instr == 'L') {
                dir = normalizeDir(dir, -1);
            } else if (instr == 'R') {
                dir = normalizeDir(dir, 1);
            }
        }
        int netPos[2];
        netPos[0] = pos[0];
        netPos[1] = pos[1];
        int netDir = dir;
        for (int i = 0; i < 3; i++) {
            moveForward(pos, (dir + 0) % 4, netPos[1]);
            moveForward(pos, (dir + 1) % 4, netPos[0]);
            dir = normalizeDir(dir, netDir);
        }
        return pos[0] == 0 && pos[1] == 0;
    }
};
