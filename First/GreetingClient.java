import java.net.*;
import java.io.*;


public class GreetingClient{
    public static void main(String[] args)
    throws IOException
    {
        String servername=args[0];
        int port =Integer.parseInt(args[1]);
        try{
            System.out.println("连接到主机："+servername+"    端口："+port);
            //建立服务端第一步  监听窗口
            Socket client=new Socket(servername,port); 
            System.out.println("远程主机地址："+client.getRemoteSocketAddress());

            //发送给服务器信息的方法
            OutputStream outToserver=client.getOutputStream();
            DataOutputStream out =new DataOutputStream(outToserver);
            out.writeUTF("你好"+client.getLocalSocketAddress());
            
            //获取来自服务器信息的方法
            InputStream inFromserver=client.getInputStream();
            DataInputStream in =new DataInputStream(inFromserver);
            System.out.println("等待服务器相应："+in.readUTF());
            
            //关闭服务器
            client.close();
        }catch(IOException e){
            e.printStackTrace();
        }
    }
}