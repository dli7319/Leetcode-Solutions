class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int canPlant = 0;
        int flowerbedSize = flowerbed.size();
        for (int i = 0; i < flowerbedSize; i++) {
            if (flowerbed[i] == 0) {
                if (i == flowerbedSize - 1 || flowerbed[i+1] == 0) {
                    canPlant++;
                    i++;
                }
            } else if (flowerbed[i] == 1) {
                i++;
            }
        }
        return n <= canPlant;
    }
};
