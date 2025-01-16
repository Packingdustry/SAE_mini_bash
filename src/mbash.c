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
char* getChemin();

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
  if (strstr(cmd, "cd") != NULL) {
    char* chemin = getChemin();
    int err = chdir(chemin);
    if (err != 0) {
      printf("cd: %s: Aucun fichier ou dossier de ce nom\n", chemin);
    }
    return;
  }
  printf("Execute: %s", cmd);
  system(cmd);
}

char* getChemin() {
  char* chemin = malloc(MAXLI);
  strcpy(chemin, &cmd[3]);
  chemin[strlen(chemin)-1] = 0;
  if (strstr(chemin, "~") != NULL) {
    chemin = strcat(getenv("HOME"), &chemin[1]);
  }
  return chemin;
}
