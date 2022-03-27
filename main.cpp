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
    cout<<"按下a键输入用户的个人信息，创建新账号"<<endl;
    cin>>a;
    while(a == 'a')//创建新用户
    {
        ListInsert(L);
        cout<<"按下a键继续创建新用户,按下s键停止创建新用户"<<endl;
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
    cout<<"下面显示所有用户信息"<<endl;
    showIDdata(L);
    cout<<"按下b键为用户创建交易记录"<<endl;
    cin>>b;
    while(b == 'b')//创建用户的交易记录
    {
        cout<<"请输入该用户的账号";
        cin>>Id;
        p_node_account k = findid(L,Id);
        initList1(k->first_node_log);
        c = 'c';
        while(c == 'c')
        {
            cout<<"按下D键则创建该用户的存款记录，按下W键则创建该用户的取款记录"<<endl;
            cin>>d;
            cout<<"请输入该用户本次交易的金额";
            cin>>value;
            cout<<"请输入该用户本次交易的日期";
            cin>>datatime;
            if(d == 'd')
            {
                deposit(k,Id,value,datatime);
            }
            else
            {
                withdrawals(k,Id,value,datatime);
            }
            cout<<"若想继续创建交易记录，则按下c键，否则按下v键"<<endl;
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
        cout<<"若想继续为下一个用户创建交易记录，则按下b键，否则按下n键"<<endl;
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
    cout<<"输入用户的账号，可查询该用户的用户余额"<<endl;
    cin>>Id;
    float valuedata = getBalance(L,Id);
    if(valuedata == -1)
    {
        cout<<"该用户不存在"<<endl;
    }
    else
    {
        cout<<"该用户的余额为："<<valuedata<<endl;
    }
    cout<<"输入用户的账号，可查询该用户的所有交易记录"<<endl;
    cin>>Id;
    findTransaction(L,Id);
    cout<<"输入用户的账号，可查询该用户的利息，利息率为30%"<<endl;
    cin>>Id;
    float result;
    result = interest(L,Id);
    cout<<"该用户的利息为："<<result<<endl;
    cout<<"输入要消除的账户"<<endl;
    cin>>Id;
    ListDelete(L,Id);
    cout<<"下面显示所有用户信息"<<endl;
    showIDdata(L);
    deletedata(L);
    return 0;
}
