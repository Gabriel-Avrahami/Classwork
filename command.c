#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
  char buffer[255];
  while (fgets(buffer, 255, stdin)) {
    int a; int b; int c;
    sscanf(buffer, "%d %d %d", &a, &b, &c);
    printf("%d\n", a+b>c && a+c>b && b+c>a);
  }
  printf("end of command line\n");
  return 0;
}
