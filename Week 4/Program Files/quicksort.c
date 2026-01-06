#include <stdio.h>
static int part(int*a,int l,int r)
{
    int p=a[r];
    int i=l-1;
    for(int j=l;j<r;j++)
    {
        if(a[j]<=p)
        {
            i++;
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    int t=a[i+1];
    a[i+1]=a[r];
    a[r]=t;
    return i+1;
}
static void qs_run(int*a,int l,int r)
{
    if(l<r)
    {
        int p=part(a,l,r);
        qs_run(a,l,p-1);
        qs_run(a,p+1,r);
    }
}
void qs(int*a,int n)
{
    qs_run(a,0,n-1);
}
int main(void)
{
    int a[]={157,110,147,122,111,149,151,141,123,112,117,133};
    int n=sizeof(a)/sizeof(a[0]);
    qs(a,n);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
