public abstract class Vehicle        //抽象类，只能用于被重写与继承
{
    private String name;        //类成员
    private int speed;

    public Vehicle(){
        System.out.println("Vehicle 不带参数被调用");
    }

    public Vehicle(String name){
        this.name=name;
        System.out.println("Vehicle 带参数的被调用,参数是name");
    }

    public Vehicle(String name,int speed){
        this.name=name;
        this.speed=speed;
        System.out.println("Vehicle 全部参数被调用");
    }

    // public void info(){
    //     System.out.println(name+"准备好了");
    // }

    public void start(){
        System.out.println(name+"出发了"+"   "+"速度是："+speed);
    }

    public void stop(){
        System.out.println(name+"停车了");
    }   

    public String getName(String name){
        this.name=name;
        return this.name;
    }                           //方法获取名字

    public int getSpeed(int speed){
        this.speed=speed;
        return this.speed;
    }                           //方法获取速度

}

class Train extends Vehicle{
    
    public Train(){
        System.out.println(getName("Train")+"准备完毕");
    }

    public Train(String name){
        super(name);
    }       //利用super引用构造函数

    public Train(String name,int speed){
        super(name,speed);
    }       //利用super引用构造函数
}

class Aircraft extends Vehicle{
    public Aircraft(){
        System.out.println(getName("Aircraft")+"准备完毕");
    }

    public Aircraft(String name){
        super(name);
    }

    public Aircraft(String name,int speed){
        super(name,speed);
    }
}

class Mian{
    public static void main(String[] args){
        var train1=new Train("回家号",350);

        // train1.info();
        train1.start();

        train1.stop();

        var air1=new Aircraft("回家飞机",450);

        air1.start();
        air1.stop();
    }
}