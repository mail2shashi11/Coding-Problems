class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int startX = -1, startY = -1;
        vector<pair<int, int>> litterPos;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    startX = i;
                    startY = j;
                } else if (classroom[i][j] == 'L') {
                    litterPos.push_back({i, j});
                }
            }
        }
        
        int numLitter = litterPos.size();
        int fullMask = (1 << numLitter) - 1;
        if (numLitter == 0) return 0;
        
        vector<vector<int>> litterIdx(m, vector<int>(n, -1));
        for (int i = 0; i < numLitter; ++i) {
            litterIdx[litterPos[i].first][litterPos[i].second] = i;
        }
        
        // bestEnergy[r][c][mask] stores maximum energy seen for each state
        vector<vector<vector<int>>> bestEnergy(
            m, vector<vector<int>>(n, vector<int>(1 << numLitter, -1)));
        
        queue<tuple<int, int, int, int>> q;
        q.push({startX, startY, 0, energy});
        bestEnergy[startX][startY][0] = energy;
        
        int steps = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, mask, e] = q.front();
                q.pop();
                
                if (mask == fullMask) return steps;
                if (e == 0) continue;
                
                for (auto& d : dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X') {
                        continue;
                    }
                    
                    int nextE = e - 1;
                    char cell = classroom[nr][nc];
                    
                    if (cell == 'R') {
                        nextE = energy;
                    }
                    
                    int nextMask = mask;
                    if (cell == 'L') {
                        nextMask |= (1 << litterIdx[nr][nc]);
                    }
                    
                    if (nextE > bestEnergy[nr][nc][nextMask]) {
                        bestEnergy[nr][nc][nextMask] = nextE;
                        q.push({nr, nc, nextMask, nextE});
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};