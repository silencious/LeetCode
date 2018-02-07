#include <string>
#include <sstream>
using namespace std;

class ComplexNumberMultiplication {
public:
	string complexNumberMultiply(string a, string b) {
		stringstream ss1(a), ss2(b);
		int ax, ay, bx, by;
		char ch;
		ss1>>ax>>ch>>ay;
		ss2>>bx>>ch>>by;
		int cx=ax*bx-ay*by, cy=ax*by+ay*bx;
		return to_string(cx)+'+'+to_string(cy)+'i';
	}
};