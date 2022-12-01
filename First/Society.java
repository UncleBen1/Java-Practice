
class Person{
    private String name;
    private String phone;
    private String address;
    private int age;    

    public Person(){}   //  构造函数

    public Person(String name,String phone,String address,int age){
        this.name=name;
        this.phone=phone;
        this.address=address;
        this.age=age;
    }               //带参数的构造函数

    public void Declear(){
        System.out.println("中华人民共和国公民："+name+"\n"+address+"\n"+age+"\n"+phone);   //输出这普通人所有信息；
    }

    public void setName(String name){
        this.name=name;
    }
    public String getName(){
        return name;
    }                                   //name的setter与getter属性

    public void setAddress(String address){
        this.address=address;
    }
    public String getAddress(){
        return address;
    }                                   //address的setter与getter属性

    public void setPhone(String phone){
        this.phone=phone;
    }
    public String getPhone(){
        return phone;
    }                                   //phone的setter与getter属性

    public int setAge(int age){
        this.age=age;
        return this.age;
    }                                   //age的setter与getter属性


    
}

class Teacher extends Person
{
    private String grade;   //  教师所教年级
    private String subject;

    public Teacher(){}; //构造器
    
    public Teacher(String name,String phone,String address,int age,String grade,String subject){
        super(name,phone,address,age);      //super关键字获取父类
        this.grade=grade;
        this.subject=subject;
    }           //老师所教的年级是

    public void Teacherinfo(){
        System.out.println("年级："+grade+"  科目："+subject+"\n职工姓名:"+getName()+"\n职工联系方式:"+getPhone()+"\n职工住址:"+getAddress());
    }   //输出老师的所有信息

    public void Working(){
        System.out.println(getName()+"正在上课"+"   所教科目："+subject);
    }   //正在工作

    public void Offwork(){
        System.out.println(getName()+"已经下班了");
    }   //下班

}

class Student extends Person
{
    private String grade;
    private String classroom;

    public Student(){};
    public Student(String grade,String classroom,String name,String address,String phone,int age){
        // this(name)=name;
        super(name,phone,address,age);              //super关键字方法获取父类
        this.grade=grade;
        this.classroom=classroom;
    }

    

    public void listen(){
        System.out.println(getName()+"正在听讲");
    }

    public void relax(){
        System.out.println(getName()+"正在休息");
     }
} 

class Main{
    public static void main(String[] args){
        var p1=new Person("Huang","204668838","BeiJing",19);
        var p2=new Teacher("Li","20466828","Shanghai",19,"Seven","English");
        var p3=new Student("Seven","Seven","WenZiYang","WuHu","2020203902",22);

        p1.Declear();           //第一位公民
        p2.Teacherinfo();       //第二位是教师
        p3.listen();            

    
    }
}