/*
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

示例 1：
输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2
输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]

提示：
    1 <= values <= 10000
    最多会对 appendTail、deleteHead 进行 10000 次调用
*/
#include <stack>
#include <iostream>
using std::cout;
using std::stack;
using std::endl;
class CQueue {
private:
stack<int> a;
stack<int> b;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        a.push(value);
    }
    
    int deleteHead() {
        if(b.empty()&&a.empty()){
            return -1;
        }
        else if(b.empty()&&!a.empty()){
            while(!a.empty()){
                b.push(a.top());
                a.pop();
            }
        }
        int temp = b.top();
        b.pop();
        return temp;
    }
};


 int main(){
CQueue obj;
obj.appendTail(2);
obj.appendTail(3);
obj.appendTail(4);
int param_1 = obj.deleteHead();
int param_2=obj.deleteHead();
int param_3=obj.deleteHead();
cout<<"pram_1"<<param_1<<endl;
cout<<"pram_2"<<param_2<<endl;
cout<<"pram_3"<<param_3<<endl;
 }
 