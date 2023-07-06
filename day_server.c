#include<stdio.h>                                
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<time.h>
main(){
int sd,sd2,nsd,clilen,sport,len;
int port;
time_t  ticks;
char sendmsg[100],rcvmsg[100];
struct  sockaddr_in servaddr,cliaddr;
printf("Enter the server port:\n");
scanf("%d",&sport);
printf("%d",sport);
sd=socket(AF_INET,SOCK_STREAM,0);
ticks=time(NULL);
strcpy(sendmsg,ctime(&ticks)); 
if(sd<0)
printf("Can't create \n");
else
printf("Socket is created\n");
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(sport);
sd2=bind(sd,(struct  sockaddr*) &servaddr,sizeof(servaddr));
if(sd2<0)
printf("Can't bind\n");
else
printf(" Binded \n");
listen(sd,5);
clilen=sizeof(cliaddr);
nsd=accept(sd,(struct  sockaddr *)&cliaddr,&clilen);
if(nsd<0)
printf("Can't accept\n");
else
printf("Accepted\n");
send(nsd,sendmsg,100,0);
}















