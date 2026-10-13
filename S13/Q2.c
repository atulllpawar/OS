#include<stdio.h> 
#include<stdlib.h> 
int main() 
{ 
int rq[100],i,j,n,initial,size,total_head_move=0,direction,temp,index; 
printf("\n Enter No. of request : "); 
scanf("%d",&n); 
printf("\n Enter %d requests : ",n); 
for(i=0;i<n;i++) 
{ 
scanf("%d",&rq[i]); 
} 
printf("\n Enter total no. of cylinders : "); 
scanf("%d",&size); 
printf("\n Enter initial head position : "); 
scanf("%d",&initial); 
printf("\n Enter Direction 0 for left and 1 for right : "); 
scanf("%d",&direction); 
for(i=1;i<n;i++) 
{ 
for(j=0;j<n-i;j++) 
{ 
if(rq[j]>rq[j+1]) 
{ 
temp = rq[j]; 
rq[j] = rq[j+1]; 
rq[j+1] = temp; 
} 
} 
} 
for(i=0;i<n;i++) 
{ 
if(rq[i]>initial) 
{ 
index = i; 
break; 
} 
} 
if(direction==0) 
{ 
for(i=index-1;i>=0;i--) 
{ 
total_head_move += abs(initial-rq[i]); 
initial = rq[i]; 
} 
        for(i=index;i<n;i++)                               
        { 
            total_head_move += abs(initial-rq[i]); 
            initial = rq[i]; 
        } 
    } 
    else 
    { 
        for(i=index;i<n;i++) 
        { 
            //printf(" %d ",rq[i]); 
            total_head_move += abs(initial-rq[i]); 
            initial = rq[i]; 
        } 
        for(i=index-1;i>=0;i--) 
        { 
            total_head_move += abs(initial-rq[i]); 
            initial = rq[i]; 
        } 
    } 
 
    printf("\n Total head movement is : %d",total_head_move); 
 
    return 0; 
}