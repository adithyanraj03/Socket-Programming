// A daytime server
import java.net.*;
import java.io.*;
import java.util.Date;
 
public class daytimeserver {
 
  public final static int daytimePort = 1397;

  public static void main(String[] args) {

   ServerSocket theServer;
   Socket theConnection;
   PrintStream p;

   try {
     theServer = new ServerSocket(daytimePort);
     try {
       while (true) {
         theConnection = theServer.accept();
         p = new PrintStream(theConnection.getOutputStream());
         p.println(new Date());        
         theConnection.close();
       }
     }
     catch (IOException e) {
       theServer.close();
       System.err.println(e);
     }

   }  // end try
   catch (IOException e) {
     System.err.println(e);
   }

  }

}
