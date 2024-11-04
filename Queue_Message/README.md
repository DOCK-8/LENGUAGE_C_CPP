# DOCUMENTACION
## QUEUE MESSAGE
Estas son lugares donde se globaliza mensajes
para la comunicacion o transmicion de informacion
tomando en cuenta o analogia, la idea de un cliente
como un proceso A,cocinero como un proceso B y la
preparacion como una necesidad o dependencia de un
entre procesos;
Entonces si el proceso A necesita que le preparen
un platillo en especifico, el proceso B lo hara.

## INICIALIZACION
Si conocemos ¿Qué es? entonces ahora es necesario saber como usarlo
### FUNCIONES
**msgget()**
Esta funcion permite abrir o crear una nueva cola de mensajes
**msgsnd()**
Esta nos permite agregar un mensaje al final de la cola
especificando su tamaño del mensaje 
**msgrcv()**
Este nos permite obtener mensajes de la cola, aclaracion como es una cola
este sera: "Extraigo el primero que entro"
## MESSAGE
**struct**
```
#define MAX_VALUE = 50
struct msg_queue{
  long type_message;
  char content [MAX_VALUE];
};
```
## GLOSARY
*ftok()* : genera una unique key  
*msgget()* : genera o accede a una cola de mensajes  
*msgsnd()* : agrega un nuevo mensaje a la cola  
*msgrcv()* : accede a un mensaje de la cola one-get one-out  
*msgctl()* : en lo general es usado para eliminar la cola de mensajes
## EXAMPLE
En este ejemplo lo que vamos hacer es una comunicacion entre procesos
donde uno envia un mensaje que puede ser leido por otro, en este caso 
se hace uso de un array de caracteres, para poder tener una variable 
global entre procesos.
### EMISOR
```
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
```
### RECEPTOR
```
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
```
