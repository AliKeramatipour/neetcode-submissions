
typedef pair<int, int> pii;
const int MAXN = 100;
pii par[MAXN][MAXN];
int sz[MAXN][MAXN];

class Solution {    
public:

    void init(int n)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                {
                    pii g = make_pair(i,j);
                    par[i][j] = g;
                    sz[i][j] = 1;
                }
    }

    pii find(pii x)
    {
        while (par[x.first][x.second] != x) {
            pii prrr = par[x.first][x.second];
            par[x.first][x.second] = par[prrr.first][prrr.second]; // path halving
            x = par[x.first][x.second];
        }
        return x;
    }

    bool unite(pii a, pii b) {
        a = find(a); b = find(b);
        if (a == b) return false;

        if (sz[a.first][a.second] < sz[b.first][b.second]) swap(a, b);

        par[b.first][b.second] = a;
        sz[a.first][a.second] += sz[b.first][b.second];
        return true;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        init(n);

        int t = -1;
        
        vector<vector<int>> nodes;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                vector<int> info = {grid[i][j], i, j};
                nodes.push_back(info);
            }
        }

        sort(nodes.begin(), nodes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        int pnt = 0;
        
        vector<pii> dir = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        while (true)
        {
            cout << t << endl;
            while (pnt < nodes.size() && nodes[pnt][0] <= t)
            {
                int x = nodes[pnt][1];
                int y = nodes[pnt][2];
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dir[i].first;
                    int ny = y + dir[i].second;
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n)  continue;
                    if (grid[nx][ny] > t) continue;
                    unite({x,y},{nx,ny});
                }

                pnt++; 
            }
            if (find({0,0}) == find({n-1,n-1})){
                return t;
            }

            t++;
        }

        return 0;
    }
};
