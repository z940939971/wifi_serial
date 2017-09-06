CC = arm-none-linux-gnueabi-gcc

MAIN = wifi_main


$(MAIN):./src/*.c
	$(CC) $^ -o $@ -I ./inc

clean:
	$(RM) serial
