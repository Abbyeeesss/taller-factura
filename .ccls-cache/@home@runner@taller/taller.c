#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validarCedula(int num_cedula) {
  int cedula[15];
  int suma_par = 0;
  int suma_impar = 0;
  int suma_total;
  int verificador;
  int esValido = 0;

  for(int i = 9; i >= 0; i--){
    cedula[i] = num_cedula % 10;
    num_cedula = num_cedula / 10;
  }

  suma_par = 0;
  suma_impar = 0;

  for(int i = 0; i < 9; i += 2){
    if(cedula[i] * 2 >= 10){
      suma_impar += (cedula[i] * 2) - 9;
    } else{
      suma_impar += cedula[i] * 2;
    }
  }

  for(int i = 1; i < 9; i += 2){
    suma_par += cedula[i];
  }

  suma_total = suma_par + suma_impar;
  verificador = suma_total + cedula[9];

  if(verificador % 10 == 0){
    esValido = 1;
  } else{
    printf("Su cédula no es válida.\n");
  }

  return esValido;
}

int main(void) {
  int num1=0,num2=0,num3=0,num4=0,num5=0, op;
  char direccion[15], sn[6], fecha[12], nom[20];
  char telefono[10];
  int llantas=150;
  int pastillas=55;
  int embrage=180;
  int faro=70;
  int radiador=120;
  float precio=0,precio1=0,precio2=0,precio3=0,precio4=0;
  float subtotal,descuento,total,iva,total1;
  int num_cedula,cd;
  int telefono_valido = 0;
  int cedula_valida = 0;

  printf("Ingresar Datos\n");
  printf("Ingresar nombre y apellido: ");
  fgets(nom, sizeof(nom), stdin);
  nom[strcmp(nom, "\n")]=0;

    do {
      printf("Ingrese su número de cédula: ");
      scanf("%d", &num_cedula);
      cedula_valida = validarCedula(num_cedula);

      if (cedula_valida == 1) {
        break;
      }
    } while(1);

  printf("Ingresar fecha: ");
  scanf("%s", fecha);
  printf("Ingresar direccion: ");
  scanf("%s", direccion);

  do { 
    printf("Ingresar telefono: ");
    scanf("%s", telefono);
    if (strlen(telefono) != 10) {
      printf("El número ingresado no tiene 10 dígitos. Ingrese nuevamente\n");
    } else {
      telefono_valido = 1;
    }
  } while(telefono_valido != 1);

  printf("\n");

  do {
    printf("\nIngrese el numero del producto que desea comprar\n");
    printf("1. Llantas\n");
    printf("2. Kit de pastillas de freno\n");
    printf("3. Kit de embrage\n");
    printf("4. Faro\n");
    printf("5. Radiador\n");
    printf("6. Generar factura\n");
    printf("7. Salir del programa\n");
    scanf("%d", &op);

    switch(op) { 
      case (1):
        printf("Ingrese la cantidad de unidades que desea comprar: ");
        scanf("%d", &num1);
        precio = llantas * num1;
        break;
      case (2):
        printf("Ingrese la cantidad de unidades que desea comprar: ");
        scanf("%d", &num2);
        precio1 = pastillas * num2;
        break;
      case (3):
        printf("Ingrese la cantidad de unidades que desea comprar: ");
        scanf("%d", &num3);
        precio2 = embrage * num3;
        break;
      case (4):
        printf("Ingrese la cantidad de unidades que desea comprar: ");
        scanf("%d", &num4);
        precio3 = faro * num4;
        break;
      case (5):
        printf("Ingrese la cantidad de unidades que desea comprar: ");
        scanf("%d", &num5);
        precio4 = radiador * num5;
        break;
      case (6):
        subtotal = precio + precio1 + precio2 + precio3 + precio4;
        if (subtotal <= 500) { 
          descuento = 0;
        } else if (subtotal >= 501 && subtotal <= 1000){
          descuento = subtotal * 0.04;
        } else if (subtotal >= 1001 && subtotal <= 5000) { 
          descuento = subtotal * 0.07;
        } else { 
          descuento = subtotal * 0.09;
        }

        total = subtotal - descuento;
        iva = subtotal * 0.12;
        total1 = total + iva;

        printf("\n--------------------------FACTURA-------------------------\n" );
        printf("Comprador: %s\n", nom);
        printf("C.I: %d\n",cd);
        printf("Fecha: %s\n", fecha);
        printf("Direccion: %s\n", direccion);
        printf("Telefono: %s\n", telefono);

        printf("\nCantidad\t Codigo\t\t Detalle\t P/U\t Precio Total \n");
        printf("%d\t\t OUEFI\t\t Llantas\t $150\t $%.2f\n", num1, precio);
        printf("%d\t\t GTYUW\t\t Kit.Pa\t\t $55\t $%.2f\n", num2, precio1);     
        printf("%d\t\t AAEVW\t\t Kit.Em\t\t $180\t $%.2f\n", num3, precio2);
        printf("%d\t\t EOKAS\t\t Faro\t\t $70\t $%.2f\n", num4, precio3);
        printf("%d\t\t QWONB\t\t Radiador\t $120\t $%.2f\n", num5, precio4);

        printf("\nSubtotal:\t$%.2f\n", subtotal);
        printf("Descuento:\t$%.2f \n", descuento);
        printf("IVA:\t\t$%.2f\n", iva);
        printf("Total:\t\t$%.2f\n", total1);
        printf("------------------------------------------------------------\n" );
        printf("\n");
        break;
    }
  } while (op != 7);

  printf("GRACIAS POR USAR EL PROGRAMA\n");

  return 0;
}
