#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

// ���������ʽṹ�嶨��
typedef struct object
{
    char name[N];     // ��Ʒ����
    char location[N]; // ����λ��״̬  -�ֿ� / С�� / ������
    int num;          // ��Ʒ����
    float per_money;    // ��Ʒ����
    char delivery[N];  // ���ͷ�ʽ ���� / ��� / ���� / �˹�
    struct object *next; //ָ��
}object;

// ϵͳ����չʾ����
int System_Show(int x)
{
    printf("          ***************************************************************\n");
    printf("          ************������ʽ�ṹ�������ڼ���������ϵͳ*****************\n");
    printf("          ***************************************************************\n");
    printf("          ***       ��ѡ��ϵͳ���ܣ�                                  ***\n");
    printf("          ***      >����1¼��������Ϣ                                 ***\n");
    printf("          ***      >����2����������Ϣ                                 ***\n");
    printf("          ***      >����3����������Ϣ                                 ***\n");
    printf("          ***      >����4ɾ��������Ϣ                                 ***\n");
    printf("          ***      >����-1����ϵͳ                                    ***\n");
    printf("          ***************************************************************\n");
    printf("          ***�ҵ�ѡ���ǣ�");
    scanf("%d",&x);  // �û�ѡ��
    return x;
}

// ����������
object* Creat_list(object* rear1)
{
    object* p = (object*)malloc(sizeof(object*));

    getchar();
    printf("          ***������������֣�");
    scanf("%s",p->name);
    printf("          ***���������λ��״̬���ֿ� / С�� / �����У���");
    getchar();
    scanf("%s",p->location);
    printf("          ***���������������");
    getchar();
    scanf("%d",&p->num);
    printf("          ***��������ﵥ�ۣ�");
    getchar();
    scanf("%f",&p->per_money);
    getchar();
    printf("          ***������������ͷ�ʽ(���� / ��� / ���� / �˹� ):");
    scanf("%s",p->delivery);
    printf("          ************************��Ʒ��Ϣ¼��ɹ���**********************\n");

    p->next = NULL;
    rear1->next = p;
    rear1 = p;
    return rear1;
}

// ��Ʒ��Ϣչʾ
void List_ALL_show(object* p)
{
    printf("          ***************************************************************\n");
    printf("          *******************�����ڼ���������ϵͳ���ʱ�******************\n");
    while(p!= NULL)
    {
        printf("          ***************************************************************\n");
        printf("          ***��Ʒ��%s                                              ***\n",p->name);
        printf("          ***����״̬��%s                                          ***\n",p->location);
        printf("          ***����������%d                                            ***\n",p->num);
        printf("          ***���ﵥ�ۣ�%.2f                                          ***\n",p->per_money);
        printf("          ***�������ͷ�ʽ��%s                                      ***\n",p->delivery);
        printf("          ***************************************************************\n");

        p = p->next;
    }
}

// ������Ʒչʾ
void List_single_show(object* p)
{
        printf("          ***************************************************************\n");
        printf("          ***��Ʒ��%s                                              ***\n",p->name);
        printf("          ***����״̬��%s                                          ***\n",p->location);
        printf("          ***����������%d                                            ***\n",p->num);
        printf("          ***���ﵥ�ۣ�%.2f                                          ***\n",p->per_money);
        printf("          ***�������ͷ�ʽ��%s                                      ***\n",p->delivery);
        printf("          ***************************************************************\n");
}

// ��ѯ������  �ҵ����ʺ���( �ܶຯ�����ǻ��ڴˣ�
void find(object* p, char F[],int find_choice)
{
    int find_flag = 0; // Ĭ��û�ҵ�
    // ����Ʒ����
    if(find_choice ==1 )
    {
        while(p != NULL)
        {
            if(strcmp(p->name, F) == 0 )
            {
                List_single_show(p);   // չʾ
                find_flag = 1;         // ��־�ҵ���
            }
            p = p->next;
        }
        if( find_flag == 0)
        {
            printf("          ***û�ҵ���\n");
        }
    }
    // ����Ʒ״̬
    if(find_choice == 2)
    {
        while(p != NULL )
        {
            if(strcmp(p->location, F) == 0)
            {
                List_single_show(p);   // չʾ
                find_flag = 1;         // ��־�ҵ���
            }
            p = p->next;
        }
        if(find_flag == 0)
        {
            printf("          ***û�ҵ���\n");
        }
    }
    // ����Ʒ���ͷ�ʽ
    if(find_choice ==3)
    {
        while(p != NULL )
        {
            if(strcmp(p->delivery, F) == 0)
            {
                List_single_show(p);   // չʾ
                find_flag = 1;         // ��־�ҵ���
            }
            p = p->next;
        }
        if(find_flag == 0)
        {
            printf("          ***û�ҵ���\n");
        }
    }

}

// ����������
void change(object** p)
{
    int find_flag = 0 , n =0 ;
    char things[N] = {'\0'}; // ������Ҫ���ĵ���Ʒ
    char change_Name[N] = {'\0'}; // ���ĵ�����
    char change_Location[N] = {'\0'};
    int change_Num = 0;
    float change_Per_money = 0;
    char change_Delivery[N] = {'\0'};

    printf("          ***��������Ҫ���ĵ����ʷ��ࣺ\n");
    printf("          ***���������Ʒ�����ƣ�");
    getchar();
    scanf("%s",things);
    *p = (*p)->next ;
    while((*p) != NULL )
    {
        if(strcmp((*p)->name, things) == 0)
        {
            List_single_show(*p);   // չʾ
            printf("          ***����������1��״̬2������3������4�����ͷ�ʽ5��");
            scanf("%d",&n);
            switch( n )
            {
            case 1:
                {
                    printf("          ***����������֣�");
                    scanf("%s",change_Name);
                    strcpy((*p)->name, change_Name);
                    break;
                }
            case 2:
                {
                    printf("          ***�������״̬��");
                    scanf("%s",change_Location);
                    strcpy((*p)->location, change_Location);
                    break;
                }
            case 3:
                {
                    printf("          ***�������������");
                    scanf("%d",&change_Num);
                    (*p)->num = change_Num;
                    break;
                }
            case 4:
                {
                    printf("          ***������ĵ��ۣ�");
                    scanf("%f",&change_Per_money);
                    (*p)->per_money = change_Per_money;
                    break;
                }
            case 5:
                {
                    printf("          ***����������ͷ�ʽ��");
                    scanf("%s",change_Delivery);
                    strcpy((*p)->delivery, change_Delivery);
                    break;
                }
            default:
                printf("          ***�������");
            }
            printf("���ĳɹ���\n");
            List_single_show(*p);
            find_flag = 1;         // ��־�ҵ���
        }
        (*p) = (*p)->next ;
    }
    if(find_flag == 0)
    {
        printf("          ***û�ҵ���\n");
    }

}

// ɾ��������
void delted(object** q)
{
    char things[N] = {'\0'}; // ������Ҫ���ĵ���Ʒ
    int k = 0;
    int find_flag = 0;

    printf("          ***��������Ҫɾ�������ʷ��ࣺ\n");
    printf("          ***����ɾ����Ʒ�����ƣ�");
    getchar();
    scanf("%s",things);
    while((*q)->next!= NULL )
    {
        if(strcmp((*q)->next->name, things) == 0)
        {
            printf("          ***�Ƿ�ɾ���������ʣ�\n");
            List_single_show((*q)->next);
            printf("          ***����1ɾ������0ȡ����");
            scanf("%d",&k);
            if( k ==1 )
            {
                (*q)->next = (*q)->next->next; // ɾ��
                printf("          ***�ѳɹ�ɾ����\n");
            }
            find_flag = 1;
        }
        (*q) = (*q)->next ;
    }
    if(find_flag == 0)
    {
        printf("          ***û�ҵ���\n");
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

    int choice = 0 ;    // �û�ѡ��
    int Creat_flag = 0; // ��������ѡ��
    int Find_flag = 0;  // ����ѡ��
    int find_choice =0; // ��ѯ����
    char F[N] = {'\0'};   // ��ѯ���ַ���
    choice = System_Show(choice);  // ����չʾ

    while(choice != -1)  // ϵͳ��ѭ�� choice = -1 ��������
    {
        if(choice == 1)
        {
            printf("          ************************¼��������Ϣ***************************\n");
            do
            {
                rear1 = Creat_list(rear1); // ��������

                printf("          ***����1�������ӻ���\n          ***����0ֹͣ���ӻ��");
                scanf("%d",&Creat_flag);
            }while(Creat_flag != 0);

            List_ALL_show(head->next); // չʾ����
        }

        if(choice == 2)
        {
            printf("          ************************����������Ϣ***************************\n");
            do
            {
                printf("          ***��������Ҫ���ҵķ��ࣺ\n");
                printf("          ***����1������Ʒ����\n          ***����2������Ʒ״̬\n          ***����3������Ʒ���ͷ�ʽ  ��");
                scanf("%d",&find_choice);
                printf("          ***��������Ҫ���ҵ���Ʒ���� / ״̬ / ���ͷ�ʽ��");
                getchar();
                scanf("%s",F);

                find(head->next,F,find_choice);

                printf("\n          ***����1�������һ���\n          ***����0ֹͣ���һ��");
                scanf("%d",&Find_flag);
            }while(Find_flag != 0);
        }

        if(choice == 3)
        {
            printf("          ************************����������Ϣ***************************\n");
            List_ALL_show(head->next); // չʾ����
            rear2 = head;
            change(&rear2);  // ������Ʒ��Ϣ
            List_ALL_show(head->next);
        }

        if(choice == 4)
        {
            printf("          ************************ɾ��������Ϣ***************************\n");
            List_ALL_show(head->next); // չʾ����
            rear3 = head;
            delted(&rear3);
            List_ALL_show(head->next);
        }

        choice = System_Show(choice);  // չʾ���棬��һ��ѭ��
    }
    List_ALL_show(head->next); // չʾϵͳ
    printf("          ***********************ϵͳ��������������**********************\n");

} 


