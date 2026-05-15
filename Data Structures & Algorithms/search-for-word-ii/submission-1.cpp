vector< pair<int,int> > neighbours {{0,-1}, {0, 1}, {1, 0}, {-1,0}};

class Solution {
public:

    void find(int l, int r, string w, vector<string>& words, vector<vector<char>>& board, vector<vector<bool>>& seen, int x, int y, vector<bool>& found)
    {
        int rows = board.size();
        int cols = board[0].size();
        string wn = w + board[x][y];

        // advance l past words too small to still match
        while (l <= r && words[l] < wn) l++;
        // retract r past words that don't start with wn
        while (l <= r && words[r].compare(0, wn.size(), wn) != 0) r--;
        if (l > r) return;

        if (words[l] == wn)
            found[l] = true;

        seen[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + neighbours[i].first;
            int ny = y + neighbours[i].second;
            if (nx < 0 || ny < 0 || nx >= rows || ny >= cols)
                continue;
            if (seen[nx][ny]) continue;

            find(l, r, wn, words, board, seen, nx, ny, found);
        }

        seen[x][y] = 0;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        sort(words.begin(), words.end());
        int n = words.size();
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> seen(rows, vector<bool>(cols, false));
        vector<bool> found(n, false);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                find(0, n-1, "", words, board, seen, i, j, found);
            }
        }
        vector<string> res;
        for (int i = 0; i < n; i++)
        {
            if (found[i])
                res.push_back(words[i]);
        }
        return res;
    }
};