#include<stdio.h>
#include "funciones_tareas.h"
#include<string.h>
int main(){
    struct tarea tareas[20], *buscador;
    int numero_tarea=0,modificador,opcion,i;
    char titulo[20];
    menu();
    scanf("%d",&opcion);
    while(opcion!=6){
        switch(opcion){
        case 1:
            printf("digite su tarea:\n\n");
            agregar(numero_tarea,&tareas);
            numero_tarea++;
            menu();
            break;
        case 2:
            printf("\ndigite el numero de tarea que desea modificar su estado:\n");
            scanf("%d",&modificador);
            cambio_estado(&tareas,modificador);
            menu();
            break;
        case 3:
            tareas_pendientes(&tareas,numero_tarea);
            menu();
            break;
        case 4:
            printf("la lista de tareas es:\n\n");
            lista_tareas(&tareas,numero_tarea);
            menu();
            break;
        case 5:
            printf("digite el titulo de la tarea que desea buscar:\n");
            scanf("%s", titulo);
            buscador=busqueda(&tareas,numero_tarea,&titulo);
            if (buscador!=NULL){
                printf("su tarea (%s) esta en la lista:\n",buscador->titulo);
                if(buscador->estado==1){
                    printf("su tarea esta completada\n\n");
                }else{
                    printf("su tarea esta pendiente\n\n");
                }
            }
            menu();
            break;
        case 6:
            break;
        }
        printf("digite otra opcion:\n");
        scanf("%d",&opcion);

    }
     printf("¡Gracias por usar el gestor de tareas!\n");
     system("pause");
    return 0;
}
