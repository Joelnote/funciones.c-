#include <stdio.h>

#define MAX 5

// Arreglos paralelos base (adaptalos al tema de tu examen)
int codigo[MAX];
char nombre[MAX][50];
float valor[MAX];    // Sirve para notas, precios, tiempos, sueldos, etc.
int ocupado[MAX];    // 0 = libre, 1 = ocupado


// 1. MENU PRINCIPAL
void menu() {
    int op;
    do {
        printf("\n=== MENU ===\n");
        printf("1. Ingresar en posicion\n");
        printf("2. Llenar todo el arreglo\n");
        printf("3. Mostrar todos\n");
        printf("4. Buscar por codigo\n");
        printf("5. Editar valor\n");
        printf("6. Eliminar / Liberar\n");
        printf("7. Sumar y promedio\n");
        printf("8. Mayor y menor\n");
        printf("9. Contar aprobados/reprobados\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &op);

        switch (op) {
            case 1: /* llamar funcion */ break;
            case 2: /* llamar funcion */ break;
            case 0: printf("Saliendo...\n"); break;
            default: printf("Opcion no valida\n");
        }
    } while (op != 0);
}


// 2. INGRESAR EN UNA POSICION ESPECIFICA (Ej: parqueadero o inventario)
void ingresarPosicion() {
    int pos;
    printf("Posicion (0 - %d): ", MAX - 1);
    scanf("%d", &pos);

    printf("Codigo: ");
    scanf("%d", &codigo[pos]);

    printf("Nombre: ");
    scanf("%s", nombre[pos]);

    printf("Valor/Nota: ");
    scanf("%f", &valor[pos]);

    ocupado[pos] = 1;
    printf("Registrado.\n");
}


// 3. LLENAR TODO EL ARREGLO DE GOLPE (Ej: ingresar 5 estudiantes seguidos)
void llenarTodo() {
    for (int i = 0; i < MAX; i++) {
        printf("\n--- Registro %d ---\n", i);
        printf("Codigo: ");
        scanf("%d", &codigo[i]);

        printf("Nombre: ");
        scanf("%s", nombre[i]);

        printf("Valor/Nota: ");
        scanf("%f", &valor[i]);

        ocupado[i] = 1;
    }
    printf("Todos los datos ingresados.\n");
}


// 4. INGRESAR EN EL PRIMER ESPACIO LIBRE (Automatico, sin pedir posicion)
void ingresarAutomatico() {
    for (int i = 0; i < MAX; i++) {
        if (ocupado[i] == 0) {
            printf("Guardando en posicion libre %d\n", i);
            printf("Codigo: ");
            scanf("%d", &codigo[i]);
            printf("Nombre: ");
            scanf("%s", nombre[i]);
            printf("Valor/Nota: ");
            scanf("%f", &valor[i]);

            ocupado[i] = 1;
            printf("Guardado con exito.\n");
            return; // Sale apenas guarda uno
        }
    }
    printf("No hay espacios libres.\n");
}


// 5. MOSTRAR TABLA DE DATOS
void mostrar() {
    printf("\nPOS\tCOD\tNOMBRE\t\tVALOR\n");
    for (int i = 0; i < MAX; i++) {
        if (ocupado[i] == 1) {
            printf("%d\t%d\t%s\t\t%.2f\n", i, codigo[i], nombre[i], valor[i]);
        } else {
            printf("%d\t-\t---\t\t0.00\n", i);
        }
    }
}


// 6. BUSCAR POR CODIGO / NUMERO
void buscarPorCodigo() {
    int busq, encontrado = 0;
    printf("Ingrese codigo a buscar: ");
    scanf("%d", &busq);

    for (int i = 0; i < MAX; i++) {
        if (ocupado[i] == 1 && codigo[i] == busq) {
            printf("Encontrado en pos %d -> Nombre: %s | Valor: %.2f\n", i, nombre[i], valor[i]);
            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0) {
        printf("Codigo no encontrado.\n");
    }
}


// 7. EDITAR / MODIFICAR UN DATO BUSCANDO POR CODIGO
void editarValor() {
    int busq;
    printf("Ingrese codigo del registro a editar: ");
    scanf("%d", &busq);

    for (int i = 0; i < MAX; i++) {
        if (ocupado[i] == 1 && codigo[i] == busq) {
            printf("Valor actual de %s: %.2f\n", nombre[i], valor[i]);
            printf("Ingrese nuevo valor: ");
            scanf("%f", &valor[i]);
            printf("Actualizado correctamente.\n");
            return;
        }
    }
    printf("Codigo no encontrado.\n");
}


// 8. ELIMINAR / LIBERAR UNA POSICION
void eliminarPosicion() {
    int pos;
    printf("Posicion a eliminar (0 - %d): ", MAX - 1);
    scanf("%d", &pos);

    ocupado[pos] = 0;
    codigo[pos] = 0;
    valor[pos] = 0;
    printf("Espacio liberado.\n");
}


// 9. SUMAR TODOS LOS VALORES Y SACAR PROMEDIO (Ej: promedio de notas)
void promedioNotas() {
    float suma = 0;
    int cont = 0;

    for (int i = 0; i < MAX; i++) {
        if (ocupado[i] == 1) {
            suma += valor[i];
            cont++;
        }
    }

    if (cont == 0) {
        printf("No hay notas registradas.\n");
    } else {
        printf("Suma total: %.2f\n", suma);
        printf("Promedio general: %.2f\n", suma / cont);
    }
}


// 10. ENCONTRAR EL MAYOR (Ej: mejor nota, mayor venta)
void imprimirMayor() {
    float mayor = -1;
    int posMay = -1;

    for (int i = 0; i < MAX; i++) {
        if (ocupado[i] == 1 && valor[i] > mayor) {
            mayor = valor[i];
            posMay = i;
        }
    }

    if (posMay == -1) {
        printf("No hay registros.\n");
    } else {
        printf("El mayor es %s (Cod: %d) con %.2f\n", nombre[posMay], codigo[posMay], mayor);
    }
}


// 11. ENCONTRAR EL MENOR (Ej: ganador por menor tiempo, precio mas barato)
void imprimirMenor() {
    float menor = 999999;
    int posMen = -1;

    for (int i = 0; i < MAX; i++) {
        if (ocupado[i] == 1 && valor[i] < menor) {
            menor = valor[i];
            posMen = i;
        }
    }

    if (posMen == -1) {
        printf("No hay registros.\n");
    } else {
        printf("El menor es %s (Cod: %d) con %.2f\n", nombre[posMen], codigo[posMen], menor);
    }
}


// 12. CONTAR CUANTOS CUMPLEN UNA CONDICION (Ej: aprobados >= 6 y reprobados)
void contarAprobados() {
    int aprobados = 0, reprobados = 0;

    for (int i = 0; i < MAX; i++) {
        if (ocupado[i] == 1) {
            if (valor[i] >= 6.0) {
                aprobados++;
            } else {
                reprobados++;
            }
        }
    }

    printf("Aprobados: %d\n", aprobados);
    printf("Reprobados: %d\n", reprobados);
}


// 13. MOSTRAR SOLO LOS QUE SUPERAN UN LIMITE (Ej: notas mayores al promedio o stock bajo)
void filtrarSuperiores() {
    float limite;
    int hay = 0;
    printf("Mostrar registros mayores a: ");
    scanf("%f", &limite);

    for (int i = 0; i < MAX; i++) {
        if (ocupado[i] == 1 && valor[i] > limite) {
            printf("- %s: %.2f\n", nombre[i], valor[i]);
            hay = 1;
        }
    }

    if (hay == 0) {
        printf("Ningun registro supera %.2f\n", limite);
    }
}


// 14. APLICAR UN AUMENTO O DESCUENTO A TODOS (Ej: subir 10% o sumar 1 punto)
void aplicarPorcentaje() {
    float porcentaje;
    printf("Ingrese porcentaje a aumentar (ej: 10 para 10%%): ");
    scanf("%f", &porcentaje);

    for (int i = 0; i < MAX; i++) {
        if (ocupado[i] == 1) {
            valor[i] = valor[i] + (valor[i] * porcentaje / 100.0);
        }
    }
    printf("Valores actualizados.\n");
}


// 15. VACIAR / REINICIAR TODO EL SISTEMA
void limpiarTodo() {
    for (int i = 0; i < MAX; i++) {
        ocupado[i] = 0;
        codigo[i] = 0;
        valor[i] = 0;
    }
    printf("Todos los registros han sido borrados.\n");
}
