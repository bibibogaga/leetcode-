#include <stack>
#include <vector>
using std::vector;
using std::stack;
typedef struct node {
    int data;
    struct node *next;
}NODE;

class LinkList
{
private:
    NODE *head;
public:
    LinkList() { head = nullptr; }
    ~LinkList();
    bool  Insert(int i, int e); 
    vector<int> Reverse(NODE* head);
    NODE*  getNODE();
};
//析构函数
LinkList::~LinkList()//和清空一样
{
    NODE *p = head;
    while (head)
    {
        p = head;
        head = head->next;
        delete(p);
    }
}
//获取链表节点，自己写的
NODE* LinkList::getNODE(){
    NODE *p =head;
    return p;
}
//给链表位置i插入元素e
bool LinkList::Insert(int i, int e)
{
    NODE *p = head,*s;
    int j = 0;
    if (i == 0)
    {
        s = (NODE *)new NODE[1];
        s->data = e;
        s->next = p;
        head = s;
        return true;
    }
    while (p&&j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == nullptr)
        return false;//到队尾了
    s= (NODE *)new NODE[1];
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//反转链表
vector<int> LinkList::Reverse(NODE* head){
         stack<int> s;
         vector<int> res;
        //入栈
        while(head){
            s.push(head->data);
            head = head->next;
        }
        //出栈
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        return res;

}