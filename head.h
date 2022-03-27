#include <iostream>
#include<string>

using namespace std;

typedef struct node_log
{
    string DataTime;
    char w_d;
    float balance;
    struct node_log *next;
}node_log,*p_node_log;

typedef struct node_account
{
    string ID;
    string name;
    float balance;
    struct node_account *next;
    struct node_log *first_node_log;
}node_account,*p_node_account;

void initList(p_node_account &L);
void initList1(p_node_log &p);
void ListInsert(p_node_account &L);
void ListDelete(p_node_account &L,string Id);
float getBalance(p_node_account L,string Id);
void showIDdata(p_node_account L);
void deposit(p_node_account &L, string Id, float value, string datatime);
void withdrawals(p_node_account &L, string Id, float value, string datatime);
void transaction(p_node_log &p, float value, string datatime,char a);
void findTransaction(p_node_account &L, string Id);
void transactiondata(p_node_log p);
void deletedata(p_node_account &L);
void deletelist(p_node_account &L);
node_account* findid(p_node_account &L,string Id);
float interest(p_node_account L,string Id);
