#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
int main(){
	struct addrinfo hints,*res;
	hints.ai_socktype=SOCK_STREAM;
	hints.ai_family=AF_UNSPEC;
	memset(&hints,0,sizeof(hints));
	getaddrinfo("127.0.0.1","5056",&hints,&res);
	int s=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
	connect(s,res->ai_addr,res->ai_addrlen);
	char msg[]="This is a test message";
	int remain=sizeof(msg);
	int sent=0;
	while(sent<remain){
	int n=(int)send(s,msg+sent,remain,0);
	
	sent+=n;
	remain-=n;	
		}
		printf("Bytes Sent:%d\n",sent);
	
	
	return 0;
	}
