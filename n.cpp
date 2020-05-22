#include "stdio.h"

int main()
{
    int v;
    int t;
    int s;
    scanf("%d", &v);
    scanf("%d", &t);
    if(v > 0)
    {
        s = v*t;
        if(s >= 109)
            printf("%d", s - 109);
        else
            printf("%d", s);
    }
    else
    {
        s = -v*t;
        if(s >= 109)
            printf("%d", 218 - (s + 109));
        else
            printf("%d", 109 + s);
    }
    }

