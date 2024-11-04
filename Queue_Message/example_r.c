#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#define MAX_VALUE 50

struct msg_queue{
  long type_msg;
  char content [MAX_VALUE];
} message;

int main(int n, char** argv){
  key_t key;
  int msgid;
  key = ftok("progfile", 65);

  msgid = msgget(key, 0666 | IPC_CREAT);
  msgrcv(msgid, &message, sizeof(message), 1,0);
  printf("Dato recibido es : %s", message.content);

  msgctl(msgid, IPC_RMID, NULL);
  return 0;
}

