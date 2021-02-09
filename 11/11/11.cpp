/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  
示例 1：
输入：[3,4,5,1,2]
输出：1
示例 2：
输入：[2,2,2,0,1]
输出：0
*/
/*
解法：二分查找

*/
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int i=0,j=numbers.size()-1;
        while (i<j)
        {
            int m=(i+j)/2;
            if(numbers[m]<numbers[j]){
               j=m;
            }
            else if(numbers[m]>numbers[j]){
                i=m+1;
            }
            else j--;
        }
        return numbers[i];
       
        

    }
};
int main(){
    vector<int> numbers={5,6,7,2,3,4};
    Solution solution;
    int n=solution.minArray(numbers);
    cout<<"边界值"<<n;
    
}