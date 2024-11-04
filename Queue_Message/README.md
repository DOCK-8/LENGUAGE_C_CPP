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
```
[message] : contenor
```
**msgrcv()**
Este nos permite obtener mensajes de la cola, aclaracion como es una cola
este sera: "Extraigo el primero que entro"
```
```
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
