#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int main(int argc,char* argv[]){
  printf("1\n");
  int fd = open("/dev/urandom",O_RDONLY);
  if (fd == -1){
    printf("error1");
    exit(-1);
  }
  unsigned char lotto[6];
  if(read(fd,lotto,6)!=6){
    printf("error2");
  }
  for(int j=0;j<6;j++){
    lotto[j] = (lotto[j] % 45) + 1;
  }
  printf("%s",lotto);
  close(fd);
  return 0;
}
