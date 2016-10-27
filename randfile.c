#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int randomize(){
  int fd = open("/dev/random", O_RDONLY);
  int num;
  read(fd, &num, 4);
  close(fd);
  return num;
}

int main(){
  int array1[10];
  int count = 0;
  while (count < 10){
    array1[count] = randomize();
    printf("random %d: %d\n", count, array1[count]);
    count++;
  }
  
  int fd1 = open("random.txt", O_CREAT | O_WRONLY);
  write(fd1, array1, 40);
  close(fd1);

  int array2[10];
  int fd2 = open("random.txt", O_RDONLY);
  read(fd2, array2, 40);
  close(fd2);

  int x = 0;
  printf("Comparing:\n");
  while (x < 10){
    printf("random %d: %d\n", x, array2[x]);
    x++;
  }
}
    
  
