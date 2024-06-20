#include "contacts.h"

int main()
{
    int choose = 0;
    contacts con;
    Init_Contacts(&con);    //初始化通讯录
    do
    {
        Show_menu();         //显示菜单
        printf("Your choose is -->");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:     //添加联系人
                Add_Contacts(&con);         break;
            case 2:    //删除联系人
                Del_Contacts(&con);         break;
            case 3:   //修改联系人
                Modifly_Contacts(&con);     break;
            case 4:  //查找联系人
                Seek_Contacts(&con);        break;
            case 5: //显示通讯录
                Show_Contacts(&con);        break;
            case 6: //排序通讯录
                Sort_Contacts(&con);        break;
            case 7://清空所有联系人
                Clear_Contacts(&con);       break;
            case 0:
                printf("Exit Successful!"); break;
            default:    //输入错误，请重新输入
                printf("Input error!");     break;
        }
    } while (choose);

    system("pause");
    return 0;
}
