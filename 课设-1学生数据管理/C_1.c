#include<stdio.h>

//#include<windows.h>

#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

typedef struct Node
{
	int Num;// 学号
    int StuId; //学号
	char Name[50];// 姓名
	char Sex[10];// 性别
	char Academic[50];// 系名
	int Eng;    //英语成绩
	int Math;   //数学成绩
    int Comp;   //计算机成绩
    int Sum;    // 总成绩

	struct Node* next;// 指针域
}node;

node list;// 链表

// 读取文件
int Read_FILE(node* L);

// 保存文件
int  Save_FILE(node* L);

// 主菜单界面
void welcome();

// 增加学生信息
void Add(node *L,node e);// 功能
void Add_Printf();// 界面

// 删除学生信息
void Delete_Printf(node*L);// 界面
void Delete(node* s);// 功能

// 修改学生信息
void Fix(node *L);

// 查询学生信息
void Search_Printf(node* L);// 界面
node* Search_id(int id, node* L);// 按学号进行查找
node* Search_name(char name[], node* L);// 按姓名进行查找

// 输出学生信息
void Print(node* L);// 功能
void Print_Printf();// 界面

// 排序学生信息
void Sort(node* L);
bool cmp_big_ID(node e1, node e2);// 学号从大到小
bool cmp_big_Score(node e1, node e2);// 成绩从大到小
bool cmp_small_ID(node e1, node e2);// 学号从小到大
bool cmp_small_Score(node e1, node e2);// 成绩从小到大

// 退出管理系统
void goodbye();

int main()
{
	int choice = 0;
	Read_FILE(&list);
	while (true)
	{
		welcome();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:// 增加学生信息
			Add_Printf();
			break;
		case 2:// 删除学生信息
			Delete_Printf(&list);
			break;
		case 3:// 修改学生信息
			Fix(&list);
			break;
		case 4:// 查询学生信息
			Search_Printf(&list);
			break;
		case 5:// 输出学生信息
			Print(&list);
			break;
		case 6:// 排序学生信息
			Sort(&list);
			break;
		case 0:// 退出管理系统
			goodbye();
			break;
		}
		printf("是否需要继续操作?(Yes:1 / No:0):");
		scanf("%d", &choice);
		if (choice == 0)
		{
			break;
		}
	}
	return 0;
}

void welcome()
{
	printf("==============================================================\n");
	printf("===================== 学生成绩管理系统 =========================\n");
	printf("====================  1 ---- 增加信息  =====================\n");
	printf("====================  2 ---- 删除信息  =====================\n");
	printf("====================  3 ---- 修改信息   =====================\n");
	printf("==================== 4 ---- 查询信息   ======================\n");
	printf("===================  5 ---- 输出信息   ======================\n");
	printf("===================  6 ---- 排序信息   ======================\n");
	printf("===================  0 ---- 退出管理系统   =======================\n");
	printf("================================================================\n");

}

// 读取文件
int Read_FILE(node* L)
{
	FILE* pfRead = fopen("student_information.txt", "r");
	node st;
	node* s;
	node* t = L;

	if (pfRead == NULL)
	{
		return 0;
	}

	while (fscanf(pfRead, "%d %d %s %s %s %d %d %d",&st.Num,&st.StuId,st.Name, st.Sex, st.Academic,&st.Eng, &st.Math,&st.Comp) != EOF)
	{
        st.Sum=st.Eng+st.Math+st.Comp;

		s = (node*)malloc(sizeof(node));

		*s = st;

		// 尾插法
		t->next = s;
		t = s;
		t->next = NULL;
	}

	return 1;
}

// 保存文件
int  Save_FILE(node* L)
{
	
	FILE* pfWrite = fopen("student_information.txt", "w");

	if (pfWrite == NULL)
	{
		return 0;
	}

	node* p = L->next;

	while (p != NULL)
	{
		
        fprintf(pfWrite,"%d %d %s %s %s %d %d %d\n",p->Num,p->StuId,p->Name,p->Sex,p->Academic,p->Eng,p->Math,p->Comp);
        
		p = p->next;
	}

	return 1;
}

// 增加学生信息
void Add_Printf()
{
	system("cls");
	node st;
	printf("请输入新增学生的相关信息：\n");
	printf("编号：");
	scanf("%d", &st.Num);
	printf("学号：");
	scanf("%d", &st.StuId);
	printf("姓名：");
	scanf("%s", st.Name);
	printf("性别：");
	scanf("%s", st.Sex);
	printf("系名：");
	scanf("%s", st.Academic);
	printf("英语成绩：");
	scanf("%d", &st.Eng);
	printf("数学成绩：");
	scanf("%d", &st.Math);
	printf("计算机成绩：");
	scanf("%d", &st.Comp);

	Add(&list, st);
}

void Add(node* L, node e)
{
	// 头插法
	node* p = L;
	node* s = (node*)malloc(sizeof(node));
	*s = e;

	s->next = p->next;
	p->next = s;

	Save_FILE(L);
}

// 删除学生信息
void Delete_Printf(node* L)
{
	system("cls");
	int id;

	node* p;

	printf("请输入要删除的学生的学号：");
	scanf("%d", &id);
	node* st = Search_id(id, L);
	p = st;

	if (st == NULL)
	{
		printf("查无此人！\n");
		return;
	}

	st = st->next;
	
    Print_Printf();
    printf("%d  %d  %s  %s  %s  %d  %d  %d %d\n",st->Num,st->StuId,st->Name,st->Sex,st->Academic,st->Eng,st->Math,st->Comp,st->Sum);

	Delete(p);
	// 保存信息
	Save_FILE(L);
}

void Delete(node* s)
{
	node* t = s->next;

	s->next = t->next;
	t->next = NULL;

	free(t);
}

// 修改学生信息
void Fix(node* L)
{
	system("cls");	
	int id;
	printf("请输入要修改的学生的学号：");
	scanf("%d", &id);
	node* st = Search_id(id, L);

	if (st == NULL)
	{
		printf("查无此人！\n");
		return;
	}

	st = st->next;

	int choice = 0;
	while (1)
	{
		system("cls");

		//要修改的学生成绩
		Print_Printf();
        printf("%d  %d  %s  %s  %s  %d  %d  %d\n",st->Num,st->StuId,st->Name,st->Sex,st->Academic,st->Eng,st->Math,st->Comp);

        printf("修改编号 ---- 1\n");
        printf("修改学号 ---- 2\n");
		printf("修改姓名 ---- 3\n");
		printf("修改性别 ---- 4\n");
		printf("修改系名 ---- 5\n");
		printf("修改英语成绩 ---- 6\n");
		printf("修改数学成绩 ---- 7\n");
        printf("修改计算机成绩 ---- 8\n");

		printf("请输入要修改的信息：");
		scanf("%d", &choice);

		switch (choice)
		{
        
        case 1:{
            printf("请输入编号");
            scanf("%d",&st->Num);
            break;
        }
        case 2:{
            printf("请输入学号");
            scanf("%d",&st->StuId);
            break;
        }

		case 3:
			printf("请输入姓名：");
			scanf("%s", st->Name);
			break;
		case 4:
			printf("请输入性别：");
			scanf("%s", st->Sex);
			break;
		case 5:
			printf("请输入系名：");
			scanf("%s", st->Academic);
			break; 
		case 6:
			printf("请输入英语成绩：");
			scanf("%d",&st->Eng);
			break;
		case 7:
			printf("请输入数学成绩：");
			scanf("%d",&st->Math);
			break;
        case 8:{
            printf("请输入计算机成绩：");
            scanf("%d",&st->Comp);
            break;
            
        }
		}
		printf("是否继续修改该学生信息？（Yes：1 / No：0）：");
		scanf("%d", &choice);
		if (choice == 0)
		{
			break;
		}
	}

	// 修改完成后该学生的信息
	Print_Printf();
    printf("%d  %d  %s  %s  %s  %d  %d  %d\n",st->Num,st->StuId,st->Name,st->Sex,st->Academic,st->Eng,st->Math,st->Comp);
	
	// 保存信息
	Save_FILE(L);
}

// 查询学生信息
void Search_Printf(node* L)
{
	system("cls");
	int choice = 0;
	printf("按照学号查询 ---- 1\n");
	printf("按照姓名查询 ---- 2\n");
	printf("请输入查询方式：");
	scanf("%d", &choice);

	int id;
	char name[50];
	node* st;
	if (choice == 1)
	{
		printf("请输入要查询的学号：");
		scanf("%d", &id);
		st = Search_id(id, L);

		if (st == NULL)
		{
			printf("查无此人！\n");
		}
		else
		{
			st = st->next;
			printf("查找到该学号对应同学，该同学信息如下\n");
			Print_Printf();
            printf("%d  %d  %s  %s  %s  %d  %d  %d %d\n",st->Num,st->StuId,st->Name,st->Sex,st->Academic,st->Eng,st->Math,st->Comp,st->Sum);
			
		}
	}
	else if (choice == 2)
	{
		printf("请输入要查询的姓名：");
		scanf("%s", name);
		st = Search_name(name, L);

		if (st == NULL)
		{
			printf("查无此人！\n");
		}
		else
		{
			st = st->next;
            printf("查找到%s同学，该同学信息如下",name);
			Print_Printf();
            printf("%d  %d  %s  %s  %s  %d  %d  %d\n",st->Num,st->StuId,st->Name,st->Sex,st->Academic,st->Eng,st->Math,st->Comp);
			
		}
	}
}

// 按学号进行查找
node* Search_id(int id, node* L)
{
	node* p = L;
	
	while (p->next != NULL)
	{
		if (p->next->StuId == id)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

// 按姓名进行查找
node* Search_name(char name[], node* L)
{
	node* p = L;

	while (p->next != NULL)
	{
		if (strcmp(name, p->next->Name) == 0)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

// 输出学生信息
void Print(node* L)
{
	system("cls");
	node* p = L->next;
	Print_Printf();
	if (p != NULL)
	{
		while (p != NULL)
		{
            printf("%d  %d  %s  %s  %s  %d  %d  %d %d\n",p->Num,p->StuId,p->Name,p->Sex,p->Academic,p->Eng,p->Math,p->Comp,p->Sum);
			p = p->next;
		}
	}
}

void Print_Printf()
{
	    printf("编号 学号 姓名 性别 系名 英语 数学 计算机 总分\n");
}

// 排序学生信息
void Sort(node* L)
{
	system("cls");
	int choice = 0;
	printf("按照学号从大到小排序 ---- 1\n");
	printf("按照学号从小到大排序 ---- 2\n");
	printf("按照总成绩从大到小排序 ---- 3\n");
	printf("按照总成绩从小到大排序 ---- 4\n");
	printf("请选择排序方式：");
	scanf("%d", &choice);

	int flag = 0;
	for (node* p = L->next; p != NULL; p = p->next)
	{
		for (node* q = p; q != NULL; q = q->next)
		{
			switch (choice)
			{
			case 1:
				if (!cmp_big_ID(*p, *q))
				{
					flag = 1;
				}
				break;
			case 2:
				if (!cmp_small_ID(*p, *q))
				{
					flag = 1;
				}
				break;
			case 3:
				if (!cmp_big_Score(*p, *q))
				{
					flag = 1;
				}
				break;
			case 4:
				if (!cmp_small_Score(*p, *q))
				{
					flag = 1;
				}
				break;
			}
			if (flag == 1)
			{
				// 交换数据域
				node t = *p;
				*p = *q;
				*q = t;
				// 处理指针域
				t.next = p->next;
				p->next = q->next;
				q->next = t.next;
				flag = 0;
			}
		}
	}
}

// 学号从大到小
bool cmp_big_ID(node e1, node e2)
{
	return e1.StuId > e2.StuId;
}
// 成绩从大到小
bool cmp_big_Score(node e1, node e2)
{
	return e1.Sum > e2.Sum;
}

// 学号从小到大
bool cmp_small_ID(node e1, node e2)
{
	return e1.StuId < e2.StuId;
}
// 成绩从小到大
bool cmp_small_Score(node e1, node e2)
{
	return e1.Sum < e2.Sum;
}

// 退出管理系统
void goodbye()
{
	system("cls");
	printf("欢迎下次使用学生信息管理系统！");
	exit(0);// 结束程序
}
