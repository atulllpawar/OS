#include<stdio.h> 
#include<unistd.h> 
#include<sys/types.h> 
int main() 
{ 
pid_t pid; 
pid = fork(); 
if(pid==0) 
{ 
nice(-5); 
printf("\n Child Process started %d %d",getpid(),getppid()); 
printf("\n Child : Welcome to K2"); 
} 
else 
{ 
printf("\n Parent Process started %d",getpid()); 
printf("\n Parent : Welcome to K2"); 
} 
return 0; 
}