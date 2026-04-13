class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = -1;
        // 1  2  3  4
        // 2  2  4  1
        // -1 0  1  3

        // -4 0 1 3
        // -1 -1 1
        int n = gas.size();
        int earn = 0, total = 0;
        int maxGas = 0, maxGasIdx = 0;

        for (int i = 0; i < n; i++) {
            earn += (gas[i] - cost[i]);
            total += (gas[i] - cost[i]);
            if (earn < 0) {
                earn = 0;
                maxGasIdx = (i + 1) % n;
            }
        }
        return (total >= 0) ? maxGasIdx : -1;
    }
};
