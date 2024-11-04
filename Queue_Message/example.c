#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX_VALUE 50

struct msg_queue{
  long type_msg;
  char content [MAX_VALUE];
};

int main (int n, char** argv){
  key_t key;
  int msgid;

  key = ftok("progfile", 65);

  msgid = msgget(key, 0666 | IPC_CREAT);
  if( msgid==-1){
    printf("Error al momento de crear una cola de mensajes");
    return 1;
  }
  
  struct msg_queue max;
  max.type_msg = 1;
  printf("Write Data : ");
  fgets(max.content, MAX_VALUE , stdin);
  msgsnd(msgid, &max, sizeof(max),0);
  printf("Dato enviado es : %s \n", max.content);
  return 0;
}
