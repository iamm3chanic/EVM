#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    FILE *in,*out;
    int N,M,i,j,k,l;
    double vesk=0,vesl=0,flag=0;
    double **a,*b;

    in=fopen("input.txt","r");
    if(in==NULL)
    {
        return(-1);
    }

    out=fopen("output.txt","w");
    if(out==NULL)
    {
        return(-1);
    }

    if(fscanf(in,"%d%d",&N,&M)!=2)
    {
        return(-1);
    }

    if(N<=0 || M<=0)
    {
        return(-1);
    }

    a=(double**)malloc(N*sizeof(double*));
    if(a==NULL)
    {
        return(-1);
    }

    for(i=0;i<N;i++)
    {
        a[i]=(double*)malloc(M*sizeof(double));
        if(a[i]==NULL)
        {
            return(-1);
        }
    }

    for(i=0;i<N;i++)
    {
        for (j=0;j<M;j++)
        {
            if(fscanf(in,"%lf",&a[i][j])!=1)
            {
                return(-1);
            }
        }
    }

    for(k=0;k<N;k++)
    {
        for(l=1;l<N-k;l++)
        {
            for(j=0;j<M-1;j++)
            {
                vesk=vesk+fabs(a[k][j+1]-a[k][j]);
            }
            for(j=0;j<M-1;j++)
            {
                vesl=vesl+fabs(a[k+l][j+1]-a[k+l][j]);
            }
            if(vesl>vesk)
            {
                for(j=0;j<M;j++)
                {
                    flag=a[k][j];
                    a[k][j]=a[k+l][j];
                    a[k+l][j]=flag;
                }
            }
            vesl=0;
            vesk=0;
        }
    }

    fprintf(out,"%d %d\n",N,M);

    for(i=0;i<N;i++)
    {
        for (j=0;j<M;j++)
        {
            fprintf(out,"%lf   ",a[i][j]);
        }
        fprintf(out,"\n");
    }

    b=(double*)malloc(N*sizeof(double));
    if(b==NULL)
    {
        return(-1);
    }

    fprintf(out,"\n");

    for(i=0;i<N;i++)
    {
        b[i]=0;
        for(j=0;j<M;j++)
        {
            b[i]=b[i]+a[i][j]*a[0][j];
        }
        fprintf(out,"%lf  ",b[i]);
    }

    for(i=0;i<N;i++)
    {
        free(a[i]);
    }
    free(a);
    free(b);

    return 0;
}
