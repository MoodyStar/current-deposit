#include"head.h"
void initList(p_node_account &L)
{
    L = new node_account;
    L->next = NULL;
}//初始化账户链表

void initList1(p_node_log &p)
{
    p = new node_log;
    p->next = NULL;
}//初始化交易记录链表

void ListInsert(p_node_account &L)
{
    p_node_account p = new node_account;
    cout<<"请输入新用户的账号"<<endl;
    cin>>p->ID;
    cout<<"请输入新用户的姓名"<<endl;
    cin>>p->name;
    p->balance = 0;
    p->next = L->next;
    L->next = p;
}//插入新用户结点

void ListDelete(p_node_account &L,string Id)
{
    p_node_account p = L;
    while((p->next)&&(p->next->ID.compare(Id) != 0))
    {
        p = p->next;
    }
    if(!(p->next))
    {
        cout<<"查无此用户"<<endl;
        return ;
    }
    if(p->next->balance == 0)
    {
        p_node_account q = p->next;
        p->next = q->next;
        delete q;
    }
    else
    {
        cout<<"该账户还有余额，请将余额清零"<<endl;
    }
    return ;
}//销毁用户结点

float getBalance(p_node_account L,string Id)
{
    p_node_account p = L->next;
    float i;
    while(Id.compare(p->ID) != 0)
    {
        if(p->next == NULL)
        {
            return -1;
        }
        p = p->next;
    }
    i = p->balance;
    return i;
}//查询某个账号余额

node_account* findid(p_node_account &L,string Id)
{
    p_node_account p = L->next;
    while(Id.compare(p->ID) != 0)
    {
        if(p->next == NULL)
        {
            return 0;
        }
        p = p->next;
    }
    return p;
}//查找某个账户的位置

void showIDdata(p_node_account L)
{
    p_node_account p = L->next;
    if(p == NULL)
    {
        cout<<"无账户"<<endl;
    }
    while(p != NULL)
    {
        cout<<">>该用户的账号为："<<p->ID<<endl;
        cout<<">>        姓名为："<<p->name<<endl;
        cout<<">>        余额为："<<p->balance<<endl;
        p = p->next;
        cout<<""<<endl;
    }
}//显示所有用户账号信息

void deposit(p_node_account &L, string Id, float value, string datatime)
{
    p_node_account p = L;
    char a = 'D';
    while(Id.compare(p->ID) != 0)
    {
        if(p->next == NULL)
        {
            break;
        }
        p = p->next;
    }
    p->balance = p->balance + value;
    transaction(p->first_node_log,value,datatime,a);
}//用户的存款记录


void withdrawals(p_node_account &L, string Id, float value, string datatime)
{
    p_node_account p = L;
    char a = 'W';
    while(Id.compare(p->ID) != 0)
    {
        if(p->next == NULL)
        {
            break;
        }
        p = p->next;
    }
    p->balance = p->balance - value;
    transaction(p->first_node_log,value,datatime,a);
}//用户的取款记录

void transaction(p_node_log &p, float value, string datatime,char a)
{
    p_node_log k = new node_log;
    k->w_d = a;
    k->balance = value;
    k->DataTime = datatime;
    k->next = p->next;
    p->next = k;
}//交易记录

void findTransaction(p_node_account &L, string Id)
{
    p_node_account p = L->next;
    while(Id.compare(p->ID) != 0)
    {
        if(p->next == NULL)
        {
            break;
        }
        p = p->next;
    }
    transactiondata(p->first_node_log);
}//查找某个账户的交易记录

void transactiondata(p_node_log p)
{
    p_node_log k = p->next;
    while(k != NULL)
    {
        cout<<"该用户最新交易的情况如下"<<endl;
        if(k->w_d == 'D')
        {
            cout<<"交易方式为：存款"<<endl;
        }
        else
        {
            cout<<"交易方式为：取款"<<endl;
        }
        cout<<"交易时间为："<<k->DataTime<<endl;
        cout<<"交易金额为："<<k->balance<<endl;
        cout<<""<<endl;
        k = k->next;
    }
}//显示所有交易记录
float interest(p_node_account L,string Id)
{
    p_node_account p = L->next;
    while(Id.compare(p->ID) != 0)
    {
        if(p->next == NULL)
        {
            break;
        }
        p = p->next;
    }
    float result = p->balance*0.3;
    return result;
}//计算利息

void deletedata(p_node_account &L)
{
    p_node_account t;
    if(L == NULL)
    {
        return ;
    }
    while(L != NULL)
    {
        t = L;
        L = L->next;
        delete t;
    }
}//释放账号链表

void deletedata_1(p_node_log &p)
{
    p_node_log k =NULL;
    if(p == NULL)
    {
        return ;
    }
    while (p != NULL)
    {
        k = p;
        p = p->next;
        delete k;
    }
}//释放交易记录链表

void deletelist(p_node_account &L)
{
    if(L->next == NULL)
    {
        return ;
    }
    p_node_account p = L->next;
    while(p->next!=NULL)
    {
        if(L->first_node_log != NULL)
        {
            deletedata_1(L->first_node_log);
        }
        p=p->next;
    }
}//查找哪个账户有交易记录，释放那个交易记录的链表

