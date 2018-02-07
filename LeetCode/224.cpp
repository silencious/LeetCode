#include <string>
#include <vector>
using namespace std;

class Calculatorr {
public:
	int calculate(string s) {
		int result = 0;
		int num = 0;
		int sign = 1;
		vector<int> stack;
		for(int i=0;i<s.length();i++){
			char ch = s[i];
			if(ch>='0'&&ch<='9'){
				num = num*10+(ch-'0');
			}else if(ch=='+'){
				result+=sign*num;
				sign = 1;
				num = 0;
			}else if(ch=='-'){
				result+=sign*num;
				sign = -1;
				num = 0;
			}else if(ch=='('){
				stack.push_back(result);
				stack.push_back(sign);
				result = 0;
				sign = 1;
			}else if(ch==')'){
				num=result+sign*num;
				sign = stack[stack.size()-1];
				result = stack[stack.size()-2]+sign*num;
				num=0;
				stack.pop_back();
				stack.pop_back();
			}
		}
		if(num!=0) result+=sign*num;
		return result;
	}
};