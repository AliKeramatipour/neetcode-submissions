class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        int n = nums.size();
        for (int i = 0; i < k; i++)
            s.insert(-nums[i]);
        vector<int> res;
        res.push_back(-(*s.begin()));
        for (int end = k; end < n; end++)
        {
            int rem = end - k;
            s.erase(s.find(-nums[rem]));
            s.insert(-nums[end]);
            res.push_back(-(*s.begin()));
        }
        for (auto x: res)
            cout << x << " ";
        return res;
    }
};
