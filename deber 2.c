#include <stdio.h>

int main() {
    int estudiantes = 5;
    int asignaturas = 3;
    float notas[5][3];

    for (int i = 0; i < estudiantes; i++) {
        printf("\n-Estudiante %d-\n", i + 1);
        for (int j = 0; j < asignaturas; j++) {
            do {
                printf("Ingresa la calificacion para la asignatura %d (0 a 10): ", j + 1);
                scanf("%f", &notas[i][j]);
                if (notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("Nota invalida. ");
                }
            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }
    }

    printf("\nRESULTADOS POR ESTUDIANTE\n");
    for (int i = 0; i < estudiantes; i++) {
        float suma = 0;
        float max = notas[i][0];
        float min = notas[i][0];

        for (int j = 0; j < asignaturas; j++) {
            suma += notas[i][j];
            if (notas[i][j] > max) max = notas[i][j];
            if (notas[i][j] < min) min = notas[i][j];
        }
        printf("Estudiante %d -> Promedio: %.2f, Nota Mas Alta: %.2f, Nota Mas Baja: %.2f\n", 
               i + 1, suma / asignaturas, max, min);
    }

    printf("\nRESULTADOS POR ASIGNATURA\n");
    for (int j = 0; j < asignaturas; j++) {
        float suma = 0;
        float max = notas[0][j];
        float min = notas[0][j];
        int aprobados = 0;
        int reprobados = 0;

        for (int i = 0; i < estudiantes; i++) {
            suma += notas[i][j];
            if (notas[i][j] > max) max = notas[i][j];
            if (notas[i][j] < min) min = notas[i][j];
            if (notas[i][j] >= 6.0) {
                aprobados++;
            } else {
                reprobados++;
            }
        }
        printf("Asignatura %d - Promedio: %.2f, Nota Mas Alta: %.2f, Nota Mas Baja: %.2f\n", 
               j + 1, suma / estudiantes, max, min);
        printf("   Aprobados: %d, Reprobados: %d\n", aprobados, reprobados);
    }

    return 0;
}