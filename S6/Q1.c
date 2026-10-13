#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<malloc.h> 
#define SIZE 100 
typedef struct direntry 
{ 
char fname[20]; 
int ibno,blist[20],k; 
struct direntry *next; 
}DIRENT; 
DIRENT *dirst=NULL,*dirend=NULL; 
int bitvector[SIZE]; 
int main() 
{ 
int ch=0,i,j,n,flag; 
char fname[20]; 
DIRENT *t1,*t2; 
for(i=0;i<SIZE;i++) 
{ 
bitvector[i]=1; 
} 
while(1) 
{ 
printf("\n\n1. Show Bit Vector"); 
printf("\n2. Create New File"); 
printf("\n3. Show Directory"); 
printf("\n4. Exit"); 
printf("\nEnter Your Choice : "); 
scanf("%d",&ch); 
switch(ch) 
{ 
case 1 : 
for(i=0;i<SIZE;i++) 
{ 
printf("%4d",bitvector[i]); 
} 
break; 
case 2 : 
if(dirst==NULL) 
{ 
dirst=(DIRENT*)malloc(sizeof(DIRENT)); 
dirend=dirst; 
} 
else 
         { 
           dirend->next=(DIRENT*)malloc(sizeof(DIRENT)); 
           dirend=dirend->next; 
         } 
        dirend->next=NULL; 
      
     printf("\nEnter A Filename : "); 
        scanf("%s",dirend->fname); 
      
     printf("\n Enter The Number of Blocks To Allocate : "); 
        scanf("%d",&n); 
      
     dirend->k=n; 
        j=flag=0; 
         
     for(i=0;i<SIZE && n>0;i++) 
        { 
          if(bitvector[i]==1) 
           { 
             if(flag==0) 
             { 
        dirend->ibno=i; 
        flag=1; 
             } 
             else 
             { 
        dirend->blist[j++]=i;   
             } 
              
       bitvector[i]=0; 
       n--; 
           } 
         } 
        break; 
      case 3 : 
         printf("\n Directory : "); 
         printf("\n---------------------------------------------"); 
         printf("\n Filename  IndexBlockNo      Block List"); 
         printf("\n--------------------------------------------"); 
         for(t1=dirst;t1!=NULL;t1=t1->next) 
         {  
       printf("\n %-10s %5d\t",t1->fname,t1->ibno); 
            for(j=0;j<t1->k-1;j++) 
            { 
       printf("%5d",t1->blist[j]); 
      } 
         } 
         printf("\n-------------------------------------------"); 
         break; 
      case 4 :exit(0); 
       
      default: printf("\n Invalid Choice"); 
     } 
 } 
  
 return 0; 
}