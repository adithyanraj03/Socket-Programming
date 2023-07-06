#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
main(){
int csd,cport,len;
char sendmsg[100],revmsg[100];
struct  sockaddr_in  servaddr;
printf("Enter the port \n");
scanf("%d",&cport);
printf("%d",cport);
csd=socket(AF_INET,SOCK_STREAM,0);
if(csd<0)
printf("Can't create\n");
else
printf("Socket is created\n");
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(cport);
if(connect(csd,(struct sockaddr *)&servaddr,sizeof(servaddr))<0)
printf("Can't  connect\n");
else
printf("Connected sucessfully\n");
recv(csd,revmsg,100,0);
printf("Message read %s",revmsg);









}
