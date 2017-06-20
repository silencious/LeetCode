#include <vector>
#include <deque>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class LargestValues {
public:
	vector<int> largestValues(TreeNode* root){
		if(root==NULL){
			vector<int> v;
			return v;
		}
		vector<int> ret;
		if(root->left==NULL){
			ret = largestValues(root->right);
		}else if(root->right==NULL){
			ret = largestValues(root->left);
		}else{
			vector<int> v1=largestValues(root->left),v2=largestValues(root->right);
			ret = maxVec(v1,v2);
		}
		reverse(ret.begin(),ret.end());
		ret.push_back(root->val);
		reverse(ret.begin(),ret.end());
		return ret;
	}
	vector<int> maxVec(vector<int>& v1,vector<int>& v2){
		if(v1.size()<v2.size()){
			swap(v1,v2);
		}
		for(int i=0;i<v2.size();i++){
			if(v1[i]<v2[i]){
				v1[i]=v2[i];
			}
		}
		return v1;
	}
	vector<int> largestValues2(TreeNode* root){
		vector<int> v(0);
		helper2(root,v,0);
		return v;
	}
	void helper2(TreeNode* node, vector<int>& v, int d){
		if(node==NULL) return;
		if(d==v.size()){
			v.push_back(node->val);
		}else{
			v[d]=max(v[d],node->val);
		}
		helper2(node->left,v,d+1);
		helper2(node->right,v,d+1);
	}
	vector<int> sol;
	vector<int> largestValues3(TreeNode* root){
		helper3(root,0);
		return sol;
	}
	void helper3(TreeNode* node, int d){
		if(node==NULL) return;
		if(d==sol.size()){
			sol.push_back(node->val);
		}else if(sol[d]<node->val){
			sol[d]=node->val;
		}
		helper3(node->left,d+1);
		helper3(node->right,d+1);
	}
};