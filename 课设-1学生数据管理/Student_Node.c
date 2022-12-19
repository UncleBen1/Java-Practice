#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100

int len=0; //目前长度

struct StuInfo{
int Num;// 编号
int StuId; //学号
char Name[50];// 姓名
char Sex[10];// 性别
char Academic[50];// 系名
int Eng; //英语成绩
int Math; //数学成绩
int Comp; //计算机成绩
int Sum; // 总成绩
};

struct StuInfo stu[MAXSIZE];

/**
* 增加学生操作
*/
void Add(){
len++;
int p=0;
printf("请输入你要插入的位置：");
scanf("%d",&p);
for(int i=len;i>=p;i--){
stu[i-1].Num++;
stu[i]=stu[i-1];
}// 10 3 8

printf("输入编号：");
scanf("%d",&stu[p-1].Num);
printf("输入学号：");
scanf("%d",&stu[p-1].StuId);
printf("输入姓名：");
scanf("%s",stu[p-1].Name);
printf("输入性别：");
scanf("%s",stu[p-1].Sex);
printf("输入系名：");
scanf("%s",stu[p-1].Academic);
printf("输入英语成绩：");
scanf("%d",&stu[p-1].Eng);
printf("输入数学成绩：");
scanf("%d",&stu[p-1].Math);
printf("输入计算机成绩：");
scanf("%d",&stu[p-1].Comp);

printf("添加完成");

}

/**
* 读取文件操作
*/

void Read_File()
{

FILE *fp; 

fp=fopen("student_information.txt","r");
if(fp==NULL)
{
printf("文件不存在！");
exit(1); 
}
while(fscanf(fp,"%d %d %s %s %s %d %d %d ",&stu[len].Num,&stu[len].StuId,stu[len].Name,stu[len].Sex,stu[len].Academic,&stu[len].Eng,&stu[len].Math,&stu[len].Comp)!=EOF)
{
len++;
}

fclose(fp);
printf("读取完毕！\n"); 
return ;
} 

/**
* 更改文件保存操作
*/
void Save_File(){
FILE *fp;
int i=0;
fp=fopen("student_information.txt","w");
if(fp==NULL){
printf("文件指针打开失败");
return ;
}
for(i;i<len;i++){
fprintf(fp,"%d %d %s %s %s %d %d %d %d\n",stu[i].Num,stu[i].StuId,stu[i].Name,stu[i].Sex,stu[i].Academic,stu[i].Eng,stu[i].Math,stu[i].Comp,stu[i].Eng+stu[i].Math+stu[i].Comp);
}
fclose(fp);
printf("写入文本完毕");
return ;
}

/**
* 打印顺序表数据操作
*/
void Printf_Stu(){
int k=0;
printf("编号 学号 姓名 性别 系名 英语成绩 数学成绩 计算机成绩 总成绩\n");
for(k;k<len;k++){
printf("%d %d %s %s %s %d %d %d %d\n",stu[k].Num,stu[k].StuId,stu[k].Name,stu[k].Sex,stu[k].Academic,stu[k].Eng,stu[k].Math,stu[k].Comp,stu[k].Eng+stu[k].Math+stu[k].Comp);
}
printf("输出完毕");
return ;
}

/**
* 查找操作
*/

void Search_Stu(){
char name[50];
int id=0;
int i=0;
int commond=0;
printf("按姓名查找-------1,按学号查找输入--------2\n");
scanf("%d",&commond);

if(commond==1){
printf("输入你要查找的姓名：");
scanf("%s",name);
for(i=0;i<len;i++){
if(strcmp(name,stu[i].Name)==0){
printf("%s信息如下:\n",name);
printf("%d %d %s %s %s %d %d %d\n",stu[i].Num,stu[i].StuId,stu[i].Name,stu[i].Sex,stu[i].Academic,stu[i].Eng,stu[i].Math,stu[i].Comp); 
return ;
}
}
printf("抱歉文本中没有名为%s的同学",name);
return ;
}

if(commond ==2){
printf("请输入你要查找的学号");
scanf("%d",&id);
for(i=0;i<len;i++){
if(id==stu[i].StuId){
printf("该学号信息如下：\n");
printf("%d %d %s %s %s %d %d %d\n",stu[i].Num,stu[i].StuId,stu[i].Name,stu[i].Sex,stu[i].Academic,stu[i].Eng,stu[i].Math,stu[i].Comp); 
return ;
}
}
printf("抱歉，该学号不存在于文当中\n");
return ;
}
}

void Change_Info(){
int id;
int i=0;
int choice=0;
printf("请输入你想要修改同学的id：");
scanf("%d",&id);
for(i=0;i<len;i++){
if(id==stu[i].StuId){
printf("查找到该id对应的同学");
printf("%d %d %s %s %s %d %d %d\n",stu[i].Num,stu[i].StuId,stu[i].Name,stu[i].Sex,stu[i].Academic,stu[i].Eng,stu[i].Math,stu[i].Comp); 
while(1){
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
scanf("%d",&stu[i].Num);
break;
}
case 2:{
printf("请输入学号");
scanf("%d",&stu[i].StuId);
break;
}

case 3:
printf("请输入姓名：");
scanf("%s", stu[i].Name);
break;
case 4:
printf("请输入性别：");
scanf("%s",stu[i].Sex);
break;
case 5:
printf("请输入系名：");
scanf("%s",stu[i].Academic);
break; 
case 6:
printf("请输入英语成绩：");
scanf("%d",&stu[i].Eng);
break;
case 7:
printf("请输入数学成绩：");
scanf("%d",&stu[i].Math);
break;
case 8:{
printf("请输入计算机成绩：");
scanf("%d",&stu[i].Comp);
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
}
}
return ;
}

void Sort_Stu(){
int choice=0;
struct StuInfo s; //创建结构体结点
printf("按总分从大到小排序-----1,按总分从小到大排序------2\n");
scanf("%d",&choice);
switch(choice){
case 1: {
printf("按总分从小到大排序\n");
//选择排序
for(int i=0;i<len-1;i++){ 
for(int j=i+1;j<=len-1;j++){
if(stu[j].Eng+stu[j].Math+stu[j].Comp<stu[i].Eng+stu[i].Math+stu[i].Comp){
s=stu[j];
stu[j]=stu[i];
stu[i]=s;
}
}
}
break;
}

case 2: {
printf("按总分从大到小排序\n");
//冒泡排序
for(int i=1;i<=len-1;i++)
for(int j=0;j<len-i;j++){
if(stu[j].Eng+stu[j].Math+stu[j].Comp<stu[j+1].Eng+stu[j+1].Math+stu[j+1].Comp){
s=stu[j+1];
stu[j+1]=stu[j];
stu[j]=s;
}
}
break;
}

case 3:{
//直接插入排序
printf ("按总分从小到大排序\n");
int i=0;
int j=0;

for(i=1;i<len;i++){ //从数组第二个开始依次遍历无序数组
s=stu[i]; //临时保留需要插入的元素
for(j=i-1;s.Eng+s.Math+s.Comp<=stu[j].Eng+stu[j].Math+stu[j].Comp&&j>=0;j--){//将待排元素依次和有序元素比较
//小于
stu[j+1]=stu[j];
}
stu[j+1] =s;
}
return ;
}
default :{
break;
}
}
}
void Delete_Stu(){
printf("请输入你要删除的学生的学号：");
int id=0;
int j=0;
while(true){
scanf("%d",&id);
for(int i=0;i<len;i++){
if(id==stu[i].StuId){
for(j=i;j<len-1;j++){
stu[i].Num--;
stu[j]=stu[j+1];
}
len--;
printf("删除成功\n");
return ;
}
}
printf("学号输入错误，请重新输入");
}
}

void Welcome()
{
printf("==============================================================\n");
printf("===================== 学生成绩管理系统 =========================\n");
printf("==================== 1 ---- 增加信息 =====================\n");
printf("==================== 2 ---- 删除信息 =====================\n");
printf("==================== 3 ---- 修改信息 =====================\n");
printf("==================== 4 ---- 查询信息 ======================\n");
printf("=================== 5 ---- 输出信息 ======================\n");
printf("=================== 6 ---- 排序信息 ======================\n");
printf("=================== 0 ---- 退出管理系统 =======================\n");
printf("================================================================\n");

}

/**
* 插入学生操作
* Add到学生后 选择一个位置插入
* 后面位置上的Num+1 i位之前不变 用 for循环来
*/

void Insert_Stu(){

}

int main(void){
Read_File();
int commond=0;
while(true){
Welcome();
scanf("%d",&commond);
switch (commond)
{
case 0:{
printf("成功退出管理学生管理系统\n");
break;
}
case 6:{
Sort_Stu();
Save_File();
break;
}

case 5:{
Printf_Stu();
break;
}

case 4:{
Search_Stu();
break;
}
case 3:{
Change_Info();
Save_File();
break;
}

case 2:{
Delete_Stu();
Save_File();
break;
}
case 1:{
Add();
Save_File();
break;
}
default:{
printf("你想要的功能还有待开发\n");
break;
}
break;
}
int a=0;
printf("你是否还需要继续操作？（YES：1/NO：0）");
scanf("%d",&a);
if(a==0){
break;
}
}
return 1;
}