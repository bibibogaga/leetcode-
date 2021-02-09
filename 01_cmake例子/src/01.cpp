/*题目描述：
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
请找出数组中任意一个重复的数字
输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 
*/
#include <iostream>
using std::cout;
using std::cin;
bool duplicate(char numbers[],char length[],char* duplication){

    for(int i = 0;i < length[0];++i){
        while(numbers[i]!=i){
            if(numbers[i]=numbers[numbers[i]]){
                *duplication=numbers[i];
                return *duplication;
            }

            int temp=numbers[i];
            numbers[i]=numbers[temp];
            numbers[temp]=temp;
        }

    }
    return false;
}

int main (int argc,char **argv){
    if(argc!=2){cout<<"please input:numbers[],length"<<std::endl;}
    auto num= argv[1];
    auto length=argv[2];
    cout<<"num is"<<num[0]<<std::endl;
    cout<<"length is"<<length[0]<<std::endl;
  
    cout<<"duplication number is "<<duplicate(num,length,nullptr);


}