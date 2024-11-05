#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void asc(int *a, int sz);
int main(int argc,char *argv[])
{
    int arr[10];
    int i,size;
char *env[]={NULL};
FILE *f;
char *newarg[]={NULL,"sort.txt", NULL};
newarg[0]=argv[1];
pid_t pid;
printf("\nEnter size of array: ");
scanf("%d"
, &size);
printf("\nEnter %d elements: \n",size);
for(i=0; i<size; i++)
{
scanf("%d"
, &arr[i]);
}
pid = fork();
if(pid == 0)
{//sleep(1);
execve(argv[1],newarg,env);
//exit(0);
}
else
{
asc(arr, size);
f=fopen("sort.txt","w");
fprintf(f," %d",size);
for(i=0;i<size;i++)
{
}
fprintf(f," %d"
,arr[i]);
fclose(f);
}
return 0;
}
void asc(int *a,int sz)
{
int i, j;
int temp;
for(i=0; i<sz; i++)
{
for(j=i+1; j<sz; j++)
{
if(a[i]>a[j])
{
temp = a[i];
a[i] = a[j];
a[j] = temp;
}
}
}
printf("\n Parent Process");
printf("\nSorted array in ascending order is:\n");
for(i=0; i<sz; i++)
{
printf("%d\t"
, a[i]) ;
}
printf("\n");
}