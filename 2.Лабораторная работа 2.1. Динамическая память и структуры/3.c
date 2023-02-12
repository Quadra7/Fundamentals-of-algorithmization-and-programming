#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef struct DateTime_s 
{
    int year, month, day;
    int hours, minutes, seconds;
} DateTime;

DateTime min(const DateTime* arr, int cnt)
{
    DateTime minDate = { 5001,13,32,24,61,61 };
    for (int i = 0; i < cnt; i++)
    {
        if (minDate.year > arr[i].year)
        {
            minDate = arr[i];
            continue;
        }
        if ((minDate.year == arr[i].year) && (minDate.month > arr[i].month))
        {
            minDate = arr[i];
            continue;
        }
        if ((minDate.year == arr[i].year) && (minDate.month == arr[i].month) && (minDate.day > arr[i].day))
        {
            minDate = arr[i];
            continue;
        }
        if ((minDate.year == arr[i].year) && (minDate.month == arr[i].month) && (minDate.day == arr[i].day) && (minDate.hours > arr[i].hours))
        {
            minDate = arr[i];
            continue;
        }
        if ((minDate.year == arr[i].year) && (minDate.month == arr[i].month) && (minDate.day == arr[i].day) && (minDate.hours == arr[i].hours) && (minDate.minutes > arr[i].minutes))
        {
            minDate = arr[i];
            continue;
        }
        if ((minDate.year == arr[i].year) && (minDate.month == arr[i].month) && (minDate.day == arr[i].day) && (minDate.hours == arr[i].hours) && (minDate.minutes == arr[i].minutes) && (minDate.seconds > arr[i].seconds))
        {
            minDate = arr[i];
            continue;
        }
    }
    return minDate;
}

int main()
{
    int cnt;
    scanf("%d", &cnt);
    DateTime* arr = (DateTime*)malloc(cnt * sizeof(DateTime));
    for (int i = 0; i < cnt; i++)
    {
        scanf("%d %d %d %d %d %d", &arr[i].year, &arr[i].month, &arr[i].day, &arr[i].hours, &arr[i].minutes, &arr[i].seconds);
    }
    DateTime result = min(arr, cnt);
    printf("%d %d %d %d %d %d", result.year, result.month, result.day, result.hours, result.minutes, result.seconds);
    free(arr);
    return 0;
}