#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {
  char buffer[255];
  FILE * isUser;
  isUser = fopen("./input", "r");
  if (argc > 1) {
    if (strcmp(argv[1], "user") == 0) {
      while (fgets(buffer, 255, stdin)) {
        int a; int b; int c;
        sscanf(buffer, "%d %d %d", &a, &b, &c);
        printf("%d\n", a+b>c && a+c>b && b+c>a);
      }
    }
    else if (strcmp(argv[1], "horizontal") == 0) {
      int count = 0;
      if (isUser == NULL) {
        while (fgets(buffer, 255, stdin) && strcmp(buffer, "\n") != 0) {
          int a; int b; int c;
          sscanf(buffer, "%d %d %d", &a, &b, &c);
          if (a+b>c && a+c>b && b+c>a) {
            count++;
          }
        }
      }
      else {
        while (fgets(buffer, 255, isUser)) {
          int a; int b; int c;
          sscanf(buffer, "%d %d %d", &a, &b, &c);
          if (a+b>c && a+c>b && b+c>a) {
            count++;
          }
        }
      }
      printf("%d\n", count);
    }
    printf("end of command line\n");
  }
  else {
    printf("./a.out user -- Input three ints into command line, will return if triangle is valid\n./a.out horizontal -- Prints total number of valid triangles in stdin or file named input\n");
  }
  return 0;
}
