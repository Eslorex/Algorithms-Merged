#include <stdio.h>
#include <string.h>

int main() {
  char str[100];  
  int i, j;
  int max = 0;  
  char maxchar;  

  while (1) {  

    printf("Enter a string (enter 'exit' to quit): ");
    scanf("%[^\n]s", str);  


    if (strcmp(str, "exit") == 0) {
      break;  
    }


    for (i = 0; i < strlen(str); i++) {
      int count = 0;  


      for (j = i; j < strlen(str); j++) {
        if (str[i] == str[j]) {
          count++;
        }
      }

      if (count > max) {
        max = count;
        maxchar = str[i];
      }
    }


    printf("Most common character: '%c'\n", maxchar);
    printf("Number of times it appears: %d\n", max);


    getchar();
  }

  return 0;
}
