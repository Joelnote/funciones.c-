#include <stdio.h>

#define MAX 5

int codigo[MAX];
char nombre[MAX][50];
float valor[MAX];
int ocupado[MAX]; // 0 = libre, 1 = ocupado


// 1. VALIDAR POSICION DENTRO DE RANGO (0 a MAX-1)
void validarPosicion() {
    int pos;
    do {
        printf("Ingrese posicion (0 - %d): ", MAX - 1);
        scanf("%d", &pos);

        if (pos < 0 || pos >= MAX) {
            printf("Error: posicion fuera de rango.\n");
        }
    } while (pos < 0 || pos >= MAX);
}


// 2. VALIDAR QUE EL ESPACIO ESTE LIBRE ANTES DE GUARDAR
void validarEspacioLibre() {
    int pos;
    do {
        printf("Ingrese posicion (0 - %d): ", MAX - 1);
        scanf("%d", &pos);

        if (pos < 0 || pos >= MAX) {
            printf("Error: posicion fuera de rango.\n");
        } else if (ocupado[pos] == 1) {
            printf("Error: ese espacio ya esta ocupado.\n");
        }
    } while (pos < 0 || pos >= MAX || ocupado[pos] == 1);
}


// 3. VALIDAR QUE EL ESPACIO ESTE OCUPADO ANTES DE ELIMINAR O SACAR
void validarEspacioOcupado() {
    int pos;
    do {
        printf("Ingrese posicion (0 - %d): ", MAX - 1);
        scanf("%d", &pos);

        if (pos < 0 || pos >= MAX) {
            printf("Error: posicion fuera de rango.\n");
        } else if (ocupado[pos] == 0) {
            printf("Error: ese espacio esta vacio.\n");
        }
    } while (pos < 0 || pos >= MAX || ocupado[pos] == 0);
}


// 4. VALIDAR QUE EL NUMERO SEA POSITIVO (Precios, cantidades, tiempos)
void validarPositivo() {
    float num;
    do {
        printf("Ingrese valor (mayor a 0): ");
        scanf("%f", &num);

        if (num <= 0) {
            printf("Error: el valor debe ser mayor a 0.\n");
        }
    } while (num <= 0);
}


// 5. VALIDAR RANGO DE NOTAS O PORCENTAJES (Ej: 0 a 10)
void validarNota() {
    float nota;
    do {
        printf("Ingrese nota (0 - 10): ");
        scanf("%f", &nota);

        if (nota < 0 || nota > 10) {
            printf("Error: la nota debe estar entre 0 y 10.\n");
        }
    } while (nota < 0 || nota > 10);
}


// 6. VALIDAR HORA Y MINUTOS (Formato 24h: hora 0-23, min 0-59)
void validarHoraMinutos() {
    int hora, min;
    do {
        printf("Ingrese hora (0 - 23): ");
        scanf("%d", &hora);
        printf("Ingrese minutos (0 - 59): ");
        scanf("%d", &min);

        if (hora < 0 || hora > 23 || min < 0 || min > 59) {
            printf("Error: hora o minutos invalidos.\n");
        }
    } while (hora < 0 || hora > 23 || min < 0 || min > 59);
}


// 7. VALIDAR QUE LA HORA DE SALIDA SEA MAYOR A LA DE INGRESO (Para parqueadero)
void validarHoraSalida() {
    int hIn = 8, mIn = 30; // Ejemplo de hora ingreso
    int hOut, mOut, totIn, totOut;

    do {
        printf("Hora salida (0 - 23): ");
        scanf("%d", &hOut);
        printf("Minuto salida (0 - 59): ");
        scanf("%d", &mOut);

        totIn = (hIn * 60) + mIn;
        totOut = (hOut * 60) + mOut;

        if (hOut < 0 || hOut > 23 || mOut < 0 || mOut > 59) {
            printf("Error: formato de hora invalido.\n");
        } else if (totOut <= totIn) {
            printf("Error: la hora de salida debe ser mayor a la de ingreso.\n");
        }
    } while (hOut < 0 || hOut > 23 || mOut < 0 || mOut > 59 || totOut <= totIn);
}


// 8. VALIDAR QUE NO SE REPITA UN CODIGO / ID (Sin duplicados)
void validarCodigoUnico() {
    int nuevoCod, repetido;

    do {
        repetido = 0;
        printf("Ingrese codigo unico: ");
        scanf("%d", &nuevoCod);

        if (nuevoCod <= 0) {
            printf("Error: el codigo debe ser positivo.\n");
            repetido = 1;
        } else {
            for (int i = 0; i < MAX; i++) {
                if (ocupado[i] == 1 && codigo[i] == nuevoCod) {
                    printf("Error: ese codigo ya existe.\n");
                    repetido = 1;
                    break;
                }
            }
        }
    } while (repetido == 1);
}


// 9. VALIDAR QUE HAYA AL MENOS UN REGISTRO ANTES DE MOSTRAR O CALCULAR
void validarNoVacio() {
    int hayDatos = 0;

    for (int i = 0; i < MAX; i++) {
        if (ocupado[i] == 1) {
            hayDatos = 1;
            break;
        }
    }

    if (hayDatos == 0) {
        printf("Error: no hay registros guardados todavia.\n");
        return; // Corta la funcion aqui mismo
    }

    // Si llega aqui, si hay datos y puedes poner tu ciclo for normal
}


// 10. VALIDAR QUE EL ARREGLO NO ESTE LLENO ANTES DE INGRESAR
void validarNoLleno() {
    int cont = 0;

    for (int i = 0; i < MAX; i++) {
        if (ocupado[i] == 1) {
            cont++;
        }
    }

    if (cont == MAX) {
        printf("Error: sistema lleno (maximo %d registros).\n", MAX);
        return; // Corta la funcion aqui mismo
    }
}
