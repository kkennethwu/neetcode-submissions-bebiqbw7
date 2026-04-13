class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> Q; // min heap
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int n : nums) {
            Q.push(n);
            if (Q.size() > k) Q.pop();
        }
    }
    
    int add(int val) {
        Q.push(val);
        if (Q.size() > k) Q.pop();
        return Q.top();
    }
};
