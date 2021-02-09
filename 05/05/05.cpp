/*
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
示例 1：
输入：s = "We are happy."
输出："We%20are%20happy."
限制：
0 <= s 的长度 <= 10000

算法流程：

    初始化：空格数量 count ，字符串 s 的长度 len ；
    统计空格数量：遍历 s ，遇空格则 count++ ；
    修改 s 长度：添加完 "%20" 后的字符串长度应为 len + 2 * count ；
    倒序遍历修改：i 指向原字符串尾部元素， j 指向新字符串尾部元素；当 i = j 时跳出（代表左方已没有空格，无需继续遍历）；
        当 s[i] 不为空格时：执行 s[j] = s[i] ；
        当 s[i] 为空格时：将字符串闭区间 [j-2, j] 的元素修改为 "%20" ；由于修改了 3 个元素，因此需要 j -= 2 ；
    返回值：已修改的字符串 s ；

作者：jyd
链接：https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/solution/mian-shi-ti-05-ti-huan-kong-ge-ji-jian-qing-xi-tu-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <string>
#include <iostream>
using std::string;
class Solution {
public:
    string replaceSpace(string s) {
        int count =0,len=s.size();
        for(char c:s){
            if(c==' ') count++;
        }
        s.resize(len+count*2);
        for(int i=len-1,j=s.size()-1;i<j;i--,j--){
            if(s[i]!=' ') s[j]=s[i];
            else {
            s[j-2]='%',s[j-1]='2',s[j]='0';
            j-=2;
            }
        }
        return s;

    }
};
int main(){
    Solution solution;
    string s=solution.replaceSpace("We are happy.");
    std::cout<<s;
}