#include <stdlib.h> 
#include <unistd.h> 
#include <fcntl.h>
#include <string.h>
  
int main() 
{ 
    int fd = open("dup2.txt", O_CREAT | O_RDWR); 
      
    dup2(fd, 1);  

    write(fd, "Test File descriptor\n", strlen("Test File descriptor\n"));
    write(1, "Test stdout\n", strlen("Test stdout\n"));
    close(fd);
    write(1, "Test stdout numero 2\n", strlen("Test stdout numero 2\n"));
    return (0); 
} 