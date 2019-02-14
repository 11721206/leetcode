#include "BinaryTree.h"

int main(void)
{
	Solution ms;
	struct TreeNode *myTree;
	vector<int> ret;
	myTree = NULL;
	cout << "create binary tree:" << endl;
	cout << "input:"<<endl; //[1,null,2,3]
	myTree = ms.preCreatBiTree(myTree);
	cout << "pre order" << endl;
	ms.preorderTraversal(myTree);
	cout << "minDepth" << endl;
	cout << ms.minDepth(myTree) << endl;
	cout << "inoder travesal:" << endl;
	ret = ms.inorderTraversal(myTree);
	vector<int>::iterator vit;
	for(vit=ret.begin();vit!=ret.end();vit++)
		cout << *vit << endl;
	vector<string> res;
	vector<string>::iterator sit;
	res = ms.binaryTreePaths(myTree);
	cout << "binary tree paths:" << endl;
	for(sit = res.begin();sit != res.end(); sit++)
		cout << *sit << endl;
	// cout << "后序遍历该树" << endl;
	// ms.backorderTraversal(myTree);
	system("pause");
	return 1;
}