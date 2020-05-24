/******************************************************************
** 文件名: TreeNodeTest.cpp
** 创建人: BanMing 
** 日  期: 5/24/2020, 10:09:23 PM
** 描  述:  二叉树测试
https://www.jianshu.com/p/456af5480cee

**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/

#include <iostream>
#include <stack>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 先序遍历***************************************************************************************

// 先输出当前节点，然后依次遍历左右子树（根左右）

// 递归 先序遍历
void recursionPreorderTraversal(TreeNode *tree)
{
    if (tree == NULL)
    {
        return;
    }

    // std::cout << tree->val << std::endl;
    printf("%d ", tree->val);
    recursionPreorderTraversal(tree->left);
    recursionPreorderTraversal(tree->right);
}

// 非递归 先序遍历
void preorderTraversal(TreeNode *tree)
{
    // 因为需要知道前一个根节点，所以需要记录一下，后面好回溯
    std::stack<TreeNode *> treeStack;

    while (tree != NULL || !treeStack.empty())
    {

        // 先遍历左边
        while (tree != NULL)
        {
            // std::cout << tree->val << std::endl;
            printf("%d ", tree->val);
            treeStack.push(tree);
            tree = tree->left;
        }

        // 如果左边没有了 就开始遍历右边 使用栈回溯
        if (!treeStack.empty())
        {
            TreeNode *node = treeStack.top();
            treeStack.pop();
            tree = node->right;
        }
    }
}

// 中序遍历***************************************************************************************

// 当前节点先记录，然后遍历左节点，如果没有左节点即输出节点（左根右）

void recursionMiddleTraversal(TreeNode *tree)
{
    if (tree != NULL)
    {
        // std::cout << tree->val << std::endl;
        recursionMiddleTraversal(tree->left);
        printf("%d ", tree->val);
        recursionMiddleTraversal(tree->right);
    }
}

void middleTraversal(TreeNode *tree)
{
    std::stack<TreeNode *> treeStack;
    while (tree != NULL || !treeStack.empty())
    {
        // 先遍历完左边子树
        while (tree != NULL)
        {
            treeStack.push(tree);
            tree = tree->left;
        }

        // 当左边遍历完后，输出当前节点
        if (!treeStack.empty())
        {
            tree = treeStack.top();
            printf("%d ", tree->val);
            treeStack.pop();
            tree = tree->right;
        }
    }
}

// 后序遍历***************************************************************************************

// 当前节点先记录，然后遍历左、右节点，依次遍历完成后打印当前点

void recursionPostorderTraversal(TreeNode *tree)
{

    if (tree == NULL)
    {
        return;
    }
    recursionPostorderTraversal(tree->left);
    recursionPostorderTraversal(tree->right);
    printf("%d ", tree->val);
}

void postorderTraversal(TreeNode *tree)
{
    std::stack<TreeNode *> treeStack;
    // 这里需要一个上次打印的点，以便好判断一个节点的左右都遍历了
    TreeNode *lastVisit = tree;
    while (tree != NULL || !treeStack.empty())
    {
        // 先遍历左边
        while (tree != NULL)
        {
            treeStack.push(tree);
            tree = tree->left;
        }

        // 转向右边
        if (!treeStack.empty())
        {
            TreeNode *node = treeStack.top();
            if (node->right == lastVisit || node->right == NULL)
            {
                treeStack.pop();
                lastVisit = node;
                printf("%d ", node->val);
            }
            else
            {
                tree = node->right;
                continue;
            }
        }
    }
}
// 测试
void Run()
{

    TreeNode *testTree = new TreeNode(1);

    testTree->left = new TreeNode(2);
    testTree->right = new TreeNode(3);

    testTree->left->left = new TreeNode(4);
    testTree->right->right = new TreeNode(5);

    testTree->left->left->right = new TreeNode(6);

    testTree->left->left->right->left = new TreeNode(7);
    testTree->left->left->right->right = new TreeNode(8);

    // printf("recursionPreorderTraversal :");
    // recursionPreorderTraversal(testTree);
    // printf("\n");

    // printf("preorderTraversal :");
    // preorderTraversal(testTree);
    // printf("\n");

    // printf("recursionMiddleTraversal :");
    // recursionMiddleTraversal(testTree);
    // printf("\n");

    // printf("middleTraversal :");
    // middleTraversal(testTree);
    // printf("\n");

    printf("recursionPostorderTraversal :");
    recursionPostorderTraversal(testTree);
    printf("\n");

    printf("middleTraversal :");
    postorderTraversal(testTree);
    printf("\n");
}