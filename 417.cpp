#include <vector>
using namespace std;

class WaterFlow {
public:
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>> &matrix) {
		vector<pair<int, int>> ret;
		int y = matrix.size();
		if (y == 0)
			return ret;
		int x = matrix[0].size();
		if (x == 0)
			return ret;
		vector<vector<bool>> pac(y, vector<bool>(x, false)), atl(y, vector<bool>(x, false));
		bool rem = true;
		while (rem) {
			rem = false;
			for (int i = 0; i < y; i++) {
				for (int j = 0; j < x; j++) {
					int h = matrix[i][j];
					if (!pac[i][j]) {
						if (i == 0) {
							pac[i][j] = true;
						} else {
							pac[i][j] = pac[i][j] || (pac[i - 1][j] && matrix[i - 1][j] <= h);
						}
						if (j == 0) {
							pac[i][j] = true;
						} else {
							pac[i][j] = pac[i][j] || (pac[i][j - 1] && matrix[i][j - 1] <= h);
						}
						if (i != y - 1) {
							pac[i][j] = pac[i][j] || (pac[i + 1][j] && matrix[i + 1][j] <= h);
						}
						if (j != x - 1) {
							pac[i][j] = pac[i][j] || (pac[i][j + 1] && matrix[i][j + 1] <= h);
						}
						rem = rem || pac[i][j];
					}
					if (!atl[i][j]) {
						if (i == y - 1) {
							atl[i][j] = true;
						} else {
							atl[i][j] = atl[i][j] || (atl[i + 1][j] && matrix[i + 1][j] <= h);
						}
						if (j == x - 1) {
							atl[i][j] = true;
						} else {
							atl[i][j] = atl[i][j] || (atl[i][j + 1] && matrix[i][j + 1] <= h);
						}
						if (i != 0) {
							atl[i][j] = atl[i][j] || (atl[i - 1][j] && matrix[i - 1][j] <= h);
						}
						if (j != 0) {
							atl[i][j] = atl[i][j] || (atl[i][j - 1] && matrix[i][j - 1] <= h);
						}
						rem = rem || atl[i][j];
					}
				}
			}
		}
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				if (pac[i][j] && atl[i][j]) {
					ret.push_back(pair<int, int>(i, j));
				}
			}
		}
		return ret;
	}

	vector<pair<int, int>> pacificAtlanticDFS(vector<vector<int>> &matrix) {
		vector<pair<int, int>> ret;
		int y = matrix.size();
		if (y == 0)
			return ret;
		int x = matrix[0].size();
		if (x == 0)
			return ret;

		vector<vector<bool>> pac(y, vector<bool>(x, false)), atl(y, vector<bool>(x, false));
		for (int j = 0; j < x; j++) {
			dfs(matrix, pac, INT_MIN, 0, j);
			dfs(matrix, atl, INT_MIN, y - 1, j);
		}
		for (int i = 0; i < y; i++) {
			dfs(matrix, pac, INT_MIN, i, 0);
			dfs(matrix, atl, INT_MIN, i, x - 1);
		}
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				if (pac[i][j] && atl[i][j]) {
					ret.push_back(pair<int, int>(i, j));
				}
			}
		}
		return ret;
	}

	int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

	void dfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int h, int i, int j) {
		int x = matrix[0].size(), y = matrix.size();
		if (i < 0 || i >= y || j < 0 || j >= x || visited[i][j] || matrix[i][j] < h)
			return;
		visited[i][j] = true;
		for (int k = 0; k < 4; k++) {
			dfs(matrix, visited, matrix[i][j], i + dir[k][0], j + dir[k][1]);
		}
	}
};