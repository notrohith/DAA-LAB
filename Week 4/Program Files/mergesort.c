#include <stdio.h>
static void ms_merge(int*a,int*tmp,int l,int m,int r)
{
    int i=l;
    int j=m;
    int k=l;
    while(i<m&&j<r)
    {
        if(a[i]<=a[j])
            tmp[k++]=a[i++];
        else
            tmp[k++]=a[j++];
    }
    while(i<m)
        tmp[k++]=a[i++];
    while(j<r)
        tmp[k++]=a[j++];
    for(i=l;i<r;i++)
        a[i]=tmp[i];
}
static void ms_run(int*a,int*tmp,int n,int sz)
{
    if(sz>=n)
        return;
    for(int s=0;s<n;s+=2*sz)
    {
        int m=s+sz;
        int e=s+2*sz;
        if(m>n)
            m=n;
        if(e>n)
            e=n;
        if(m<e)
            ms_merge(a,tmp,s,m,e);
    }
    ms_run(a,tmp,n,sz*2);
}
void ms(int*a,int n,int buf[])
{
    ms_run(a,buf,n,1);
}
int main(void)
{
    int a[]={157,110,147,122,111,149,151,141,123,112,117,133};
    int n=sizeof(a)/sizeof(a[0]);
    int buf[n];
    ms(a,n,buf);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}

