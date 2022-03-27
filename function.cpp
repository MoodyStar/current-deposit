#include"head.h"
void initList(p_node_account &L)
{
    L = new node_account;
    L->next = NULL;
}//��ʼ���˻�����

void initList1(p_node_log &p)
{
    p = new node_log;
    p->next = NULL;
}//��ʼ�����׼�¼����

void ListInsert(p_node_account &L)
{
    p_node_account p = new node_account;
    cout<<"���������û����˺�"<<endl;
    cin>>p->ID;
    cout<<"���������û�������"<<endl;
    cin>>p->name;
    p->balance = 0;
    p->next = L->next;
    L->next = p;
}//�������û����

void ListDelete(p_node_account &L,string Id)
{
    p_node_account p = L;
    while((p->next)&&(p->next->ID.compare(Id) != 0))
    {
        p = p->next;
    }
    if(!(p->next))
    {
        cout<<"���޴��û�"<<endl;
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
        cout<<"���˻��������뽫�������"<<endl;
    }
    return ;
}//�����û����

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
}//��ѯĳ���˺����

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
}//����ĳ���˻���λ��

void showIDdata(p_node_account L)
{
    p_node_account p = L->next;
    if(p == NULL)
    {
        cout<<"���˻�"<<endl;
    }
    while(p != NULL)
    {
        cout<<">>���û����˺�Ϊ��"<<p->ID<<endl;
        cout<<">>        ����Ϊ��"<<p->name<<endl;
        cout<<">>        ���Ϊ��"<<p->balance<<endl;
        p = p->next;
        cout<<""<<endl;
    }
}//��ʾ�����û��˺���Ϣ

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
}//�û��Ĵ���¼


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
}//�û���ȡ���¼

void transaction(p_node_log &p, float value, string datatime,char a)
{
    p_node_log k = new node_log;
    k->w_d = a;
    k->balance = value;
    k->DataTime = datatime;
    k->next = p->next;
    p->next = k;
}//���׼�¼

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
}//����ĳ���˻��Ľ��׼�¼

void transactiondata(p_node_log p)
{
    p_node_log k = p->next;
    while(k != NULL)
    {
        cout<<"���û����½��׵��������"<<endl;
        if(k->w_d == 'D')
        {
            cout<<"���׷�ʽΪ�����"<<endl;
        }
        else
        {
            cout<<"���׷�ʽΪ��ȡ��"<<endl;
        }
        cout<<"����ʱ��Ϊ��"<<k->DataTime<<endl;
        cout<<"���׽��Ϊ��"<<k->balance<<endl;
        cout<<""<<endl;
        k = k->next;
    }
}//��ʾ���н��׼�¼
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
}//������Ϣ

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
}//�ͷ��˺�����

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
}//�ͷŽ��׼�¼����

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
}//�����ĸ��˻��н��׼�¼���ͷ��Ǹ����׼�¼������

