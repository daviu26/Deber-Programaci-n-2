#include <stdio.h>
#include <string.h>

int main() {
    int id = 0, stock = 0, opcion, cantidad;
    float precio = 0.0, ganancias = 0.0, descuento;
    char nombre[50] = "";

    // Registro inicial del producto
    printf("ID del producto: ");
    scanf("%d", &id);
    getchar(); 
    
    printf("Nombre del producto: ");
    fgets(nombre, 50, stdin);
    nombre[strcspn(nombre, "\n")] = 0; 
    
    do {
        printf("Stock inicial: ");
        scanf("%d", &stock);
    } while (stock < 0);

    do {
        printf("Precio unitario: ");
        scanf("%f", &precio);
    } while (precio < 0);

    do {
        printf("\n\t--- MENU DE LA TIENDA ---\n");
        printf("\t1. Vender producto\n");
        printf("\t2. Reabastecer\n");
        printf("\t3. Consultar informacion\n");
        printf("\t4. Ver ganancias\n");
        printf("\t5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Cantidad a vender: ");
                scanf("%d", &cantidad);
                if (cantidad < 0) {
                    printf("Error. Numero no valido.\n");
                } else if (cantidad > stock) {
                    printf("Error. Stock insuficiente.\n");
                } else {
                    printf("Descuento por unidad ($): ");
                    scanf("%f", &descuento);
                    if (descuento < 0 || descuento > precio) descuento = 0;
                    
                    stock -= cantidad;
                    ganancias += (precio - descuento) * cantidad;
                    printf("Venta completada.\n");
                }
                break;
            case 2:
                printf("Cantidad a agregar: ");
                scanf("%d", &cantidad);
                if (cantidad > 0) {
                    stock += cantidad;
                    printf("Stock actualizado.\n");
                } else {
                    printf("Cantidad invalida.\n");
                }
                break;
            case 3:
                printf("\n\t--- DATOS DEL PRODUCTO ---\n");
                printf("ID: %d\nNombre: %s\nStock: %d\nPrecio: $%.2f\n", id, nombre, stock, precio);
                break;
            case 4:
                printf("Ganancias totales acumuladas: $%.2f\n", ganancias);
                break;
            case 5:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opcion incorrecta.\n");
        }
    } while (opcion != 5);

    return 0;
}