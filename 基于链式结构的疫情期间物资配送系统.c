#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

// 疫情下物资结构体定义
typedef struct object
{
    char name[N];     // 物品名字
    char location[N]; // 货物位置状态  -仓库 / 小区 / 配送中
    int num;          // 物品数量
    float per_money;    // 物品单价
    char delivery[N];  // 配送方式 待定 / 快递 / 货车 / 人工
    struct object *next; //指针
}object;

// 系统界面展示函数
int System_Show(int x)
{
    printf("          ***************************************************************\n");
    printf("          ************基于链式结构的疫情期间物资配送系统*****************\n");
    printf("          ***************************************************************\n");
    printf("          ***       请选择系统功能：                                  ***\n");
    printf("          ***      >输入1录入物资信息                                 ***\n");
    printf("          ***      >输入2查找物资信息                                 ***\n");
    printf("          ***      >输入3更改物资信息                                 ***\n");
    printf("          ***      >输入4删除物资信息                                 ***\n");
    printf("          ***      >输入-1结束系统                                    ***\n");
    printf("          ***************************************************************\n");
    printf("          ***我的选择是：");
    scanf("%d",&x);  // 用户选择
    return x;
}

// 创建链表函数
object* Creat_list(object* rear1)
{
    object* p = (object*)malloc(sizeof(object*));

    getchar();
    printf("          ***请输入货物名字：");
    scanf("%s",p->name);
    printf("          ***请输入货物位置状态（仓库 / 小区 / 配送中）：");
    getchar();
    scanf("%s",p->location);
    printf("          ***请输入货物数量：");
    getchar();
    scanf("%d",&p->num);
    printf("          ***请输入货物单价：");
    getchar();
    scanf("%f",&p->per_money);
    getchar();
    printf("          ***请输入货物配送方式(待定 / 快递 / 货车 / 人工 ):");
    scanf("%s",p->delivery);
    printf("          ************************物品信息录入成功！**********************\n");

    p->next = NULL;
    rear1->next = p;
    rear1 = p;
    return rear1;
}

// 物品信息展示
void List_ALL_show(object* p)
{
    printf("          ***************************************************************\n");
    printf("          *******************疫情期间物资配送系统物资表******************\n");
    while(p!= NULL)
    {
        printf("          ***************************************************************\n");
        printf("          ***物品：%s                                              ***\n",p->name);
        printf("          ***货物状态：%s                                          ***\n",p->location);
        printf("          ***货物数量：%d                                            ***\n",p->num);
        printf("          ***货物单价：%.2f                                          ***\n",p->per_money);
        printf("          ***货物配送方式：%s                                      ***\n",p->delivery);
        printf("          ***************************************************************\n");

        p = p->next;
    }
}

// 单次物品展示
void List_single_show(object* p)
{
        printf("          ***************************************************************\n");
        printf("          ***物品：%s                                              ***\n",p->name);
        printf("          ***货物状态：%s                                          ***\n",p->location);
        printf("          ***货物数量：%d                                            ***\n",p->num);
        printf("          ***货物单价：%.2f                                          ***\n",p->per_money);
        printf("          ***货物配送方式：%s                                      ***\n",p->delivery);
        printf("          ***************************************************************\n");
}

// 查询链表函数  找到物资函数( 很多函数都是基于此）
void find(object* p, char F[],int find_choice)
{
    int find_flag = 0; // 默认没找到
    // 找物品名字
    if(find_choice ==1 )
    {
        while(p != NULL)
        {
            if(strcmp(p->name, F) == 0 )
            {
                List_single_show(p);   // 展示
                find_flag = 1;         // 标志找到了
            }
            p = p->next;
        }
        if( find_flag == 0)
        {
            printf("          ***没找到！\n");
        }
    }
    // 找物品状态
    if(find_choice == 2)
    {
        while(p != NULL )
        {
            if(strcmp(p->location, F) == 0)
            {
                List_single_show(p);   // 展示
                find_flag = 1;         // 标志找到了
            }
            p = p->next;
        }
        if(find_flag == 0)
        {
            printf("          ***没找到！\n");
        }
    }
    // 找物品配送方式
    if(find_choice ==3)
    {
        while(p != NULL )
        {
            if(strcmp(p->delivery, F) == 0)
            {
                List_single_show(p);   // 展示
                find_flag = 1;         // 标志找到了
            }
            p = p->next;
        }
        if(find_flag == 0)
        {
            printf("          ***没找到！\n");
        }
    }

}

// 更改链表函数
void change(object** p)
{
    int find_flag = 0 , n =0 ;
    char things[N] = {'\0'}; // 查找需要更改的物品
    char change_Name[N] = {'\0'}; // 更改的名字
    char change_Location[N] = {'\0'};
    int change_Num = 0;
    float change_Per_money = 0;
    char change_Delivery[N] = {'\0'};

    printf("          ***请输入需要更改的物资分类：\n");
    printf("          ***输入更改物品的名称：");
    getchar();
    scanf("%s",things);
    *p = (*p)->next ;
    while((*p) != NULL )
    {
        if(strcmp((*p)->name, things) == 0)
        {
            List_single_show(*p);   // 展示
            printf("          ***更改其名字1？状态2？数量3？单价4？配送方式5？");
            scanf("%d",&n);
            switch( n )
            {
            case 1:
                {
                    printf("          ***输入更改名字：");
                    scanf("%s",change_Name);
                    strcpy((*p)->name, change_Name);
                    break;
                }
            case 2:
                {
                    printf("          ***输入更改状态：");
                    scanf("%s",change_Location);
                    strcpy((*p)->location, change_Location);
                    break;
                }
            case 3:
                {
                    printf("          ***输入更改数量：");
                    scanf("%d",&change_Num);
                    (*p)->num = change_Num;
                    break;
                }
            case 4:
                {
                    printf("          ***输入更改单价：");
                    scanf("%f",&change_Per_money);
                    (*p)->per_money = change_Per_money;
                    break;
                }
            case 5:
                {
                    printf("          ***输入更改配送方式：");
                    scanf("%s",change_Delivery);
                    strcpy((*p)->delivery, change_Delivery);
                    break;
                }
            default:
                printf("          ***输入错误！");
            }
            printf("更改成功！\n");
            List_single_show(*p);
            find_flag = 1;         // 标志找到了
        }
        (*p) = (*p)->next ;
    }
    if(find_flag == 0)
    {
        printf("          ***没找到！\n");
    }

}

// 删除链表函数
void delted(object** q)
{
    char things[N] = {'\0'}; // 查找需要更改的物品
    int k = 0;
    int find_flag = 0;

    printf("          ***请输入需要删除的物资分类：\n");
    printf("          ***输入删除物品的名称：");
    getchar();
    scanf("%s",things);
    while((*q)->next!= NULL )
    {
        if(strcmp((*q)->next->name, things) == 0)
        {
            printf("          ***是否删除以下物资？\n");
            List_single_show((*q)->next);
            printf("          ***输入1删除输入0取消：");
            scanf("%d",&k);
            if( k ==1 )
            {
                (*q)->next = (*q)->next->next; // 删除
                printf("          ***已成功删除！\n");
            }
            find_flag = 1;
        }
        (*q) = (*q)->next ;
    }
    if(find_flag == 0)
    {
        printf("          ***没找到！\n");
    }
}

int main()
{
    object* head = (object*)malloc(sizeof(object*));
    head->name[N] = '\0';
    head->location[N] = '\0';
    head->num = 0;
    head->per_money = 0;
    head->delivery[N] = '\0';
    head->next = NULL;

    object* rear1 = head;
    object* rear2 = head;
    object* rear3 = head;

    int choice = 0 ;    // 用户选择
    int Creat_flag = 0; // 创建链表选择
    int Find_flag = 0;  // 查找选择
    int find_choice =0; // 查询分类
    char F[N] = {'\0'};   // 查询的字符串
    choice = System_Show(choice);  // 界面展示

    while(choice != -1)  // 系统大循环 choice = -1 结束程序
    {
        if(choice == 1)
        {
            printf("          ************************录入物资信息***************************\n");
            do
            {
                rear1 = Creat_list(rear1); // 创建链表

                printf("          ***输入1继续增加货物\n          ***输入0停止增加货物：");
                scanf("%d",&Creat_flag);
            }while(Creat_flag != 0);

            List_ALL_show(head->next); // 展示链表
        }

        if(choice == 2)
        {
            printf("          ************************查找物资信息***************************\n");
            do
            {
                printf("          ***请输入需要查找的分类：\n");
                printf("          ***输入1查找物品名称\n          ***输入2查找物品状态\n          ***输入3查找物品配送方式  ：");
                scanf("%d",&find_choice);
                printf("          ***请输入需要查找的物品名称 / 状态 / 配送方式：");
                getchar();
                scanf("%s",F);

                find(head->next,F,find_choice);

                printf("\n          ***输入1继续查找货物\n          ***输入0停止查找货物：");
                scanf("%d",&Find_flag);
            }while(Find_flag != 0);
        }

        if(choice == 3)
        {
            printf("          ************************更改物资信息***************************\n");
            List_ALL_show(head->next); // 展示链表
            rear2 = head;
            change(&rear2);  // 更改物品信息
            List_ALL_show(head->next);
        }

        if(choice == 4)
        {
            printf("          ************************删除物资信息***************************\n");
            List_ALL_show(head->next); // 展示链表
            rear3 = head;
            delted(&rear3);
            List_ALL_show(head->next);
        }

        choice = System_Show(choice);  // 展示界面，下一次循环
    }
    List_ALL_show(head->next); // 展示系统
    printf("          ***********************系统程序正常结束！**********************\n");

} 


