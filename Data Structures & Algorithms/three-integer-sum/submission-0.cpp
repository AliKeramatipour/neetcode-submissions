class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        map<int,int> mp;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(nums[i]) == mp.end())
            {
                mp[nums[i]] = 1;
                continue;
            }
            mp[nums[i]]++;
        }

        set< tuple<int,int,int> > results;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if ( i == j) continue;
                int a = nums[i];
                int b = nums[j];
                if (b < a) continue;
                int c = 0 - a - b;
                if (mp.find(c) == mp.end())
                    continue;
                int cnt = mp[c];
                cout << a << " " << b << " - " << c << " : " << cnt << endl;
                if ( a == c )
                    cnt--;
                if ( b == c)
                    cnt--;
                cout << " cnt after check " << cnt << endl;
                if (cnt > 0)
                {
                    tuple<int,int,int> sorted_tuple;
                    // a <= b
                    if (c >= b)
                    {
                        sorted_tuple = make_tuple(a,b,c);
                    }
                    else if (c <= a)
                    {
                        sorted_tuple = make_tuple(c,a,b);
                    } else 
                        sorted_tuple = make_tuple(a,c,b);
                    results.insert(sorted_tuple); 
                }
                               
            }
        
        for (auto x: results)
        {
            auto [a,b,c] = x;
            vector<int> v = {a,b,c};
            ans.push_back(v);
        }
        return ans;
    }
};
