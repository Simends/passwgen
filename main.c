#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

extern int getopt(int argc, char * const argv[], const char *optstring);
extern char *optarg;
extern void arc4random_buf(void *buf, size_t nbytes);

int main(int argc, char **argv)
{
  int i, opt;
  int len = 8;
  char c;
  int nosym = 0;
  int nocap = 0;
  int nonum = 0;
  while ((opt = getopt(argc, argv, "l:scn")) != -1) {
    switch (opt) {
      case 'l':
        len = atoi(optarg);
        break;
      case 's':
        nosym = 1;
        break;
      case 'c':
        nocap = 1;
        break;
      case 'n':
        nonum = 1;
        break;
    }
  }
  int passwd[len];
  arc4random_buf(passwd, sizeof(passwd));
  for (i = 0; i < len; i++) {
    c = abs(passwd[i]) % ('~' - '!') + '!';
    if (nosym) {
      if (c < '0') {
        c += '0' - '!';
      }
      if (c > '9' && c < 'A') {
        c += 'A' - '9';
      }
      if (c > 'Z' && c < 'a') {
        c += 'a' - 'Z';
      }
      if (c > 'z') {
        c -= '~' - 'z';
      }
    }
    if (nonum) {
      if (c > '/' && c < ':') {
        c += 'A' - '0';
      }
    }
    if (nocap) {
      c = tolower(c);
    }
    printf("%c", c);
  }
  puts("");
  exit(0);
}
