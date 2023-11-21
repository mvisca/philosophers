#include "philosophers.h"

int    command_args_error(void)
{
    printf("Número de argumentos incorrecto\n");
    printf("Ingrese:\n1. Número de filósofos\n2. Tiempo a morir (ms)\n");
    printf("3. Tiempo a comer (ms)\n4. Tiempo a dormir (ms)\n");
    printf("5. Número de comidas para terminar (opcional)\n");
    return (1);
}
