#include <stdlib.h>
#include <stdio.h>

extern void arc4random_buf(void *buf, size_t nbytes);

int main(int argc, char **argv)
{
  long unsigned int i;
  char c;
  char passwd[8];
  arc4random_buf(passwd, sizeof(passwd));
  for (i = 0; i < sizeof(passwd); i++) {
    c = (passwd[i] + 128) % 93 + '!';
    printf("%c", c);
  }
  printf("\n");
}
