#include <string>
using namespace std;
class ReverseString {
public:
	string reverseString(string s){
		int n=s.length();
		for(int i=0;i<n/2;i++){
			int j=n-1-i;
			swap(s[i],s[j]);
		}
		return s;
	}
};