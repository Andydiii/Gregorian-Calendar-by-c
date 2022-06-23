# Gregorian-Calendar-by-c

This program is for printing Gregorian Calendar by given year and month, which was established in 1582 and is the calendar used by most of the world (see wikipedia for more information). It is the Gregorian calendar, not the British Julian calendar (where 11 days were skipped over).

For convenience, we only consider dates prior to 1589. January 1st, 1589 was a Sunday and that will make your calculations a tiny bit more straightforward. Any dates prior to January 1st, 1589 will be considered invalid.

Similarly, we will not consider dates after 2999. Any dates after December 31st, 2999 will be considered invalid.

The number for January will be 1 and December will be 12.

We will assign Sunday to be 0, Monday to be 1, and Saturday to be 6. This will also make your calculations a tiny bit more straightforward.

- valid_date(year, month, day) determines if the provided date is a valid date, according to the Gregorian Calendar.  
This function checks to see if the year is a leap year, where February 29 is a valid date (otherwise, February 29 is not a valid date).  
A year divisible by 400 is a leap year.  
Otherwise, a year divisible by 100 is not a leap year.  
Otherwise, a year divisible by 4 is a leap year.  
Otherwise, the year is not a leap year.  

- day_of_the_week(year, month, day) finds the "day of the week" for the given date.  
To determine this, must start in 1589 and then loop month-by-month adding the number of days in each month until you arrive at the month in the date.  
Sunday is 0. This assignment is due on day_of_the_week(2022, 5, 27) => 5 (Friday).  
The function requires that the date is valid.  

- print_calendar(year, month) prints a "pretty" calendar for the given month.  
For example, print_calendar(2021, 1) prints the following output:  
====January 2021====   
Su Mo Tu We Th Fr Sa  
                1  2  
 3  4  5  6  7  8  9  
10 11 12 13 14 15 16  
17 18 19 20 21 22 23  
24 25 26 27 28 29 30  
31  
The function print_header to print the header (i.e., the first two lines). The header starts with Sunday (Su).  
The task  of this function is to properly align the dates in the calendar.  
In the above example, there are no additional spaces after the 31 (or 2/9/16/23/30).  
Every line printed ends with a newline (including the last line). You must not print any additional newlines.  
The function requires that the year and the month must both be valid.  
