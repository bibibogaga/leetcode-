/*
方法一：哈希表 / Set

利用数据结构特点，容易想到使用哈希表（Set）记录数组的各个数字，当查找到重复数字则直接返回。
算法流程：

    初始化： 新建 HashSet ，记为 dicdicdic ；
    遍历数组 numsnumsnums 中的每个数字 numnumnum ：
        当 numnumnum 在 dicdicdic 中，说明重复，直接返回 numnumnum ；
        将 numnumnum 添加至 dicdicdic 中；
    返回 −1-1−1 。本题中一定有重复数字，因此这里返回多少都可以。

复杂度分析：

    时间复杂度 O(N)O(N)O(N) ： 遍历数组使用 O(N)O(N)O(N) ，HashSet 添加与查找元素皆为 O(1)O(1)O(1) 。
    空间复杂度 O(N)O(N)O(N) ： HashSet 占用 O(N)O(N)O(N) 大小的额外空间。

作者：jyd
链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/solution/mian-shi-ti-03-shu-zu-zhong-zhong-fu-de-shu-zi-yua/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/


#include <vector>
#include <iostream>
#include <unordered_map>
using std::vector;
using std::unordered_map;
using std::cout;
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, bool> map;
        for(int num : nums) {
            if(map[num]) return num; //num是key值，map[num]是value（这里是true或者false），nums={2，3，1，0，2，5，3}
            map[num] = true;
        }
        return -1;
    }
};
int main(){
    vector<int> vec = {2,3,1,0,2,5,3};
    Solution solution;
    int num;
    num=solution.findRepeatNumber(vec);
    cout<<"num is"<<num;

}
