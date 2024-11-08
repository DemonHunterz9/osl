#include<stdio.h>
 int present(int table_frame[], int nf, int page)
 {
 for(int i=0; i<nf; i++)
  if(page == table_frame[i])
   return 1;
 return 0;
 }
 void printtable(int table_frame[], int nf)
 {
 for(int i=0; i<nf; i++)
 {
  if(table_frame[i] == -1)
   printf("-- ");
  else
   printf("%2d ", table_frame[i]);
 }
 printf("||");
 }
 int main()
 {
    //nf-number of frames
    int n,nf,i,pos=0;
    printf("enter number of frames\n");
    scanf("%d",&nf);
    int table_frame[nf];
    for(i=0;i<nf;i++)
    {
        table_frame[i]=-1;
    }
    printf("enter total number of page requests\n");
    scanf("%d",&n);
    int pages[n];
    printf("enter reference string\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pages[i]);
    }
    int count1=0;
    printf("position of frame table after each request\n");
    for(i=0;i<n;i++)
    {
        printf("page table after request from %2d || ",pages[i]);
        if(!present(table_frame,nf,pages[i]))
        {
           table_frame[pos] = pages[i];
           pos = (pos+1)%nf ;//considering it as a queue
           printtable(table_frame,nf);
           printf("page fault\n");
           count1++;
           continue;
        }
        printtable(table_frame,nf);
  printf("\n");
    }
    printf("\nNumber of page faults : %d\n\n", count1);
 }