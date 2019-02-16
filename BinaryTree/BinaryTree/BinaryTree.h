#include <iostream>
#include <vector>
#include <sstream>   //getline 包含在 sstream 中，要include！  
using namespace std;

#define NULL_STR	"null"
const char delimiter = ',';
const char kuohao0 = '[';
const char kuohao1 = ']';

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution {
public:
	bool getStdinStr(string &mstr);
	// 根据前序构建一个二叉树
	TreeNode* preCreatBiTree(TreeNode *tree){
		string c;
		int sint;
		//getStdinStr(c);
		//if(c.compare(DELIMITER) == 0)
			
		if(!getStdinStr(c)){
			return NULL;
		}
		else{
				cout << c << endl;
				sscanf(c.c_str(),"%d",&sint);
				tree = new TreeNode(0);
				tree->val = sint;
				tree->left = preCreatBiTree(tree->left);
				tree->right = preCreatBiTree(tree->right);
		}
		return tree;
	}
	
	// 前序遍历二叉树
	void mypreorderTraversal(TreeNode *root,vector<int> &ret){
		if(root == NULL)
			return;
		// cout << root->val << endl;
		ret.push_back(root->val);
		mypreorderTraversal(root->left,ret);
		mypreorderTraversal(root->right,ret);
	}
	vector<int> preorderTraversal(TreeNode *root){
		vector<int> ret;
		mypreorderTraversal(root,ret);
		return ret;
	}
	void myinorderTraversal(TreeNode *root,vector<int> &ret)
	{
		if(root == NULL)
			return;		
		myinorderTraversal(root->left,ret);
		ret.push_back(root->val);
		myinorderTraversal(root->right,ret);
	}
	// 中序遍历二叉树
    vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		myinorderTraversal(root,ret); 
		return ret;
    }
	// 后续遍历二叉树
	void backorderTraversal(TreeNode *root){
		if(root == NULL)
			return;
		backorderTraversal(root->left);
		backorderTraversal(root->right);
		cout << root->val << endl;
	}

	int maxDepth(TreeNode *root);
	int minDepth(TreeNode *root);
	vector<string> binaryTreePaths(TreeNode* root);
	TreeNode* invertTree(TreeNode* root);
	TreeNode* pruneTree(TreeNode* root);
	TreeNode* searchBST(TreeNode* root, int val);
};