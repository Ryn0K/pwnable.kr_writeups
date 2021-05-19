#include <stdio.h>
#include <fcntl.h>

#define PW_LEN 10
#define XORKEY 1

void xor(char* s, int len){
	int i;
	for(i=0; i<len; i++){
		s[i] ^= XORKEY; //s[i] = s[i]^XORKEY;
	}
}

int main(int argc, char* argv[]){
	
	int fd;
	if(fd=open("password",O_RDONLY,0400) < 0){ // open() will always return non-negative integer on successfull but it is then compared to < 0 which is flase and led the fd value = 0(stdin) from 
	//user input stream
		printf("can't open password %d\n", fd);
		return 0;
	}

	printf("do not bruteforce...\n");
	sleep(time(0)%20);

	char pw_buf[PW_LEN+1];
	int len;
	if(!(len=read(fd,pw_buf,PW_LEN) > 0)){
		printf("read error\n");
		close(fd);
		return 0;		
	}

	char pw_buf2[PW_LEN+1];
	printf("input password : ");
	scanf("%10s", pw_buf2);
//from here on pwnbuff == pwnbuff2 s
//so we need to choose the value of pw_buff and pw_buff2^1 is always equal.
	// xor your input
	xor(pw_buf2, 10);

	if(!strncmp(pw_buf, pw_buf2, PW_LEN)){
		printf("Password OK\n");
		system("/bin/cat flag\n");
	}
	else{
		printf("Wrong Password\n");
	}

	close(fd);
	return 0;
}