#include<stdio.h>
int main()
{
    int i, j=0, n, a[50], frame[10], no, k, avail, count=0;
    printf("  Enter the number of frames: ");
    scanf("%d",&no);
    printf("  Enter the number of pages: ");
    scanf("%d",&n);
    printf("  Enter the reference string: ");
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=0; i<no; i++)
    {
        frame[i]= -1;
    }
    printf("\n  Ref. String\t Page Frames\n");
    for(i=1; i<=n; i++)
    {
        printf("  %d\t\t",a[i]);
        avail=0;
        for(k=0; k<no; k++)
        {
            if(frame[k]==a[i])
            {
                avail=1;
            }
        }
        if (avail==0)
        {
            frame[j]=a[i];
            j=(j+1)%no;
            count++;
            for(k=0; k<no; k++)
            {
                printf("%d\t",frame[k]);
            }
        }
        printf("\n");
    }
    printf("\n  Page Fault: %d",count);
    return 0;
}
