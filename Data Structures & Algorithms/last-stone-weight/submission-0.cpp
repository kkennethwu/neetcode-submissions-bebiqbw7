class Solution {
public:
    priority_queue<int> Q;
    int lastStoneWeight(vector<int>& stones) {
        for (auto s : stones) {
            Q.push(s);
        }
        while (!Q.empty()) {
            int y = Q.top(); Q.pop();
            int x;
            if (!Q.empty()) {
                x = Q.top();
                Q.pop();
            } else return y;
            if (y > x) {
                Q.push(y - x);
            }
        }
        return 0;
    }
};
