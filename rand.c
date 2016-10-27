#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int randNum(){
  int *ans = (int*)malloc(4);
  int fd= open("/dev/random", O_RDONLY);
  read(fd, ans, 4);
  close(fd);
  int temp = *ans;
  free(ans);
  return temp;
}

int main(){
  //setting mask
  umask(0000);
 
  int rand1[10];
  int rand2[10];
  
  //populating Array
  printf("Generating random numbers...\n");
  for (int i = 0; i < 10; i++) {
    rand1[i] = randNum();
    printf("random[%d]: %d\n", i, rand1[i]);
  }

  //writing array
  printf("\nWriting numbers to file...\n\n");
  int fd = open("rand.txt", O_CREAT | O_WRONLY, 0644);
  int n = write(fd,rand1,40);
  close(fd);

  //verifying values
  printf("Reading numbers from file...\n\n");
  int fd2 = open("rand.txt", O_RDONLY);
  read(fd2, rand2, 40);
  close(fd2);
  printf("Verifying values...\n");
  for (int i = 0; i < 10; i++)
    printf("random[%d]: %d\n", i, rand2[i]);
  return 0;
}
