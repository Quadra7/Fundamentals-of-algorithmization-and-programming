#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct Label_s 
{
    char name[16];
    int age;
} Label;

typedef struct NameStats_s 
{
    int cntTotal;
    int cntLong; // strlen(name) > 10
} NameStats;

typedef struct AgeStats_s 
{
    int cntTotal;
    int cntAdults; // age >= 18
    int cntKids; // age < 14
} AgeStats;

void calcStats(const Label* arr, int cnt, NameStats* oNames, AgeStats* oAges)
{
    printf("names: total = %d\n", oNames->cntTotal);
    for (int i = 0; i < cnt; i++)
    {
        if (strlen(arr[i].name) > 10)
        {
            oNames->cntLong++;
        }
        if (arr[i].age >= 18)
        {
            oAges->cntAdults++;
        }
        if (arr[i].age < 14)
        {
            oAges->cntKids++;
        }
    }
    printf("names: long = %d\nages: total = %d\nages: adult = %d\nages: kid = %d", oNames->cntLong, oAges->cntTotal, oAges->cntAdults, oAges->cntKids);
}

int main()
{
    int count;
    scanf("%d", &count);
    Label* arr = (Label*)malloc(count * sizeof(Label));
    for (int i = 0; i < count; i++)
    {
        scanf("%s %d let", arr[i].name, &arr[i].age);
    }
    NameStats oNames = { count, 0 };
    AgeStats oAges = { count, 0, 0 };
    calcStats(arr, count, &oNames, &oAges);
    free(arr);
    return 0;
}