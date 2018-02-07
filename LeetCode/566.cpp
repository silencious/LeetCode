#include <vector>
using namespace std;

class MatrixReshape {
public:
	vector<vector<int> > matrixReshape(vector<vector<int> >& nums, int r, int c) {
		int r1=nums.size(), c1=nums[0].size();
		if(r1*c1!=r*c) return nums;
		vector<vector<int> > ret;
		int i1=0, j1=0;
		for(int i=0; i<r; i++){
			vector<int> v(c);
			for(int j=0; j<c; j++){
				v[j]=nums[i1][j1];
				if(j1==(c1-1)){
					j1=0;
					i1++;
				}else{
					j1++;
				}
			}
			ret.push_back(v);
		}
		return ret;
	}
	vector<vector<int> > matrixReshape2(vector<vector<int> >& nums, int r, int c) {
		int x=nums.size(), y=nums[0].size(), n=x*y;
		if(n!=r*c) return nums;
		vector<vector<int> > ret(r, vector<int>(c));
		for(int i=0;i<n;i++) ret[i/c][i%c]=nums[i/y][i%y];
		return ret;
	}
};