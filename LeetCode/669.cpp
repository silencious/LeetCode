#include <iostream>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class TrimBST {
public:
	TreeNode* trimBST(TreeNode* root, int L, int R) {
		if(root==NULL) return NULL;
		int val = root->val;
		if(val<L){
			return trimBST(root->right, L, R);
		}else if(val>R){
			return trimBST(root->left, L, R);
		}else{
			root->left = trimBST(root->left, L, R);
			root->right = trimBST(root->right, L, R);
		}
		return root;
	}
};