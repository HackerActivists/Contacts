#include "contacts.h"

// 显示菜单
void Show_menu()
{
    printf("**************************************\n");
    printf("*****  1.add             2.del   *****\n");
    printf("*****  3.modifly         4.seek  *****\n");
    printf("*****  5.show            6.sort  *****\n");
    printf("*****  7.Clear           0.exit  *****\n");
    printf("**************************************\n");
}
// 初始化通讯录
void Init_Contacts(contacts *pc)
{
    assert(pc);
    pc->count = 0;
    memset(pc->data, 0, sizeof(pc->data)); // 全部初始化
}
// 添加联系人
void Add_Contacts(contacts *pc)
{
    assert(pc);
    if (pc->count == MAX) // 当联系人已满时，打印信息直接结束
    {
        printf("No Vacancies!\n");
        printf("Please afrsh choose!\n");
        return;
    }
    else
    {
        // 输入信息
        printf("Please input name->");
        scanf("%s", pc->data[pc->count].name);
        printf("Please input age->");
        scanf("%d", &(pc->data[pc->count].age));
        printf("Please input sex->");
        scanf("%s", pc->data[pc->count].sex);
        printf("Please input telephone->");
        scanf("%s", pc->data[pc->count].tele);
        printf("Please input address->");
        scanf("%s", pc->data[pc->count].addr);
    }
    pc->count++; // 输入成功,人数+1
    printf("added successfully!\n");
}
// 显示通讯录
void Show_Contacts(contacts *pc)
{
    assert(pc);
    if (pc->count == 0) // 如果通讯录为空,则直接返回
    {
        printf("This contacts is empty!\n");
        return;
    }
    int i = 0;
    // 列标题
    printf("%-15s\t%-15s\t%-15s\t%-15s\t%-15s\n", "name", "age", "sex", "tele", "addr");
    for (i = 0; i < pc->count; i++)
    {
        printf("%-15s\t%-15d\t%-15s\t%-15s\t%-15s\n",
               pc->data[i].name,  // 名字
               pc->data[i].age,   // 年龄
               pc->data[i].sex,   // 性别
               pc->data[i].tele,  // 电话
               pc->data[i].addr); // 地址
    }
}
// 修改联系人信息
void Modifly_Contacts(contacts *pc)
{
    assert(pc);
    char name_t[10] = {'\0'};
    printf("Please input your want modifly name->");
    scanf("%s", name_t); // 提供所修改信息的名称
    // gets(name_t);    *需要清除缓冲区

    int pos[MAX] = {0};                              // 存储的所要修改数据的下标
    int same_count = Find_Contacts(pc, name_t, pos); // 计算与输入的名称相同的个数(考虑重复情况)
    int select = 1;                                  // 当出现重复数据时为用户提供选择,select=1防止没有重复时，无法正确修改信息
    if (same_count == 0)                             // 输入要修改名称没有时,意味输入错误程序结束
    {
        printf("This contacts is empty,please afrsh choose!\n");
        return;
    }
    else if (same_count > 1) // 当出现多个相同名称时,再进一步提供选择第几个
    {
        printf("Detected multiple players before making further choices->");
        scanf("%s", &select);
        while (select > same_count) // 在循环中,所做选择序号不能超过出现的个数
        {
            printf("Input error!!!\n");
            printf("Please afrsh input->");
            scanf("%d", &select);
        }
    }
    // 修改数据-->pos数组里存储的是所出现数的下标
    printf("Please input name->");
    scanf("%s", pc->data[pos[select - 1]].name);
    printf("Please input age->");
    scanf("%d", &(pc->data[pos[select - 1]].age));
    printf("Please input sex->");
    scanf("%s", pc->data[pos[select - 1]].sex);
    printf("Please input telephone->");
    scanf("%s", pc->data[pos[select - 1]].tele);
    printf("Please input address->");
    scanf("%s", pc->data[pos[select - 1]].addr);
}
// 排查联系人
int Find_Contacts(contacts *pc, char *name_t, int pos[MAX])
{
    assert(pc);
    int i = 0;
    int tag = 0;
    printf("Find the follwing content for you :\n");
    for (i = 0; i < pc->count; i++)
    {
        // 如果所要修改数据与源数据相同时,输出出来并将下标存放到pos数组
        if (strcmp(pc->data[i].name, name_t) == 0)
        {
            printf("%-15s\t%-15d\t%-15s\t%-15s\t%-15s\n",
                    pc->data[i].name,
                    pc->data[i].age,
                    pc->data[i].sex,
                    pc->data[i].addr);
            pc->data[i].tele,
                pos[tag++] = i; // 存储下标位置
        }
    }
    return tag; // 返回个数
}
// 删除联系人
void Del_Contacts(contacts *pc)
{
    assert(pc);
    char name_t[10] = {'\0'};
    printf("Please input your want modifly name->");
    scanf("%s", name_t); // 提供所修改信息的名称

    int pos[MAX] = {0};
    int same_count = Find_Contacts(pc, name_t, pos);
    int select = 1;

    if (same_count == 0) // 当源数据中没有要删除的数据时
    {
        printf("This contacts is empty,please afrsh choose!\n");
        return;
    }
    else if (same_count > 1) // 当出现多个相同名称时,再进一步提供选择第几个
    {
        printf("Detected multiple players before making further choices->");
        scanf("%d", &select);
        while (select > same_count) // 再循环中,所做选择序号不能超过出现的个数
        {
            printf("Input error!!!\n");
            printf("Please afrsh input->");
            scanf("%s", &select);
        }
    }
    // 删除数据
    int i = 0;
    for (i = pos[select - 1]; i < pc->count - 1; i++) // count - 1 避免越界
        pc->data[i] = pc->data[i + 1];
    printf("Delete Successful!\n"); // 打印成功信息，人数 - 1
    pc->count--;
}
// 查找联系人
void Seek_Contacts(contacts *pc)
{
    assert(pc);
    char name_t[10] = {'\0'};
    printf("Please your want seek name->");
    scanf("%s", name_t);
    int pos[MAX] = {0};
    int count = Find_Contacts(pc, name_t, pos);
    if (count == 0) // 没有所要查询的人时,直接返回
    {
        printf("This contacts is empty,please afrsh choose!\n");
        return;
    }
    else // 打印出人数
        printf("Found %d contact for you\n", count);
}
// qsort排序所用函数(升序)
int cmp_peo_name(const void *e1, const void *e2)
{
    return strcmp(((PeoInfo *)e1)->name, ((PeoInfo *)e2)->name);
}
// 排序通讯录
void Sort_Contacts(contacts *pc)
{
    assert(pc);
    if (pc->count == 0) // 通讯录为空，直接结束
    {
        printf("This contacts is empty,please afrsh choose!\n");
        return;
    }
    // 不为空,则使用qsort排序
    else
        qsort(pc, pc->count, sizeof(PeoInfo), cmp_peo_name);
    printf("Sorting Successful!\n"); // 排序成功
}
// 清空联系人
void Clear_Contacts(contacts *pc)
{
    if(pc->count == 0)  //如果通讯录本身为空则打印提示信息返回
        {
            printf("This contacts is empty,please afrsh choose!\n");
            return;
        }
    printf("Are you sure you want to clear all ?\n");
    printf("Yes->1   exit->other\n");
    printf("Your choose is->");
    int flag = 1;
    scanf("%d",&flag);
    if(flag == 1)
    {
        Init_Contacts(pc);
        printf("Clear successful!\n");
    }
}