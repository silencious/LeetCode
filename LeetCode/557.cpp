#include <string>
#include <sstream>
using namespace std;

class ReverseWords {
public:
	string reverseWords(string s) {
		stringstream ss(s);
		string ret, temp;
		while(ss>>temp){
			ret+=reverseString(temp);
			ret+=" ";
		}
		return ret.substr(0,ret.length()-1);
	}
	string reverseString(string s){
		int n=s.length();
		for(int i=0;i<n/2;i++){
			int j=n-1-i;
			swap(s[i],s[j]);
		}
		return s;
	}
	// not much faster, just neat code
	string reverseWords2(string s){
		for(int i=0;i<s.length();i++){
			if(s[i]==' ') continue;
			int j=i;
			while(j<s.length() && s[j]!=' ') j++;
			reverse(s.begin()+i, s.begin()+j);
			i=j-1;
		}
		return s;
	}
};