#include <stdio.h>
#include <assert.h>

// print_header(year, month) prints the calendar "header" 
//   for the given year/month
// notes: if month is invalid, no month line is printed
//        header is aligned for 4-digit years
// effects: produces output
void print_header(const int year, const int month) {
  if (month == 1) {
    printf("====January %d====\n", year);
  } else if (month == 2) {
    printf("===February %d====\n", year);
  } else if (month == 3) {
    printf("=====March %d=====\n", year);
  } else if (month == 4) {
    printf("=====April %d=====\n", year);
  } else if (month == 5) {
    printf("======May %d======\n", year);
  } else if (month == 6) {
    printf("=====June %d======\n", year);
  } else if (month == 7) {
    printf("=====July %d======\n", year);
  }else if (month == 8) {
    printf("====August %d=====\n", year);
  } else if (month == 9) {
    printf("===September %d===\n", year);
  } else if (month == 10) {
    printf("====October %d====\n", year);
  } else if (month == 11) {
    printf("===November %d====\n", year);
  } else if (month == 12) {
    printf("===December %d====\n", year);
  }
  printf("Su Mo Tu We Th Fr Sa\n");
}

// you may use these constants in your code if you wish
// it is not a requirement, but it is strongly recommended
// you may not change their values

const int SUNDAY = 0;
const int base_year = 1589;
const int base_year_jan_1 = SUNDAY;
const int max_year = 2999;
/////////////////////////////////////////////////////////////////////////////

bool valid_date(int year, int month, int day) {
  if ((year < 1589) || (year > 2999)) {
    return false;
  }
  if ((month > 12) || (month < 1)) {
    return false;
  }
  if ((day > 31) || (day < 1)) {
    return false;
  }
  else if (month == 2) {
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
      return (1 <= day) && (day <= 29);
    else {
      return (1 <= day) && (day <= 28);
    }
  }
  else if ((month == 1) || (month == 3) 
           || (month == 5) || (month == 7) 
           || (month == 8) ||(month == 10) || (month == 12)) {
    return (1 <= day) && (day <= 31);
  }
  else {
    return (1 <= day) && (day <= 30);
  }
}


int day_of_the_week(int year, int month, int day) {
  assert(valid_date(year, month, day) == true);
  int period = 0;
  for (int curr_yr = 1589; curr_yr < year; curr_yr += 1) {
    for (int curr_mon = 1; curr_mon <= 12; curr_mon += 1) {
      if (curr_mon == 2) {
        if ((curr_yr % 400 == 0) 
            || ((curr_yr % 4 == 0) && (curr_yr % 100 != 0))) {
          period += 29;
        }
        else {
          period += 28;
        }
      }
      else if ((curr_mon == 4) || (curr_mon == 6) 
               || (curr_mon == 9) || (curr_mon == 11)) {
        period += 30;
      }
      else {
        period += 31;
      }
    }
  }
  for (int curr_yr_mon = 1; curr_yr_mon < month; curr_yr_mon += 1) {
    if (curr_yr_mon == 2) {
      if ((year % 400 == 0) || ((year % 4 == 0) 
                                       && (year % 100 != 0))) {
        period += 29; // leap year
      }
      else { // normal year
        period += 28;
      }
    }
    else if ((curr_yr_mon == 4) || (curr_yr_mon == 6) 
             || (curr_yr_mon == 9) || (curr_yr_mon == 11)) {
      period += 30;
    }
    else {
      period += 31;
    }
  }
  return (period + day - 1) % 7;
}

void print_calendar(int year, int month) {
  assert(year >= 1589 && year <= 2999 
         && month <= 12 && month >= 1);
  print_header(year, month);
  int fir_day_week = day_of_the_week(year, month, 1);
  int curr_day_week = 0;
  while(curr_day_week < fir_day_week) {
    printf("   ");
    curr_day_week += 1;
  }
  for(int curr_day = 1;
      valid_date(year, month, curr_day) == true;
      curr_day += 1) {
    if ((valid_date(year, month, curr_day + 1) == false)
        || (curr_day_week % 7 == 6)) {
      printf("%2d\n", curr_day);
    }
    else {
      printf("%2d ", curr_day);
    }
    curr_day_week += 1;
  }
}

void assertion_tests(void) {
  // Due date is a valid date and a Thursday
  assert(valid_date(2021, 1, 28));
  assert(day_of_the_week(2021, 1, 28) == 4);
  // Add your own assertion-based tests below 
  
  assert(valid_date(2022, 4, 1) == true);
  assert(valid_date(1, 4, 1) == false);
  assert(valid_date(1589, 1, 1) == true);
  assert(valid_date(1589, 1, 1) == true);
  assert(valid_date(2999, 1, 1) == true);
  assert(valid_date(3000, 12, 1) == false);
  assert(valid_date(2999, 1, 1) == true);
  assert(valid_date(13213, 1, 1) == false);
  assert(valid_date(2999, 1, 1) == true);
  assert(valid_date(2999, 321, 1312) == false);
  assert(valid_date(2, -3, -3) == false);

  assert(day_of_the_week(1589, 1, 1) == 0);
  assert(day_of_the_week(1590, 1, 1) == 1);
  assert(day_of_the_week(1591, 1, 1) == 2);
  assert(day_of_the_week(1592, 1, 1) == 3);
  assert(day_of_the_week(1593, 1, 1) == 5);
  assert(day_of_the_week(1594, 1, 1) == 6);
  assert(day_of_the_week(1600, 1, 1) == 6);
  assert(day_of_the_week(1700, 1, 1) == 5);
  assert(day_of_the_week(1701, 1, 1) == 6);
  assert(day_of_the_week(1721, 1, 1) == 3);
  assert(day_of_the_week(2022, 1, 1) == 6);
  assert(day_of_the_week(2999, 1, 1) == 2);
  assert(day_of_the_week(1999, 2, 1) == 1);
  assert(day_of_the_week(1599, 3, 1) == 1);
  assert(day_of_the_week(2999, 6, 12) == 3);
  assert(day_of_the_week(2999, 12, 1) == 0);
  assert(day_of_the_week(2999, 2, 1) == 5);
  assert(day_of_the_week(2999, 1, 1) == 2);
  assert(day_of_the_week(1777, 4, 25) == 5);
  assert(day_of_the_week(2024, 4, 29) == 1);
  assert(day_of_the_week(1884, 3, 1) == 6);
  assert(day_of_the_week(1884, 2, 29) == 5);
  assert(day_of_the_week(1884, 2, 29) == 5);
  assert(day_of_the_week(2020, 2, 28) == 5);
  assert(day_of_the_week(2020, 5, 6) == 3);
  assert(day_of_the_week(2024, 3, 1) == 5);
  assert(day_of_the_week(2024, 3, 3) == 0);
  assert(day_of_the_week(2024, 12, 31) == 2);
  assert(day_of_the_week(2024, 1, 1) == 1);
  assert(day_of_the_week(2002, 8, 13) == 2);
  assert(day_of_the_week(2002, 9, 26) == 4);
  assert(day_of_the_week(2024, 9, 4) == 3);
  assert(day_of_the_week(2024, 7, 1) == 1);
  assert(day_of_the_week(2024, 11, 18) == 1);
  assert(day_of_the_week(2024, 10, 18) == 5);
}

///////////////////////////////////////////////////////
// You do not need to modify the rest of the program //
///////////////////////////////////////////////////////

int main(void) {
  assertion_tests();
  while (1) {
    int year;
    int month;
    scanf("%d", &year);
    if (scanf("%d", &month) == 0) {
      break;
    }
    print_calendar(year, month);
  }
}
