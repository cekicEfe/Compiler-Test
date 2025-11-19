#include <stdio.h>
#include <stdlib.h>

int main(){

  void* asd_size = malloc(0);
  if(asd_size != NULL){
    printf("size : %ld",sizeof(*asd_size));
    free(asd_size);
  }else{
    printf("No memory allocated");exit(1);
  }
  return 0;
}
