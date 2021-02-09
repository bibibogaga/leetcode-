/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

*/
#include <iostream>
using std::cout;
using std::endl;
class Solution {
public:
    int numWays(int n) {
        if(n<=1) return 1;
        else{
            long long  fibtwo=1;
            long long  fibone=1;
            long long  fibN=0;
            for(int i=2;i<=n;++i){
                fibN=fibone+fibtwo;
                fibtwo=fibone;
                fibone=fibN;
            }
            return fibN;
        }
    }
};

int main(){
    int value;
    cout<<"please input a number"<<endl;
    std::cin>>value;
    Solution solution;
    int num=solution.numWays(value);
    cout<<"num is"<<num<<endl;
}