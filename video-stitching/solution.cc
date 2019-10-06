class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        if (T <= 0) {
            return 0;
        }
        int lowest = T;
        for (int i = 0; i < clips.size(); i++) {
            vector<int>& myClip = clips[i];
            if (myClip[1] >= T && myClip[0] <= lowest) {
                lowest = min(lowest, myClip[0]);
            }
        }
        if (lowest == T) {
            return -1;
        }
        int best = videoStitching(clips, lowest);
        return best >= 0 ? 1 + best : -1;
    }
};
