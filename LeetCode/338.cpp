#include <vector>
using namespace std;
class CountBits {
public:
	vector<int> countBits(int num) {
		vector<int> v(num+1,0);
		int x=0;
		for(int i=1;i<num;i+=2){
			v[i]=v[i-1]+1;
			v[i+1]=v[i/2+1];
		}
		v[num]=(num%2)?v[num-1]+1:v[num];
		return v;
	}
	vector<int> countBits2(int num) {
		vector<int> v(num+1,0);
		int x=0;
		for(int i=1;i<=num;i++){
			v[i]=v[i&(i-1)]+1;
		}
		return v;
	}
};