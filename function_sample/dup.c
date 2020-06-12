#include <stdlib.h> 
#include <unistd.h> 
#include <fcntl.h>
#include <string.h>
  
int main() 
{ 
    int fd = open("dup.txt", O_CREAT | O_RDWR); 
    int copy_fd;

    copy_fd = dup(fd);  

    write(fd, "Test File descriptor\n", strlen("Test File descriptor\n"));
    write(copy_fd, "Test copy file descriptor\n", strlen("Test copy file descriptor\n"));
    close(fd);
    write(copy_fd, "Test second copy\n", strlen("Test stdout\n"));
    return (0); 
} 