class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        vector<pair<int,int> > lh;
        vector<pair<int,int> > rh;
        int mx = -1;
        for (int i = 0; i < n; i++)
        {
            if (heights[i] <= mx) continue;
            auto x = make_pair(heights[i] , i);
            mx = heights[i];
            lh.push_back(x);
        }

        mx = -1;
        for (int i = n-1; i >= 0; i--)
        {
            if (heights[i] <= mx) continue;
            auto x = make_pair(heights[i] , i);
            mx = heights[i];
            rh.push_back(x);
        }

        for (auto x: lh)
        {
            cout << x.first << " ";
        }
        cout << endl;

        int sz = lh.size();
        long long ans = 0;
        int pointer = 0;
        for (auto bar: rh)
        {
            int barHeight = bar.first;
            int barLoc = bar.second;
            while (pointer < sz && lh[pointer].first < barHeight)
                pointer++;
            if (pointer == sz)
                break;
            
            long long width = abs(barLoc - lh[pointer].second);
            ans = max(ans, barHeight * width);
        }

        sz = rh.size();
        pointer = 0;
        for (auto bar: lh)
        {
            int barHeight = bar.first;
            int barLoc = bar.second;
            while (pointer < sz && rh[pointer].first < barHeight)
                pointer++;
            if (pointer == sz)
                break;
            
            long long width = abs(barLoc - rh[pointer].second);
            ans = max(ans, barHeight * width);
        }

        return ans;
    }
};
