#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#define MAXLI 2048

char cmd[MAXLI];
char path[MAXLI];
int pathidx;
void mbash();

int main(int argc, char** argv) {
  while (1) {
    printf("Commande: ");
    char* eof = fgets(cmd, MAXLI, stdin);
    if (eof == NULL || strcmp(cmd, "exit\n") == 0) {
      printf("\n");
      exit(0);
    } else {
      mbash(cmd);
    }
  }
  return 0;
}

void mbash() {
  printf("Execute: %s", cmd);
  system(cmd);
}
