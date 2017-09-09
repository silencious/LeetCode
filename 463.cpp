#include <vector>
using namespace std;

class IslandPerimeter {
public:
	int islandPerimeter(vector<vector<int> >& grid) {
		int r=grid.size(), c=grid[0].size(), ret = 0;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(grid[i][j]==1){
					ret+=4;
					if(i+1<r&&grid[i+1][j]==1) ret-=2;
					if(j+1<c&&grid[i][j+1]==1) ret-=2;
				}
			}
		}
		return ret;
	}
};