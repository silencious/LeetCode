#include <vector>
#include <unordered_map>
using namespace std;
class TwoSum {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ret(2);
		int i=0,j=1,n=nums.size();
		for(;i<n;i++){
			for(j=i+1;j<n;j++){
				if(nums[i]+nums[j]==target){
					ret[0]=i;
					ret[1]=j;
					return ret;
				}
			}
		}
		return ret;
	}
	vector<int> twoSumHash(vector<int>& nums, int target) {
		unordered_map<int, int> map;
		vector<int> ret(2);
		int n=nums.size();
		for(int i=0;i<n;i++){
			int comp=target-nums[i];
			if(map.find(comp)!=map.end()){
				ret[0]=map[comp];
				ret[1]=i;
				break;
			}else{
				map[nums[i]]=i;
			}
		}
		return ret;
	}
};