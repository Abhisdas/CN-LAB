#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
int main()
{
int sockfd,fd1,length,i;
char buf[100],buf1[100];
struct sockaddr_in sa,ca;

sockfd=socket(AF_INET,SOCK_STREAM,0);

sa.sin_family=AF_INET;
sa.sin_addr.s_addr=inet_addr("127.0.0.1");
sa.sin_port=htons(6034);

i=bind(sockfd,(struct sockaddr *)&sa,sizeof(sa));
printf("test %d%d\n",sockfd,i);

listen(sockfd,5);

length=sizeof(sa);
fd1=accept(sockfd,(struct sockaddr *)&ca,&length);

int k=recv(fd1,buf,100,0);
buf[k]='\0';
printf("%s\n",buf);

printf("Enter a message\t");
gets(buf1);
send(fd1,buf1,strlen(buf1),0);

close(sockfd);
close(fd1);
}