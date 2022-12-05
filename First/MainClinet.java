import java.net.*;
import java.io.*;

 class MainClient{
	public static void main(String[] args)

	throws Exception
	{

	Socket socket =new Socket("127.0.0.1",2000);	//绑定地址是127.0.0.1并且绑定端口2000
	
	new ClientinputThread(socket).start();	//读取从服务端输出的线程	--从Creating 到 Wating
	new ClientOutputThread(socket).start();	//从键盘输入抛给服务器的线程
	
}

}

class ClientinputThread extends Thread	//利用继承线程的方法 创造读取服务端抛出的数据
{
	private Socket socket;		//创建socket 实例

	public ClientinputThread(Socket socket){	

		super();	//Super关键字 继承父类使用
		this.socket=socket;

	}		//重构函数

	@Override
	public void run(){	//让线程从Wating 到  Running
		try{
			InputStream is =socket.getInputStream();	//读取从服务端抛出的函数并且赋值给is

			while(true){						//无限循环
				var arr =new byte[1024];				//创造字节输出 用来装取从服务端抛出的数据
				int len=is.read(arr);				//利用输入流中的read函数 装填arr 并且返回长度给len
				System.out.println(new String(arr,0,len));		//从arr 第0位字节开始输出 长度为len个字节长度
			}
		}catch(IOException e){
			e.printStackTrace();	//输出错误信息
		}
	}
}

class ClientOutputThread extends Thread{	//继承线程方法 创造输出流抛给服务端

	private Socket socket;

	public ClientOutputThread(Socket socket){
		super();
		this.socket=socket;
	}

	@Override 
	public void run(){
		try{

			OutputStream os=socket.getOutputStream();	//创建OutputStream实例对象

			while(true){		
			BufferedReader reader =new BufferedReader(new InputStreamReader(System.in));	//创造BuffetedReader 实例对象
			
			String line=reader.readLine();		//从键盘获取信息赋值给line
				os.write(line.getBytes());		//利用 write方法发送给服务端
			}		

		}catch(IOException e){
			e.printStackTrace();
		}
	}
}
