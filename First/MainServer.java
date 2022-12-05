import java.net.*;
import java.io.*;

public class MainServer{
	public static void main(String[] args)
	throws Exception
	{
	
		ServerSocket serversocket=new ServerSocket();	//定义服务器对象
		serversocket.bind(new InetSocketAddress("127.0.0.1",2000));	//绑定端口和ip
		
		while(true){
		
		Socket socket=serversocket.accept();	//监听客户端
		
		new InputThread(socket).start();	//开启读取流线程
		new OutputThread(socket).start();//开启输出流线程

				
		}
	}
}

 class InputThread extends Thread 	//继承方法 创建线程
{
	private Socket socket;

	public InputThread(Socket socket){
	super();
	this.socket=socket;
	}

	@Override
	public void run()
	{
		try{

			InputStream is=socket.getInputStream();	//创建InputStream对象is 获取客户端抛出的信息
		
		while(true){
		
		var arr=new byte[1024]; 	//将is的信息 填装到字节数组arr中
		int len=is.read(arr);		//利用read方法 实现装填 并且返回字节长度
		System.out.println(new String(arr,0,len));		//终端输出arr

		}
		}
		catch(IOException e){
			
			e.printStackTrace();
		
		}
		
		}
	}



class OutputThread extends Thread	//继承船舰线程
{ 
		private Socket socket;

		public OutputThread(Socket socket){
			super();
			this.socket=socket;
		}
	@Override		//重写run方法
	public void run()
	{
		try{
		OutputStream os =socket.getOutputStream();	//创建OutputStream对象 os
		
		while(true){
		
			//创建BufferedReader 对象 reader
		BufferedReader reader =new BufferedReader(new InputStreamReader(System.in));
		

		String line =reader.readLine();	//利用文件流输中readLine方法赋值给line
		
		//利用输出流抛出信息
		os.write(line.getBytes());

		}
		}catch(IOException e){
		e.printStackTrace();
		}
	
	}
}
	


