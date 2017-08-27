#include <vector>
#include <string>
#include <set>
using namespace std;

class KeyboardRow {
public:
	vector<string> findWords(vector<string>& words) {
		string r1="qwertyuiopQWERTYUIOP", r2="asdfghjklASDFGHJKL", r3="zxcvbnmZXCVBNM";
		set<char> s1,s2,s3;
		for(char c:r1) s1.insert(c);
		for(char c:r2) s2.insert(c);
		for(char c:r3) s3.insert(c);
		vector<string> ret;
		for(string s:words){
			char ch = s[0];
			bool match=true;
			set<char>* st=&s1;
			if(s2.find(ch)!=s2.end()) st=&s2;
			else if(s3.find(ch)!=s3.end()) st=&s3;
			for(char ch:s){
				if(st->find(ch)==st->end()){
					match=false;
					break;
				}
			}
			if(match) ret.push_back(s);
		}
		return ret;
	}
};