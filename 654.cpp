#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class MaximumBinaryTree {
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
class MaximumBinaryTree2 {
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		vector<TreeNode*> stack;
		for(int i=0;i<nums.size();i++){
			TreeNode* cur=new TreeNode(nums[i]);
			while(!stack.empty()&&stack.back()->val<nums[i]){
				cur->left=stack.back();
				stack.pop_back();
			}
			if(!stack.empty()){
				stack.back()->right=cur;
			}
			stack.push_back(cur);
		}
		return stack.front();
	}
};