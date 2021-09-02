#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "List.h"

int main(){

    List * ListaUsuario = createList();                                      
    int menu = 1;
    while(menu!= 0){
        printf("===============================================================\n");
        printf("|   1.- Importar Canciones                                    |\n");
        printf("|   2.- Agregar Cancion                                       |\n");
        printf("|   3.- Eliminar Cancion                                      |\n");
        printf("|   4.- Buscar Cancion por nombre                             |\n");
        printf("|   5.- Buscar Cancion por aritsta                            |\n");
        printf("|   6.- Buscar cancion por género                             |\n");
        printf("|   7.- Eliminar cancion                                      |\n");
        printf("|   8.- Mostrar nombres de las listas de reproducción         |\n");
        printf("|   9.- Mostrar una lista de reproducción                     |\n");
        printf("|   9.- Mostrar todas las canciones                           |\n");
        printf("|   10.- Exportar canciones CSV                               |\n");
        printf("|   0.- Salir                                                 |\n");
        printf("===============================================================\n");
        printf(" Ingrese un numero: ");
        scanf(" %i", menu);
        fflush(stdin);
        switch (menu)
        {
        case 1:
            importarArchivo(ListaUsuario);
            printf (" Archivo leido correctamente\n");
            break;

        case 2:
            agregarCancion(ListaUsuario);
            printf (" Cancion agregada correctamente\n");
        default:
            break;
        } 
    }
    
    return 0;
}