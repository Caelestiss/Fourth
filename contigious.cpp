#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TB 100
void conti_allocate();
void conti_deallocate();
void conti_display();
int conti_BFull();
struct Sequence
{
    char n[30];
    int len;
    int st;
}CF[30];
int conti_Table[TB],conti_pos=0,conti_r,i,j,ch,conti_B=0;
char conti_fn[30];
void conti()
{
     printf("\n Contiguous File Allocation \n\n");
     do{
     printf("\n\n1.Allocate\n2.Deallocate\n3.Display\n4.Exit");
     printf("\n\nEnter Your choice : ");
     scanf("%d",&ch);
     switch(ch)
     {
                case 1:
                    conti_pos++;
                    conti_allocate();
                    break;

                case 2:
                    conti_deallocate();
                    break;

                case 3:
                    conti_display();
                    break;

                case 4:
                    exit(0);

                default:
                    printf("\nInvalid Choice ");
        }
     }while(ch!=4);

}
void conti_allocate()
{
   printf("\nEnter File Name : ");
   scanf("%s",&(CF[conti_pos].n));
   printf("\nEnter File Length : ");
   scanf("%d",&(CF[conti_pos].len));
   if(conti_BFull())
   {
        conti_pos--;
       printf("\n\nNo Enough Free Space Available \n");
       return;
   }
   while(1)
   {
        i=0;
        conti_r=(rand()%TB+1);
        if(conti_r+CF[conti_pos].len-1>TB)
           continue;
        if(conti_Table[conti_r]==0)
        {
                for(i=conti_r+1;i<conti_r+CF[conti_pos].len;i++)
                    if(conti_Table[i]==1)
                        break;
        }
        if(i==conti_r+CF[conti_pos].len)
            break;


    }
    CF[conti_pos].st=conti_r;
    for(i=conti_r;i<conti_r+CF[conti_pos].len;i++)
        conti_Table[i]=1;
    printf("\n\tFile Allocation Table\n");
    printf("\nFileName\tStart\tLength\n");
    for(i=1;i<=conti_pos;i++)
    {
        printf("\n%s\t\t%d\t%d",CF[i].n,CF[i].st,CF[i].len);
        printf("\n");
    }

}
void conti_deallocate()
{
   printf("\nEnter The File Name : ");
   scanf("%s",&conti_fn);
   for(i=1;i<=conti_pos;i++)
   {
            if(strcmp(CF[i].n,conti_fn)==0)
            {
                    for(j=CF[i].st ;j<(CF[i].len+CF[i].st);j++)
                        conti_Table[j]=0;
                    strcpy(CF[i].n,"NULL");
                    CF[i].st=0;
                    CF[i].len=0;
                    printf("\nFile (%s) Deleted Successfully \n",conti_fn);
                    break;
            }
            else
                printf("\nDeletion Unsuccessful\n");
    }
    printf("\n\t\tFile Allocation Table\n");
    printf("\nFileName\tStart\tLength\n");
    for(i=1;i<=conti_pos;i++)
    {
        printf("\n%s\t\t%d\t%d",CF[i].n,CF[i].st,CF[i].len);
        printf("\n");
    }
}
void conti_display()
{
    printf("\nEnter The File Name : ");
    scanf("%s",conti_fn);
    printf("\nBlocks Allocated Are : ");
    for(i=1;i<=conti_pos;i++)
    {
        if(strcmp(CF[i].n,conti_fn)==0)
        {
            for(j=CF[i].st;j<(CF[i].st+CF[i].len);j++)
                printf("--%d--",j);
            break;
        }
    }
}
int conti_BFull()
{
    for(i=1,conti_B=0;i<=conti_pos;i++)
        conti_B=conti_B+CF[i].len;
    if(conti_B>TB)
        return 1;
    else
        return 0;
}
