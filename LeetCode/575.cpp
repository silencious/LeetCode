#include <vector>
#include <bitset>
using namespace std;

class DistributeCandies {
public:
	int distributeCandies(vector<int>& candies) {
		int arr[200001];
		memset(arr, 0, sizeof(arr));
		for(int n:candies){
			arr[n+100000]++;
		}
		size_t count=0;
		for(int i=0;i<200001;i++){
			if(arr[i]>0) count++;
		}
		return min(count, candies.size()/2);
	}
	int distributeCandies2(vector<int>& candies) {
		bitset<200001> bs;
		size_t count=0;
		for(int n:candies){
			if(!bs[n+100000]){
				bs.set(n+100000);
				count++;
			}
		}
		return min(count, candies.size()/2);
	}
};