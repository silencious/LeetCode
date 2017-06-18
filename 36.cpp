#include <vector>
using namespace std;
class ValidSudoku {
public:
	bool isValidSudoku(vector<vector<char> >& board) {
		for(int i=0;i<9;i++){
			vector<char>& v=board[i];
			vector<bool> rec(9,false);
			for(int j=0;j<9;j++){
				if(v[j]!='.'){
					int x=v[j]-'1';
					if(rec[x]) return false;
					rec[v[j]-'1']=true;
				}
			}
		}
		for(int j=0;j<9;j++){
			vector<bool> rec(9,false);
			for(int i=0;i<9;i++){
				char ch = board[i][j];
				if(ch!='.'){
					if(rec[ch-'1']) return false;
					rec[ch-'1']=true;
				}
			}
		}
		for(int k=0;k<9;k++){
			vector<bool> rec(9,false);
			int x=k%3,y=k/3;
			for(int i=x*3;i<x*3+3;i++){
				for(int j=y*3;j<y*3+3;j++){
					char ch = board[i][j];
					if(ch!='.'){
						if(rec[ch-'1']) return false;
						rec[ch-'1']=true;
					}
				}
			}
		}
		return true;
	}
	bool isValidSudoku2(vector<vector<char> >& board) {
		bool rec1[9][9]={false},rec2[9][9]={false},rec3[9][9]={false};
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				char ch = board[i][j];
				if(ch=='.') continue;
				int v=ch-'1',k=i/3*3+j/3;
				if(rec1[i][v]||rec2[j][v]||rec3[k][v]) return false;
				rec1[i][v]=true;
				rec2[j][v]=true;
				rec3[k][v]=true;
			}
		}
		return true;
	}
};