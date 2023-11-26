#ifndef FUNCIONES_TAREAS_H_INCLUDED
#define FUNCIONES_TAREAS_H_INCLUDED
struct tarea{
    char materia[50];
    char titulo[50];
    int estado;
};
//menu de opciones
void menu(){
    printf("MENU\nDigite la opcion deseada\n1._agregar una tarea\n");
    printf("2._marcar atara como completada\n");
    printf("3._listar todas las tareas pendientes\n");
    printf("4._listar todas las tareas\n");
    printf("5._buscar\n");
    printf("6._salir del programa\n");
}
//Aqui se esta agregando una tarea nueva
struct tarea * agregar(int indice, struct tarea * tareas){
    printf("escriba la materia a la cual corresponde su tarea:\n");
    scanf("%s",tareas[indice].materia);
    printf("escriba el titulo de la tarea %d:\n",indice+1);
    scanf("%s",tareas[indice].titulo);
    tareas[indice].estado=0;
    printf("tarea agregada con exito\n\n");
    return tareas;
}
//cambiamos el estado de pendiente a completado y marca si ya estaba completada
int cambio_estado(struct tarea * tareas, int num_tarea){
    if(tareas[num_tarea-1].estado==0){
        tareas[num_tarea-1].estado=1;
        printf("su tarea a sido completada\n\n");
    }else{
        printf("su tarea ya estaba completada\n\n");
    }
    return tareas->estado;
}
//esta funcion muestra el listado de todas las tareas
void lista_tareas(struct tarea * tareas,int indice){
    for(int i=0;i<indice;i++){
        printf("la tarea %s ",tareas[i].titulo);
        printf("de la materia %s ",tareas[i].materia);
        if(tareas[i].estado==1){
            printf("esta completada\n\n");
        }else if(tareas[i].estado==0){
            printf("esta pendiente\n\n");
        }
    }
}
//esta funcion imprime cuales son las tareas pendientes
void tareas_pendientes(struct tarea * tareas, int indice){
    printf("tareas pendientes:\n\n");
    for(int i=0;i<indice;i++){
        if(tareas[i].estado==0){
            printf("la tarea %s de la materia %s esta pendiente\n\n",tareas[i].titulo,tareas[i].materia);
        }
    }
}
//funcion recursiva para la busqueda de una tarea por titulo
struct tarea * busqueda(struct tarea * tareas, int indice ,char * titulo){
    if (indice==0) {
        printf("su tarea no esta en la lista.\nagregue la tarea primero\n");
        return NULL;
    }else if(strcmp(tareas[indice-1].titulo, titulo) == 0){
        return &tareas[indice-1];
    }else{
        busqueda(tareas, indice-1, titulo);
    }
}
#endif // FUNCIONES_TAREAS_H_INCLUDED
