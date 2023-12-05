#include <stdio.h>
#include <string.h>

int main() {
  char *input=malloc(100000);
  FILE* gh=fopen("input.txt", "r");
  int count=0;
  int sum=0;
  int sum_pow=0;
  while(fgets(input, 100000, gh)) {
    int isplayable=0;
    while(*(input++)!=':');
    input-=1;
    int gmmin=-1, rmmin=-1, bmmin=-1;
    int gmin=-1, rmin=-1, bmin=-1;
    while(*input) {
      int green=0, red=0, blue=0;
      for(int i=0; ; i++) {
          int tm=0;
          input+=2;
          while(*input!=' ')  tm=tm*10+(*(input++)-'0');
          input++;
          switch(*(input)) {
            case 'r': { red +=tm;  input+=3; }; break;
            case 'g': { green+=tm; input+=5; }; break;
            case 'b': { blue +=tm; input+=4; };
          }
          if(*input!=',') break;
      }
      if(gmin==-1){
          gmin=green;
          rmin=red;
          bmin=blue;
      }
      bmin = blue>bmin?blue:bmin;
      gmin = green>gmin?green:gmin;
      rmin = red>rmin?red:rmin;
      
      if(!(red<=12 && green <=13 && blue <=14)) isplayable=1;
      if(*input!=';') break;
    }
    sum_pow+=gmin*rmin*bmin;
    count++;
    if(!isplayable){ sum += count;}
  }
  printf("Sum is %d %d", sum, sum_pow);
}
