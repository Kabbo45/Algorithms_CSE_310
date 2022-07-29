#include<stdio.h>
int main()
{
    int p_no,b_no,b_size[10],p_size[10],b_check[10],track[10],i,j,temp;
    printf("Enter the number of block : ");
    scanf("%d",&b_no);
    for(i=0; i<b_no; i++)
    {
        printf("\nEnter the size of Block-%d : ",i+1);
        scanf("%d",&b_size[i]);
    }
    printf("\nEnter the number of process : ");
    scanf("%d",&p_no);
    for(i=0; i<p_no; i++)
    {
        printf("\nEnter the size of Process-%d : ",i+1);
        scanf("%d",&p_size[i]);
    }
    for(i=0; i<b_no; i++)
    {
        b_check[i]=-1;
    }
    for(i=0; i<p_no; i++)
    {
        track[i]=-1;
    }
    for(i=0; i<p_no; i++)
    {
        for(j=0; j<b_no; j++)
        {
            if(b_size[j] < b_size[j+1])
            {
                temp = b_size[j];
                b_size[j]=b_size[j+1];
                b_size[j+1]=temp;
            }
        }
    }
    for(i=0; i<p_no; i++)
    {
        for(j=0; j<b_no; j++)
        {
            if(b_check[j]==-1 && p_size[i]<=b_size[j])
            {
                b_check[j]=i;
                track[i]=j;
                break;
            }
        }
    }

    printf("\nProcess No\tProcess Size\tBlock No\tBlock Size\n");
    for(i=0; i<p_no; i++)
    {
        printf("Process-%d\t%d",i+1,p_size[i]);
        if(track[i]==-1)
        {
            printf("\t\tNot Allocated!");
        }
        else
        {
            printf("\t\tBlock-%d\t\t%d",track[i]+1,b_size[track[i]]);
        }
        printf("\n");
    }
}
