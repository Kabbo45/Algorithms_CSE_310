#include<stdio.h>
int main()
{
    int q[20], p[50], c=0, c1, d, no, i, j, k=0, n, r, t, b[20], c2[20];
    printf("  Enter the number of frames: ");
    scanf("%d",&no);
    printf("  Enter the number of pages: ");
    scanf("%d",&n);
    printf("  Enter the reference string: ");
    for(i=1; i<n; i++)
    {
        scanf("%d",&p[i]);
    }
    q[k]=p[k];
    printf("\n\t%d\n",q[k]);
    c++;
    k++;
    for(i=1; i<n; i++)
    {
        c1=0;
        for(j=0; j<no; j++)
        {
            if(p[i]!=q[j])
            {
                c1++;
            }
        }
        if(c1 == no)
        {
            c++;
            if(k < no)
            {
                q[k]=p[i];
                k++;
                for(j=0; j<k; j++)
                {
                    printf("\t%d",q[j]);
                }
                printf("\n");
            }
            else
            {
                for(r=0; r < no; r++)
                {
                    c2[r]=0;
                    for(j=i-1; j<n; j--)
                    {
                        if(q[r]!=p[j])
                        {
                            c2[r]++;
                        }
                        else
                            break;
                    }
                }
                for(r=0; r < no; r++)
                {
                    b[r]=c2[r];
                }
                for(r=0; r < no; r++)
                {
                    for(j=r; j < no; j++)
                    {
                        if(b[r]<b[j])
                        {
                            t=b[r];
                            b[r]=b[j];
                            b[j]=t;
                        }
                    }
                }
                for(r=0; r < no; r++)
                {
                    if(c2[r]==b[0])
                    {
                        q[r]=p[i];
                    }
                    printf("\t%d",q[r]);
                }
                printf("\n");
            }
        }
    }
    printf("\n  Page Fault: %d", c);
}
