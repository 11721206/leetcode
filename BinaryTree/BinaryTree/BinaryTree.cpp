#include "BinaryTree.h"

int isEnd = 0;
bool Solution::getStdinStr(string &mstr)  
{  
	mstr.clear();
	char c = ' ';
	//char s1[2] = {c,0};
	string s = "";
	int sNum = 0;
	if(isEnd)
		return false;
	while(1)
	{
		cin>>c;
		//cout << c << endl;
		if(c == delimiter)
			break;
		if(c == kuohao0)
			continue;
		if(c==kuohao1)
		{
			isEnd = 1;
			break;
		}
		s += " ";
		s[sNum++] = c;
	}
	if(s == NULL_STR)
		return false;
	mstr = s;		
	return true;
	//fflush(stdin);  
} 

int Solution::maxDepth(TreeNode *root)
{
	if(root == NULL) return 0;
	int lCount = maxDepth(root->left);
	int rCount = maxDepth(root->right);
	return 1 + (lCount>rCount?lCount:rCount);
}

int Solution::minDepth(TreeNode *root)
{
	if(root == NULL) return 0;
	if(root->left == NULL) return minDepth(root->right) + 1;
	if(root->right == NULL) return minDepth(root->left) + 1;
	int lCount = minDepth(root->left);
	int rCount = minDepth(root->right);
	return 1 + (lCount>rCount?rCount:lCount);
}


vector<string> Solution::binaryTreePaths(TreeNode* root)
{
	vector<string> ret;
	if(root == NULL)
		return ret;
	if((root->left == NULL) &&(root->right == NULL))
	{
		ret.push_back(to_string(root->val));
		return ret;
	}
	vector<string> lRet;
	vector<string>::iterator sit;
	lRet = binaryTreePaths(root->left);
	for(sit = lRet.begin();sit != lRet.end(); sit++)
		ret.push_back(to_string(root->val)+"->"+(*sit));
	vector<string> rRet;
	rRet = binaryTreePaths(root->right);
	for(sit = rRet.begin();sit != rRet.end();sit++)
	{
		ret.push_back(to_string(root->val) + "->" + (*sit));
	}
	return ret;
}

TreeNode* Solution::invertTree(TreeNode* root)
{
	TreeNode *res;	
	if(root == NULL)
		return NULL;
	res = new TreeNode(root->val);
	res->right = invertTree(root->left);
	res->left = invertTree(root->right);
	return res;
}

/*
* https://leetcode-cn.com/problems/binary-tree-pruning/
*/
TreeNode* Solution::pruneTree(TreeNode* root) 
{
	TreeNode *res;
	if(root == NULL)
		return NULL;	
	if((root->left == NULL) && (root->right == NULL))
		if(root->val == 0)					
			return NULL;		
		else
		{
			res = new TreeNode(root->val);
			res->left = NULL;
			res->right = NULL;
		}
	else
	{
			res = new TreeNode(root->val);
			res->left = pruneTree(root->left);
			res->right = pruneTree(root->right);
			if((res->left == NULL) && (res->right == NULL))
				if(root->val == 0)
				{
					delete res;
					return NULL;
				}					
	}			
	return res;
}

/*
* https://leetcode-cn.com/problems/search-in-a-binary-search-tree/
*/
TreeNode* solution::searchBST(TreeNode* root, int val)
{
	TreeNode* res;
	if(root==NULL)
		return NULL;
	if(root->val == val)
		return root;
	if((res=searchBST(root->left,val))==NULL)
		return searchBST(root->right,val);
	return res;
}