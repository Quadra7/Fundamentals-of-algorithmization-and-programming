#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int calcLetters(char* iStr, int* oLowerCnt, int* oUpperCnt, int* oDigitsCnt)
{
    int length = 0;
    *oLowerCnt = 0; *oUpperCnt = 0; *oDigitsCnt = 0;
    while (*iStr != '\n' && *iStr != '\0')
    {
        length++;
        if (isalpha(*iStr))
        {
            isupper(*iStr) ? *oUpperCnt += 1 : *oLowerCnt += 1;
        }
        if (isdigit(*iStr))
        {
            *oDigitsCnt += 1;
        }
        iStr++;
    }
    return length;
}
int main()
{
    FILE* input, * output;
    char iStr[102];
    int oLowerCnt, oUpperCnt, oDigitsCnt, count = 1, length;
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    while (fgets(iStr, 102, input))
    {
        printf("%s", iStr);
        length = calcLetters(iStr, &oLowerCnt, &oUpperCnt, &oDigitsCnt);
        fprintf(output, "Line %d has %d chars: %d are letters (%d lower, %d upper), %d are digits.\n", count, length, (oLowerCnt + oUpperCnt), oLowerCnt, oUpperCnt, oDigitsCnt);
        count++;
    }
    fclose(input);
    fclose(output);
    return 0;
}