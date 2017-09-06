#include "serial.h"


int init_tty()
{
	char *device1 = calloc(1, 32);
	char *device2 = calloc(1, 32);
	strcpy(device1, "/dev/ttySAC1");//串口1
	strcpy(device2, "/dev/ttySAC2");//串口2
	
	
	
	int fd = open(device2, O_RDWR|O_NOCTTY);//打开串口文件
	if(fd == -1)
	{
		fprintf(stderr, "open() %s failed: %s\n",
				device2, strerror(errno));
		exit(0);
	}
	
	
	
	//串口初始化
	struct termios new_cfg, old_cfg;
	if(tcgetattr(fd, &old_cfg) != 0)
	{
		perror("tcgetattr() failed");
		exit(0);
	}

	bzero(&new_cfg, sizeof(new_cfg));

	new_cfg = old_cfg;
	cfmakeraw(&new_cfg);

	cfsetispeed(&new_cfg, B115200);//接收波特率
	cfsetospeed(&new_cfg, B115200);//发送波特率

	new_cfg.c_cflag |= CLOCAL | CREAD;

	new_cfg.c_cflag &= ~CSIZE;
	new_cfg.c_cflag |= CS8;

	new_cfg.c_cflag &= ~PARENB;
	new_cfg.c_cflag &= ~CSTOPB;

	new_cfg.c_cc[VTIME] = 0;
	new_cfg.c_cc[VMIN]  = 1;
	tcflush(fd, TCIFLUSH);

	if(tcsetattr(fd, TCSANOW, &new_cfg) != 0)
	{
		perror("tcsetattr() failed");
		exit(0);
	}
	
	return fd;
}




