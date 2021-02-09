
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
/*
解题思路：

前序遍历性质： 节点按照 [ 根节点 | 左子树 | 右子树 ] 排序。
中序遍历性质： 节点按照 [ 左子树 | 根节点 | 右子树 ] 排序。

    以题目示例为例：

        前序遍历划分 [ 3 | 9 | 20 15 7 ]
        中序遍历划分 [ 9 | 3 | 15 20 7 ]

根据以上性质，可得出以下推论：

    前序遍历的首元素 为 树的根节点 node 的值。
    在中序遍历中搜索根节点 node 的索引 ，可将 中序遍历 划分为 [ 左子树 | 根节点 | 右子树 ] 。
    根据中序遍历中的左 / 右子树的节点数量，可将 前序遍历 划分为 [ 根节点 | 左子树 | 右子树 ] 。
通过以上三步，可确定 三个节点 ：1.树的根节点、2.左子树根节点、3.右子树根节点。
对于树的左、右子树，仍可使用以上步骤划分子树的左右子树。
作者：jyd
链接：https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/solution/mian-shi-ti-07-zhong-jian-er-cha-shu-di-gui-fa-qin/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
/*
算法思想：使用前中序递归建树

*/
#include <vector>
#include <iostream>
#include <unordered_map>
using std::vector;
using std::unordered_map;
using std::cout;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    unordered_map<int, int> in_map; //快速找到 （前序中找的根）在中序中的位置，便于对中序序列进行左右子树的划分

    TreeNode* buildTree(vector<int>& preorder, vector<int>& norder)
    {
        for(int i = 0; i < norder.size(); i++) //<中序序列, 索引>
            in_map[norder[i]] = i;
        return find_par_build(preorder, norder, 0, 0, norder.size() - 1);
        //传入的参数列表：（前序序列，中序序列，在前序序列中找到的根节点，中序左边界，中序右边界）
    }

    TreeNode* find_par_build(vector<int>& preorder, vector<int>& norder, int pre_root, int in_left_bound, int in_right_bound)
    {
        if(in_left_bound > in_right_bound)  //子树中序遍历为空，说明已经越过叶子节点，此时返回 null
            return NULL;
        TreeNode* root = new TreeNode(preorder[pre_root]);  //在前序序列中找到根节点
        int in_root = in_map[preorder[pre_root]];   //定位根节点在中序序列中的位置，此时in_root左边是左子树，右边是右子树

        //找左子树的根：
        root->left = find_par_build(preorder, norder, pre_root + 1, in_left_bound, in_root -1);
        //左子树在前序中的根节点位于：pre_root+1； 左子树在中序中的边界：[in_left_bound,in_root-1]

        //找右子树的根
        root->right = find_par_build(preorder, norder, pre_root + (in_root - in_left_bound + 1), in_root + 1, in_right_bound);
        // 右子树在前序中的根节点位于：根节点+（左子树长度+1）；右子树在中序中的边界：[in_root+1,in_right_bound]
        return root;
    }
};
int main(){
    vector<int> preorder={3,9,2,1,7};
    vector<int> norder={9,3,1,2,7};
    Solution solution;
    TreeNode* root;
    root=solution.buildTree(preorder,norder);
    cout<<"value is"<<root->val;
    return 1;
}