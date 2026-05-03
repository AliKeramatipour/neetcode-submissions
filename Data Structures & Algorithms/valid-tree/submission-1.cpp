class Solution {
public:
    vector<int> par{vector<int>(1000000, -1)};
    bool dfs(int v, vector<vector<int>>& edges, int prr)
    {
        if (prr == -1)
            par[v] = -1;
        if (par[v] != -1 )
            return false;
        par[v] = prr;

        for (int neighbour: edges[v])
        {
            if (neighbour == par[v])
                continue;
            if (!dfs(neighbour, edges, v))
                return false;
        }

        if (v == 0)
        {

        }
        return true;

    }
    bool validTree(int n, vector<vector<int>>& edges) {
        int e = edges.size();
        vector<vector<int>> humanEdges(n);
        
        for (vector<int>& e: edges)
        {
            int v = e[0];
            int u = e[1];
            humanEdges[u].push_back(v);
            humanEdges[v].push_back(u);
        }

        if (e != n - 1)
            return false;
        
        par[0] = -1;
        bool res = dfs(0, humanEdges, -1);

        for (int i = 1; i < n; i++)
            if (par[i] == -1)
                return false;
        return res;
    }
};
