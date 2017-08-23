#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		TreeNode* root = new TreeNode(nums[0]);
		for(int i=1;i<nums.size();i++){
			int v = nums[i];
			TreeNode* node = new TreeNode(v);
			if(nums[i]>root->val){
				node->left=root;
				root=node;
			}else{
				TreeNode* ptr=root;
				while(ptr->right){
					if(ptr->right->val<v){
						node->left=ptr->right;
						ptr->right=node;
						break;
					}else{
						ptr=ptr->right;
					}
				}
				if(ptr->right==NULL){
					ptr->right=node;
				}
			}
		}
		return root;
	}
};