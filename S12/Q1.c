#include<stdio.h> 
#include<stdlib.h> 
struct proc_info 
{ 
int atime; 
int btime; 
} proc[20]; 
typedef struct rqnode 
{ 
int pid; 
struct rqnode *next; 
}RQNODE; 
RQNODE *head=NULL, *temp, *last; 
struct ganttchart 
{ 
int stime; 
int pid; 
int etime; 
} gchart[20]; 
int i,n,ctime,gi=0,wtime[20],tatime[20]; 
void getprocs(); 
void start(); 
void addprocq(); 
void dispgchart(); 
void disptimes(); 
int getproc_id(); 
int finished(); 
int main() 
{ 
getprocs(); 
ctime=0;  
start(); 
dispgchart(); 
disptimes(); 
return 0; 
} 
void getprocs() 
{ 
printf("\nEnter No. of Processes : "); 
scanf("%d",&n); 
 
 printf("\nPID \tATime \tBTime \n"); 
 for(i=1;i<=n;i++) 
 { 
  printf("%d\t",i); 
  scanf("%d%d",&proc[i].atime,&proc[i].btime); 
 } 
} 
 
void start() 
{ 
 int pid; 
  
 addprocq();  
 pid=getproc_id(); 
 
 while(finished())  
 { 
  ctime++;   
  addprocq();  
 
  if(pid!=-1) 
  {  
   proc[pid].btime--; 
    
   if(proc[pid].btime==0) 
   { 
    printf("\nProcess %d completed at time %d",pid,ctime); 
    tatime[pid]=ctime-proc[pid].atime; 
    pid=getproc_id();  
   } 
  } 
 } 
  
 gchart[gi].etime=ctime; 
} 
 
void addprocq() 
{ 
 for(i=1;i<=n;i++) 
 { 
  if(proc[i].atime==ctime)   
  { 
   temp=(RQNODE*) malloc(sizeof(RQNODE)); 
  
   temp->pid=i; 
   temp->next=NULL; 
    
   if(head==NULL) 
   { 
    head=temp; 
   } 
   else 
   { 
    last->next=temp; 
   } 
    
   last=temp; 
  } 
 } 
} 
 
int finished()  
{ 
 for(i=1;i<=n;i++) 
 { 
  if(proc[i].btime!=0) 
  { 
   return(1); 
  } 
 } 
  
 return(0); 
} 
 
int getproc_id() 
{ 
 int pid; 
  
 if(head==NULL) 
 { 
  return(-1); 
 } 
  
 pid=head->pid; 
 temp=head;  
 head=head->next; 
 free(temp); 
  
 gchart[++gi].pid=pid; 
 gchart[gi].stime=ctime; 
 gchart[gi-1].etime=gchart[gi].stime; 
  
 wtime[pid]=ctime-proc[pid].atime; 
  
 return(pid); 
} 
 
void dispgchart() 
{ 
 printf("\n"); 
 for(i=1;i<=gi;i++) 
 { 
  printf("|----"); 
 } 
 printf("| \n"); 
 for(i=1;i<=gi;i++) 
 { 
  printf("| %d  ",gchart[i].pid); 
 } 
 printf("| \n"); 
 for(i=1;i<=gi;i++) 
 { 
  printf("|----"); 
 } 
 printf("| \n"); 
 for(i=1;i<=gi;i++) 
 { 
  printf("%d    ",gchart[i].stime); 
 } 
 printf("%d\n",gchart[gi].etime); 
} 
 
void disptimes() 
{ 
 int sumwt=0,sumtat=0; 
 
 printf("\n **Turnaround Time**\n"); 
 printf("\nPID \tTAT"); 
 for(i=1;i<=n;i++) 
 { 
  printf("\n %d \t %d",i,tatime[i]); 
  sumtat=sumtat+tatime[i]; 
 } 
 printf("\n Average TAT : %.2f\n",(float)sumtat/n); 
  
 printf("\n **Waiting Time**\n"); 
 printf("\nPID \tWT"); 
 for(i=1;i<=n;i++) 
 { 
  printf("\n %d \t %d",i,wtime[i]); 
  sumwt+=wtime[i]; 
 } 
 printf("\n Average WT : %.2f\n",(float)sumwt/n); 
} 