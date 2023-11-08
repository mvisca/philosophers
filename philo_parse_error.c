#include "philosophers.h"

int    command_args_error(void)
{
    printf("Número de argumentos incorrecto\n");
    printf("Ingrese:\n1. Número de filósofos\n2. Tiempo a morir (ms)\n");
    printf("3. Tiempo a comer (ms)\n4. Tiempo a dormir (ms)\n");
    printf("5. Array de comidas para cada filósofo (opcional)\n");
    printf("   Ejemplo: '1 3 4 ...'\n");
    return (1);
}
