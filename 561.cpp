#include <vector>
using namespace std;

class ArrayPartitionI {
public:
	int arrayPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int sum=0;
		for(int i=0;i<nums.size();i+=2){
			sum+=nums[i];
		}
		return sum;
	}
	int arrayPariSum2(vector<int>& nums) {	// slower
		vector<int> bucket(20001,0);
		for(int n:nums){
			bucket[n+10000]++;
		}
		int sum=0, flag=0;
		for(int i=0;i<20001;){
			if(bucket[i]>0){
				if(flag==0){
					sum+=(i-10000);
					bucket[i]--;
					flag=1;
				}else{
					bucket[i]--;
					flag=0;
				}
			}else{
				i++;
			}
		}
		return sum;
	}
};