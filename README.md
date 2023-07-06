# Socket-Programming
This repository contains three code files written in different programming languages: C, C++, and Java. Each code file represents a client-server communication program.
C Programs:
- The file "client.c" represents a client program written in C.
- It creates a socket and connects to a server using the specified port number.
- It receives a message from the server and prints it on the console.
- To compile and run the program, use the following commands:
  - gcc client.c -o client
  - ./client

 C++ Programs:
- The file "server.c" represents a server program written in C++.
- It creates a socket, binds it to a specified port, and listens for incoming connections.
- Once a connection is established, it sends the current time to the connected client.
- To compile and run the program, use the following commands:
  - g++ server.c -o server
  - ./server

Java Programs:
- The file "daytimeclient.java" represents a client program written in Java.
- It creates a socket and connects to a server using the specified hostname and port number.
- It receives the current time from the server and prints it on the console.
- To compile and run the program, use the following commands:
  - javac daytimeclient.java
  - java daytimeclient [hostname]

Note: If no hostname is provided, the program will default to "localhost".
