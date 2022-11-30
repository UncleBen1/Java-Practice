class Student{
	private String name;
	private String email;
	private String address;
	private String gender;
	private int age;

				//私有化成员数据
	public Student(){}	//构造器

	public Student(String name,String email,String address,String gender,int age){
		this.name=name;
		this.email=email;
		this.address=address;
		this.age=age;
		this.gender=gender;
	}					//构造函数
	
	public void setName(String name){
		this.name=name;
	}
	
	public String getName(){
		return name;			
	} 					//name的setter与getter属性
	
	public void setEmail(String email){
		this.email=email;
	}
	public String getEmail(){
		return email;
	}					//email的setter与getter属性
	
	public void setAddress(String address){
		this.address=address;
	}
	public String getAddress(){
		return address;
	}					//address的setter与getter属性
	
	public void setGender(String gender){
		this.gender=gender;
	}
	public String getGender(){
		return gender;
	}					//gender的setter与getter属性
	
	public void setAge(int age){
		this.age=age;
	}
	public int getAge(){
		return age;
	}					//age的setter与getter属性

    public void play(){
        System.out.println(name+"正在玩游戏");
    }                   //同学玩的一种方法

    public void drink(){
        System.out.println(name+"正在喝水");
    }                   //喝水的一种方式
	
	public String toString(){
	
		return "姓名"+name+
		"\n"+"姓名"+gender+
		"\n"+"年龄"+age+
		"\n"+"家庭住址"+address+
		"\n"+"E箱"+email;
		
	}       //重写toString（）方法输出成员信息
	
	// public static void main(String[] args){
	// var s1=new Student("HuangJUe","20466@qq.com","BeiJingYe","male",19);
	// System.out.println(s1.toString());
	// }                
    //第五章第一题
}

class Detial{
     private Student[] students;    //定义数组成员类型为Student类
     
     public void inin(){
        students=new Student[3];    //初始化students为Student 3个数组长度

        var s1=new Student("YangChangWu","123456@qq.com","HaiNanYe","male",19);

        students[0]=s1; //初始化s1后放入students数组第一位中

        var s2=new Student("WenZiYang","2222222@qq.com","HongHu","male",19);

        students[1]=s2;//初始化s2放入students数组第二位中

        var s3=new Student("LiXing","33333333@qq.com","ChongYangYe","male",10);

        students[2]=s3;//初始化s3放入students数组第三位中

     }      //初始化板块

     public String searchbyName(String name){
        String result="不好意思,通过名字查找,没有找到该学生";    //初始化返回值 后面找到在对String进行修改操作

        for(int i=0;i<students.length;i++){     //最大外层循环,查找students的人数
            var s =students[i];
            if(s.getName().equals(name)){       //利用name的getter属性和euqal函数比较字符串返回是否找到,找到了就输出这个学生的所有信息
                return s.toString();
            }
        }
        return result;
     }

     public String searchbyAddress(String address){     //通过地质查找 实现逻辑与按名字查找相同
        var result="不好意思,通过地址查找,没有找到住在"+address+"的同学";

        for(int i=0;i<students.length;i++){
            var s=students[i];
            if(s.getAddress().equals(address)){
                return s.toString();
            }
        }
        return result;
     }

     public String searchbyEmail(String email){
        var result="不好意思,没有同学的油箱是"+email;

        for(int i=0;i<students.length;i++){
            var s=students[i];
        if(s.getEmail().equals(email)){
            return s.toString();
          }
        }
        return result;
     }

     

     public static void main(String[] args){

        var a=new Detial();

        a.inin();       //初始化通讯录

        String name="YangChangWu";

        System.out.println(a.searchbyName(name));

        

        var email="2222222@qq.com";
        System.out.println(a.searchbyEmail(email));

        var address="BeiJIng";
        System.out.println(a.searchbyAddress(address));

     }
}