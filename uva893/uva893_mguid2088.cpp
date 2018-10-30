#include <cstdio>

static int dayInMonths [] =   {0, 31, 28, 31,  30,  31,  30,  31,  31,  30,  31,  30,  31};
//int normalizeDays [] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

inline bool isLeapYear(int year) {
   return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

int countDays(int day, int month, int year) {
    int counter = 0;
    for ( int i = 1; i < year; i++ ) {
        counter += (isLeapYear(i) ? 366 : 365);
    }
    for ( int i = 1; i < month; i++ ) {
        counter += dayInMonths [i];
    }
    counter += day;
    if (month > 2 && isLeapYear(year)) counter++;
    return counter;
}

int main () {
    int futureDays, month, day, year;
    while (scanf ("%d %d %d %d", &futureDays, &day, &month, &year) && year) {
        dayInMonths [2] = 28;
        int totalNumberOfDays = countDays(day, month, year);
        totalNumberOfDays += futureDays;
        printf("%d\n", totalNumberOfDays);
        int year = 1;
        int month = 1;
        while(totalNumberOfDays >= 365) {
           int year_size = isLeapYear(year) ? 366 : 365;
           totalNumberOfDays -= year_size;
           if (totalNumberOfDays <= 0) {
              totalNumberOfDays += year_size;
              break;
           }
           year++;
        }
        if (totalNumberOfDays) {
           if (isLeapYear(year)) dayInMonths [2]++;
           while (totalNumberOfDays > dayInMonths [month]) {
             totalNumberOfDays -= dayInMonths [month];
             month++;
           }
        }
        printf ("%d %d %d\n", totalNumberOfDays, month, year);
    }
    return 0;
}

