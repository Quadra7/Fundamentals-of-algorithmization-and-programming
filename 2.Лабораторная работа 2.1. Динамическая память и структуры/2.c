#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int readTime(char* iStr, int* oHours, int* oMinutes, int* oSeconds)
{
    int h = 0, m = 0, s = 0;
    int sscanf_result;
    int result;

    sscanf_result = sscanf(iStr, "%d:%d:%d", &h, &m, &s);
    if (sscanf_result == 3)
    {
        if ((h >= 0 && h <= 23) && (m >= 0 && m <= 59) && (s >= 0 && s <= 59))
        {
            result = 1;
            *oHours = h;
            *oMinutes = m;
            *oSeconds = s;
        }
        else
        {
            result = 0;
            *oHours = -1;
            *oMinutes = -1;
            *oSeconds = -1;
        }
    }
    else if (sscanf_result == 2)
    {
        sscanf_result = sscanf(iStr, "%d:%d", &h, &m);
        if ((h >= 0 && h <= 23) && (m >= 0 && m <= 59))
        {
            result = 1;
            *oHours = h;
            *oMinutes = m;
            *oSeconds = 0;
        }
        else
        {
            result = 0;
            *oHours = -1;
            *oMinutes = -1;
            *oSeconds = -1;
        }
    }
    else
    {
        result = 0;
        *oHours = -1;
        *oMinutes = -1;
        *oSeconds = -1;
    }
    return result;
}
int main()
{
    char iStr[16];
    int oHours, oMinutes, oSeconds;
    scanf("%s", iStr);
    int result = readTime(iStr, &oHours, &oMinutes, &oSeconds);
    printf("%d %d %d %d\n%d %d %d\n%d %d", result, oHours, oMinutes, oSeconds, result, oHours, oMinutes, result, oHours);
    return 0;
}