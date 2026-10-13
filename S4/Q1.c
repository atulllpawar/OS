#include<stdio.h> 
#include<stdlib.h> 
int allocation[100][100],max[100][100],need[100][100],i,j,pr,rs; 
int allocated[100],available[100]; 
void accept() 
{  
printf("\n Enter No. of Processes : "); 
scanf("%d",&pr); 
printf("\n Enter No. of Resources : "); 
scanf("%d",&rs); 
printf("\n Enter Allocation Data : "); 
for(i=0;i<pr;i++) 
{ 
for(j=0;j<rs;j++) 
{ 
scanf("%d",&allocation[i][j]); 
} 
}  
printf("\n Enter Max Data : "); 
for(i=0;i<pr;i++) 
{ 
for(j=0;j<rs;j++) 
{ 
scanf("%d",&max[i][j]); 
} 
} 
} 
void accept_available() 
{  
 printf("\n Enter Available Resources : "); 
 for(j=0;j<rs;j++) 
 { 
  printf("\n %c : ",65+j); 
  scanf("%d",&available[j]); 
 } 
} 
 
void display() 
{  
 printf("\n Allocation Matrix : "); 
 for(i=0;i<pr;i++) 
 { 
  printf("\n"); 
  for(j=0;j<rs;j++) 
  { 
   printf(" %d ",allocation[i][j]); 
  } 
 } 
 
 printf("\n Max Matrix : "); 
 for(i=0;i<pr;i++) 
 { 
  printf("\n"); 
  for(j=0;j<rs;j++) 
  { 
   printf(" %d ",max[i][j]); 
  } 
 } 
} 
 
void display_available() 
{  
 printf("\n Available Resources : "); 
 for(j=0;j<rs;j++) 
 { 
  printf("\n %c = %d",65+j,available[j]); 
 } 
} 
 
void calc_need() 
{ 
 for(i=0;i<pr;i++) 
 { 
  for(j=0;j<rs;j++) 
  { 
   need[i][j] = max[i][j] - allocation[i][j]; 
  } 
 } 
 
 printf("\n Need Matrix : "); 
 for(i=0;i<pr;i++) 
 { 
  printf("\n"); 
  for(j=0;j<rs;j++) 
  { 
   printf(" %d ",need[i][j]); 
  } 
 } 
} 
 
int main() 
{ 
 char ch; 
 
 accept(); 
 
 while(1) 
 { 
  printf("\n a. Accept Available"); 
  printf("\n b. Display Allocation, Max"); 
  printf("\n c. Display the contents of need matrix"); 
  printf("\n d. Display Available"); 
  printf("\n q. Exit"); 
 
  printf("\n Enter Choice : "); 
  scanf("%c",&ch); 
 
  switch(ch) 
  { 
   case 'a': accept_available(); 
    break; 
   case 'b': display(); 
    break; 
   case 'c': calc_need(); 
    break; 
   case 'd': display_available(); 
    break; 
   case 'q': exit(0); 
   default: printf("\n Invalid Choice"); 
  } 
 } 
  
 return 0; 
}