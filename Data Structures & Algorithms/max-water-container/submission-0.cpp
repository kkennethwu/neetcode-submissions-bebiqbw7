class Solution {
public:
    int maxArea(vector<int>& heights) {\
        int ans = 0;
        int front = 0, back = heights.size() - 1;
        int cnt = 0;
        while(front < back) {
            int v = (back - front) * min(heights[front], heights[back]);
            ans = max(ans, v);
            if (heights[front] <= heights[back]) {
                front++;
            }
            else back--;
        }
        return ans;
    }
};
