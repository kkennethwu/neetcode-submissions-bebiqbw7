class Solution {
private:
    using Pair = pair<int, char>; // freq, task
public:
    int leastInterval(vector<char>& tasks, int n) {
        auto cmp = [](Pair& a, Pair& b) {
            return a.first < b.first;
        }; // acutally, using default comparator is also fine.
        priority_queue<Pair, vector<Pair>, decltype(cmp)> pq(cmp);

        // put tasks into priority queue accroding to task frequency
        vector<int> hashMap(26, 0);
        for (const auto& task : tasks) {
            hashMap[task - 'A']++;
        }
        for (int i = 0; i < 26; i++) {
            if (!hashMap[i]) continue; 
            pq.push({hashMap[i], 'A' + i});
        }

        queue<pair<int, Pair>> q; // to store cool down tasks
        int curTime = 0;
        while (!pq.empty() || !q.empty()) {
            if (!q.empty()) {
                if (curTime - q.front().first > n) {
                    auto tmp = q.front(); q.pop();
                    pq.push(tmp.second);
                }
            }

            if (!pq.empty()) {
                auto cur = pq.top(); pq.pop();
                cur.first--; // freq

                if (cur.first) {
                    q.push({curTime, cur});
                }
            }
            curTime++; // increase time either do task or idle
        }
        return curTime;
    }
};
