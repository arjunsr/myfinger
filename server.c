/*
  Author : Arjun S R <arjun1296@gmail.com>
  Date : Fri Jun  3 23:59:46 IST 2011
  Purpose : s8 Lab
*/
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include "myfinger.h"


myfinger_out*
myfinger_1_svc(myfinger_in *inp, struct svc_req *rqstp)
{
 
  static myfinger_out out;
  char *command=NULL;
  size_t byte_count=0;
  int i=0;
  printf("[SERVER]:Looking for %s ",inp->user_name);
  pid_t fin;
  /*
    int pipefd[2];
    if (pipe(pipefd) == -1) {
    printf("pipe error");
    exit(1);
    }
    
    fin=vfork();
    switch(fin)
    {
    case 0:
    //Child
    printf("In child:%ld",(long)getpid);
    }
  */
  asprintf(&command,"finger %s",inp->user_name);
  FILE *finger_buf;
  if ( (finger_buf=popen(command,"r"))==NULL) {
    printf("[SERVER]: Error finger binary failed to execute,%s",strerror(errno));
    free(command);
    exit(1);
  }

  while ( !feof(finger_buf) && i<4096) {
    out.output[i++]=fgetc(finger_buf);
  }
  out.output[i]='\0';
  
  if (i>=4096 && !feof(finger_buf)) {
    printf("output structure space not enough\n");
    
  }

  free(command);
  pclose(finger_buf);
  return &out;
}
