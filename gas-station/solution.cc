class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> delta(2 * gas.size());
        for (int i = 0; i < gas.size(); i++) {
            delta[i] = gas[i] - cost[i];
            delta[i + gas.size()] = delta[i];
        }
        for (int i = 1; i < delta.size(); i++) {
            delta[i] += delta[i-1];
        }
        for (int i = 0; i < delta.size(); i++) {
            cout << delta[i] << " ";
        }
        vector<int> most_negative(gas.size());
        int smallest = delta[0];
        int smallestIdx = 0;
        for (int i = 0; i < gas.size(); i++) {
            while (smallestIdx + 1 < i + gas.size()) {
                smallestIdx++;
                smallest = min(delta[smallestIdx], smallest);
            }
            if (i == 0) {
                most_negative[i] = 0 - smallest;
            } else {
                most_negative[i] = delta[i - 1] - smallest;
            }
            // cout << most_negative[i] << " ";
        }
        // cout << endl;
        // for (int i = 0; i < gas.size(); i++) {
        //     cout << most_negative[i] << " ";
        // }
        for (int i = 0; i < gas.size(); i++) {
            if (most_negative[i] <= 0) {
                return i;
            }
        }
        // cout << endl;
        return -1;
    }
};
