#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 2
#define MAX_NAME_LENGTH 50

struct appointment {
  char name[MAX_NAME_LENGTH];
  char surname[MAX_NAME_LENGTH];
  time_t date;
};

struct appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void make_appointment() {
  if (num_appointments == MAX_APPOINTMENTS) {
    printf("Error: Cannot make any more appointments, maximum number of appointments reached.\n");
    return;
  }

  printf("Enter name: ");
  scanf("%s", appointments[num_appointments].name);
  printf("Enter surname: ");
  scanf("%s", appointments[num_appointments].surname);
  printf("Enter appointment date and time (YYYY-MM-DD HH:MM): ");

  int year, month, day, hour, minute;
  scanf("%d-%d-%d %d:%d", &year, &month, &day, &hour, &minute);

  struct tm tm = {0};
  tm.tm_year = year - 1900;
  tm.tm_mon = month - 1;
  tm.tm_mday = day;
  tm.tm_hour = hour;
  tm.tm_min = minute;
  appointments[num_appointments].date = mktime(&tm);

  // Check if there are already 5 appointments on the same date
  int count = 0;
  for (int i = 0; i < num_appointments; i++) {
    struct tm *tm2 = localtime(&appointments[i].date);
    if (tm2->tm_year == tm.tm_year && tm2->tm_mon == tm.tm_mon && tm2->tm_mday == tm.tm_mday) {
      count++;
    }
  }
  if (count >= 5) {
    printf("Error: Cannot make more than 5 appointments on the same day.\n");
    return;
  }

  // Check if there is already an appointment at the same date and time
  for (int i = 0; i < num_appointments; i++) {
    struct tm *tm2 = localtime(&appointments[i].date);
    if (tm2->tm_year == tm.tm_year && tm2->tm_mon == tm.tm_mon && tm2->tm_mday == tm.tm_mday && tm2->tm_hour == tm.tm_hour && tm2->tm_min == tm.tm_min) {
      printf("Error: An appointment already exists at this date and time.\n");
      return;
    }
  }

  num_appointments++;
}



void display_appointments() {
  for (int i = 0; i < num_appointments; i++) {
    struct tm *tm = localtime(&appointments[i].date);
    char date_string[20];
    strftime(date_string, sizeof(date_string), "%Y-%m-%d", tm);
    printf("%s %s: %s\n", appointments[i].name, appointments[i].surname, date_string);
  }
}

int main() {
  while (1) {
    printf("\nMenu:\n");
    printf("1. Make an appointment\n");
    printf("2. Display all appointments\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
      make_appointment();
    } else if (choice == 2) {
      display_appointments();
    } else {
      printf("Invalid choice.\n");
    }
  }

  return 0;
}

