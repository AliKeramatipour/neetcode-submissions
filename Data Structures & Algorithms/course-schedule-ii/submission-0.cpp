class Solution {
public:

    void dfs(int v, vector<vector<int>>& edges, bool& hasCycle, vector<int>& state, vector<int>& order)
    {
        cout << " calling ? " << v << endl;
        if (state[v] == 1)
        {
            hasCycle = true;
            cout << " wtf ? " << v << endl;
            return;
        }
        if (state[v] == 2)
            return;

        state[v] = 1;
        for (int u: edges[v])
        {
            cout << " here edge is " << v << " -> " << u << endl;
            dfs(u, edges, hasCycle, state, order);
        }

        order.push_back(v);
        state[v] = 2;

        return;
    }
    

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {

        cout << " n is " << n << endl;
        bool hasCycle = false;
        vector<vector<int>> edges;
        vector<int> state(n);
        vector<int> order;
        for (int i = 0; i < n; i++)
        {
            edges.push_back({});
            state[i] = 0;
        }

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            edges[v].push_back(u);
        }

        for (int i = 0; i < n; i++) if (state[i] == 0) dfs(i, edges, hasCycle, state, order);

        if (hasCycle)
            return {};

        reverse(order.begin(), order.end());
        
        return order;

    }
};
