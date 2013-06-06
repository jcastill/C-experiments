#include <stdio.h>
#include <sys/io.h>
#include <errno.h>
#include <string.h>

main() {
	int err = 0;
	printf("Trying to restart the system by sending 0xfe (System reset) to I/O port 0x64\n");
	err = ioperm(0x064,2,1);
	if (err) {
		printf("An error occurred while allowing port access permission from userspace: %s\n", strerror(errno));
		return errno;
	}
	outb(0xfe,0x64);
	return 0;
}

