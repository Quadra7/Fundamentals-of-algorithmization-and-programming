#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char* concat(char* pref, char* suff)
{
    char* p = strchr(pref, '\0');
    while (*suff)
    {
        *p++ = *suff++;
    }
    return p;
}

int main()
{
    int n;
    char pref[1000001] = "";
    char suff[101];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", suff);
        concat(pref, suff);
    }
    printf("%s", pref);
    return 0;
}