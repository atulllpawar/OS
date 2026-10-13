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
} 
else 
{ 
printf("\n Parent Process started %d",getpid()); 
} 
return 0; 
}