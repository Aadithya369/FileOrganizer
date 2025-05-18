#include <stdlib.h>
#include <stdio.h>
char *smash (const char *const words[/* count */], size_t count)
{
  for(int i=0;i<=count;i++){
    if(i == count){
          printf("%s",(words[count]));
    }
    else{
    printf("%s ",(words[count]));
    }
  }
	return calloc(1, 1);
}
