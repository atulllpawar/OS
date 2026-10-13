#include<stdio.h> 
#include<unistd.h> 
#include<sys/types.h> 
 
int main() 
{ 
  
 pid_t pid; 
 
 pid = fork(); 
 
 if(pid==0) 
 { 
  printf("\n Child Process started %d %d",getpid(),getppid()); 
  sleep(2); 
  printf("\n Child Process becomes orphan"); 
  printf("\n Child : Welcome "); 
  printf("\n Child Process exited"); 
 } 
 else 
 { 
  printf("\n Parent Process started %d",getpid()); 
  printf("\n Parent : Hello"); 
  printf("\n Parent Process exited"); 
 } 
 
 return 0; 
} 