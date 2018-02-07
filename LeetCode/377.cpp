#include <vector>
using namespace std;

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		int ret = 0, n = nums.size();
		vector<int> v(target+1,0);
		v[0]=1;
		for(int i=1;i<=target;i++){
			for(int j=0;j<n;j++){
				int x=nums[j];
				if(i-x>=0){
					v[i]+=v[i-x];
				}
			}
		}
		return v[target];
	}
};