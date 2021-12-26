#include<stdio.h>
int main()
{
    int n,x,y,z;
    scanf("%d",&n);
    char a[n][21];
    getchar();
    for(x=0;x<n;x++)
        gets(a[x]);
    scanf("%d",&y);
    for(x=0;x<y;x++)
    {
        scanf("%d",&z);
        puts(a[z-1]);
    }
    return 0;
}