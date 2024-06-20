#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <assert.h>

#define MAX 100 // 最多人数
// 最大字节空间
#define MAX_NAME 9
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDER 30

// 类型声明
typedef struct PeoInfo
{
    char name[MAX_NAME];  // 名字
    int age;              // 年龄
    char sex[MAX_SEX];    // 性别
    char tele[MAX_TELE];  // 电话
    char addr[MAX_ADDER]; // 地址
} PeoInfo;

// 初始化记录
typedef struct contacts
{
    PeoInfo data[MAX]; // 存储信息
    int count;         // 记录人数
} contacts;

// 显示菜单
void Show_menu(void);
// 初始化通讯录
void Init_Contacts(contacts *pc);
// 添加联系人
void Add_Contacts(contacts *pc);
// 显示通讯录
void Show_Contacts(contacts *pc);
// 修改联系人信息
void Modifly_Contacts(contacts *pc);
// 查找指定联系人
int Find_Contacts(contacts *pc, char *name_t, int pos[MAX]);
// 删除联系人
void Del_Contacts(contacts *pc);
// 查找联系人
void Seek_Contacts(contacts *pc);
// 排序通讯录
void Sort_Contacts(contacts *pc);
// 清空联系人
void Clear_Contacts(contacts *pc);