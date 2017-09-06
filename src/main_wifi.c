#include "wifi_ESP8266.h"
#include "serial.h"

int main(int argc ,char *argv[])
{
	int fd = init_tty();
	//host_initialize(fd);
	join_initialize(fd);
	//printf("send: %s\n", AT_CWSAP(ch,"0123456789",3));
	
}