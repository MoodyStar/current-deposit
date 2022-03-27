#include"head.h"

extern void initList(p_node_account &L);
extern void ListInsert(p_node_account &L);
extern void showIDdata(p_node_account L);
extern void initList1(p_node_log &p);
extern void deposit(p_node_account &L, string Id, float value, string datatime);
extern void withdrawals(p_node_account &L, string Id, float value, string datatime);
extern float getBalance(p_node_account L,string Id);
extern void findTransaction(p_node_account &L, string Id);
extern void ListDelete(p_node_account &L,int i);
extern void deletedata(p_node_account &L);
extern void deletelist(p_node_account &L);
extern node_account* findid(p_node_account &L,string Id);
extern float interest(p_node_account L,string Id);

int main()
{
    p_node_account L;
    char a,b,c,d;
    string Id,datatime;
    float value;
    initList(L);
    cout<<"����a�������û��ĸ�����Ϣ���������˺�"<<endl;
    cin>>a;
    while(a == 'a')//�������û�
    {
        ListInsert(L);
        cout<<"����a�������������û�,����s��ֹͣ�������û�"<<endl;
        cin>>a;
        if(a == 'a')
        {
            continue;
        }
        else
        {
            break;
        }
    }
    cout<<"������ʾ�����û���Ϣ"<<endl;
    showIDdata(L);
    cout<<"����b��Ϊ�û��������׼�¼"<<endl;
    cin>>b;
    while(b == 'b')//�����û��Ľ��׼�¼
    {
        cout<<"��������û����˺�";
        cin>>Id;
        p_node_account k = findid(L,Id);
        initList1(k->first_node_log);
        c = 'c';
        while(c == 'c')
        {
            cout<<"����D���򴴽����û��Ĵ���¼������W���򴴽����û���ȡ���¼"<<endl;
            cin>>d;
            cout<<"��������û����ν��׵Ľ��";
            cin>>value;
            cout<<"��������û����ν��׵�����";
            cin>>datatime;
            if(d == 'd')
            {
                deposit(k,Id,value,datatime);
            }
            else
            {
                withdrawals(k,Id,value,datatime);
            }
            cout<<"��������������׼�¼������c����������v��"<<endl;
            cin>>c;
            if(c == 'c')
            {
                continue;
            }
            else
            {
                break;
            }
        }
        cout<<"�������Ϊ��һ���û��������׼�¼������b����������n��"<<endl;
        cin>>b;
        if(b == 'b')
        {
            continue;
        }
        else
        {
            break;
        }
    }
    cout<<"�����û����˺ţ��ɲ�ѯ���û����û����"<<endl;
    cin>>Id;
    float valuedata = getBalance(L,Id);
    if(valuedata == -1)
    {
        cout<<"���û�������"<<endl;
    }
    else
    {
        cout<<"���û������Ϊ��"<<valuedata<<endl;
    }
    cout<<"�����û����˺ţ��ɲ�ѯ���û������н��׼�¼"<<endl;
    cin>>Id;
    findTransaction(L,Id);
    cout<<"�����û����˺ţ��ɲ�ѯ���û�����Ϣ����Ϣ��Ϊ30%"<<endl;
    cin>>Id;
    float result;
    result = interest(L,Id);
    cout<<"���û�����ϢΪ��"<<result<<endl;
    cout<<"����Ҫ�������˻�"<<endl;
    cin>>Id;
    ListDelete(L,Id);
    cout<<"������ʾ�����û���Ϣ"<<endl;
    showIDdata(L);
    deletedata(L);
    return 0;
}
