#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void desc(int *a, int sz);
int main(int argc,char *argv[])
{
int arr[10],i,size;
FILE *f;
f=fopen(argv[1],"r");
printf(" %s"
,argv[1]);
fscanf(f,"%d"
,&size);
printf(" Array Size is: %d\n",size);
for(i=0;i<size;i++)
{
fscanf(f," %d"
,&arr[i]);
printf(" %d"
,arr[i]);
}
desc(arr, size);
return(0);
}
void desc(int *a, int sz)
{
int i, j;
int temp;
for(i=0; i<sz; i++)
{
for(j=i+1; j<=sz; j++)
{
if(a[i]<a[j])
{
temp = a[i];
a[i] = a[j];
a[j] = temp;
}
}
}
printf("\n Child Process");
printf("\nSorted array in descending order is:\n");
for(i=0; i<sz; i++)
{
printf("%d\t"
, a[i]) ;
}
printf("\n");
}