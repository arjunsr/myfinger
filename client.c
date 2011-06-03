/*
  Author : Arjun S R <arjun1296@gmail.com>
  Date : Fri Jun  3 23:59:46 IST 2011
  Purpose : s8 Lab
*/
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "myfinger.h"

int
main(int argc, char *argv[])
{
  
  CLIENT *client_handle;
  myfinger_in input;
  myfinger_out *output;

  if (argc !=3) {
    printf("%s <username> <host>\n",argv[0]);
    exit(1);
  }
  client_handle=clnt_create(argv[2], MYFINGER_PROGRAM,MYFINGER_VERSION, "tcp");

  if ( strlen(argv[1]) < 4096 )
    strncpy(input.user_name,argv[1],strlen(argv[1]));

  if ( (output=myfinger_1(&input,client_handle))== NULL ) {
    printf("%s",clnt_sperror(client_handle,argv[1]));
    exit(1);
  }
  printf("[CLIENT]: Result-> %s",output->output);
  return 0;

}
