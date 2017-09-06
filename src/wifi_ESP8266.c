#include "wifi_ESP8266.h"
int read_return(int fd ,const char *buf)
{

	char ch[MSGSIZE]={0};
	char *date = calloc(1,MSGSIZE * 5);
	int i = 0;
	while(1)
	{
		bzero(ch,sizeof(ch));
		i = read(fd,ch,MSGSIZE);
		
		strcat(date,ch);
		printf("%s",date);


		if(i <= 0 ) exit(0);
		else if(strstr(date,buf) != 0) break;
		

	}
	
	free(date);
	printf("\n\n\n\n------------------------\n\n\n\n");
	usleep(500000);
	return 0;
}
void host_initialize(int fd)//热点初始化
{
	

	write(fd, AT, strlen(AT)); printf("send: %s\n", AT);
	read_return(fd,"OK");

	
	write(fd, AT_RST, strlen(AT_RST)); printf("send: %s\n", AT_RST);
	read_return(fd,"OK");
	

	write(fd, AT_CWMODE2, strlen(AT_CWMODE2)); printf("send: %s\n", AT_CWMODE2);
	read_return(fd,"OK");
	
		
	write(fd, AT_RST, strlen(AT_RST)); printf("send: %s\n", AT_RST);
	read_return(fd,"OK");
	

	write(fd, AT_CWSAP("zZz","0123456789",3), strlen(AT_CWSAP("zZz","0123456789",3))); printf("send: %s\n", AT_CWSAP("zZz","0123456789",3));
	
	read_return(fd,"OK");

	write(fd, AT_CIPMUX1, strlen(AT_CIPMUX1)); printf("send: %s\n", AT_CIPMUX1);
	read_return(fd,"OK");
	

	write(fd, AT_CIPSERVER, strlen(AT_CIPSERVER)); printf("send: %s\n", AT_CIPSERVER);
	
	read_return(fd,"OK");

	

}

void join_initialize(int fd)//从端初始化
{
	char *msg = calloc(1, MSGSIZE);


	write(fd, AT, strlen(AT)); printf("send: %s", AT);
	read_return(fd,"OK");

	

	write(fd, AT_RST, strlen(AT_RST)); printf("send: %s", AT_RST);
	read_return(fd,"OK");

	

	write(fd, AT_CWMODE1, strlen(AT_CWMODE1)); printf("send: %s", AT_CWMODE1);
	read_return(fd,"OK");
	
	

	write(fd, AT_RST, strlen(AT_RST)); printf("send: %s", AT_RST);
	read_return(fd,"OK");

	

	write(fd, AT_CWLAP, strlen(AT_CWLAP)); printf("send: %s", AT_CWLAP);
	read_return(fd,"OK");

	

	write(fd, AT_CWJAP("TP-LINK_2198FA","CHEN85603778"), strlen( AT_CWJAP("TP-LINK_2198FA","CHAN85603778"))); printf("send: %s",  AT_CWJAP("zZz","0123456789"));
	read_return(fd,"OK");

	

	write(fd, AT_CIFSR, strlen(AT_CIFSR)); printf("send: %s", AT_CIFSR);

	read_return(fd,"OK");

	write(fd, AT_CIPMUX1, strlen(AT_CIPMUX1)); printf("send: %s", AT_CIPMUX1);

	read_return(fd,"OK");

	write(fd, AT_CIPSTART0, strlen(AT_CIPSTART0)); printf("send: %s", AT_CIPSTART);

	read_return(fd,"OK");

	/*write(fd, at13, strlen(at13)); printf("send: %s", at13);
	routine(fd);
	sleep(5);*/
	
	/*write(fd, at14, strlen(at14)); printf("send: %s", at13);
	bzero(msg,MSGSIZE);
	read(fd,msg,MSGSIZE);
	if( strstr(msg,"OK") == 0 ) goto start_s;*/
		

}



