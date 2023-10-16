#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void) {
  int num1=0,num2=0,num3=0,num4=0,num5=0,op;
  char direccion[15];
  char sn[6];
  char fecha[12];
  char nom[20];
  char telefono[10];
  int llantas=150;
  int pastillas=55;
  int embrage=180;
  int faro=70;
  int radiador=120;
  float precio=0,precio1=0,precio2=0,precio3=0,precio4=0;
  float subtotal,descuento,total,iva,total1;
  int num_cedula;
  int cedula[10];
  int suma_par = 0;
  int suma_impar = 0;
  int suma_total;
  int verificador;
  int cedula_valida = 0;
  
  //do{ 
  //printf("\nDesea realizar una compra (SI/NO)\n");
  //scanf("%s",sn);
   //if (strcmp(sn, "NO") == 0 || strcmp(sn, "no") == 0) {

  //printf("GRACIAS POR USAR EL PROGRAMA\n");
   //}
   //} while(strcmp(sn, "NO") == 0 || strcmp(sn, "no") == 0);
       
  printf("Ingresar Datos\n");
    printf("Ingresar nombre y apellido: ");
 fgets(nom, sizeof(nom), stdin);
   do{  
    printf("Ingresar cedula:");
   scanf("%d",&num_cedula);
   
    for(int i = 9; i >= 0; i--){
      cedula[i] = num_cedula % 10;
      num_cedula = num_cedula / 10;
    }
    
    suma_par = 0;
    suma_impar = 0;
    
    for(int i = 0; i < 9; i+=2){
      if(cedula[i]*2 >= 10){
        suma_impar += (cedula[i]*2) - 9;
      }else{
        suma_impar += cedula[i]*2;
      }
    }
    
    for(int i = 1; i < 9; i+=2){
      suma_par += cedula[i];
    }
    
    suma_total = suma_par + suma_impar;
    verificador = suma_total + cedula[9];
  
      if (verificador%10 != 0){
      printf("\nSu cédula no es válida.Ingrese nuevamente\n");
      }
   } while(verificador%10 != 0);
  
    printf("Ingresar fecha:");
  scanf("%s",fecha);
    printf("Ingresar direccion: ");
   scanf("%s",direccion);
    printf("Ingresar telefono:");
  scanf("%s",telefono);
 printf("\n");
  do{ 
  printf("\nIngrese el numero del producto que desea comprar\n");
  printf("1.Llantas\n");
  printf("2.Kit de pastillas de freno\n");
  printf("3.Kit de embrage\n");
  printf("4.Faro\n");
  printf("5.Radiador\n");
  printf("6.Generar factura\n");
  printf("7.Salir del programa\n");
  scanf("%d",&op);
    switch(op){ 
    case (1):
    printf("Ingrese la cantidad de unidades que desea comprar:");
      scanf("%d",&num1);
       precio=llantas*num1;
      break;
    case (2):
     printf("Ingrese la cantidad de unidades que desea comprar:");
      scanf("%d",&num2);
      precio1=pastillas*num2;
      break;
    case (3):
     printf("Ingrese la cantidad de unidades que desea comprar:");
      scanf("%d",&num3);
      precio2=embrage*num3;
       break;
    case (4):
     printf("Ingrese la cantidad de unidades que desea comprar:");
      scanf("%d",&num4);
      precio3=faro*num4;
      break;
       case (5):
     printf("Ingrese la cantidad de unidades comprar:");
      scanf("%d",&num5);
      precio4=radiador*num5;
      break;
      case (6):
        subtotal=precio+precio1+precio2+precio3+precio4;
        if (subtotal<=100) { 
          descuento=0;
        } else if (subtotal>=101 && subtotal<=500){
          descuento=subtotal*0.05;
        } else if (subtotal>=501 && subtotal<=1000){ 
          descuento=subtotal*0.07;
        } else { 
          descuento=subtotal*0.1;
      }
          total=subtotal-descuento;
          iva=subtotal*0.12;
          total1=total+iva;
     printf("\n------------------------FACTURA------------------------\n" );

     printf("Comprador:%s\n",nom);
     printf("C.I:%d\n",num_cedula);
     printf("Fecha:%s\n",fecha);
     printf("Direccion:%s\n",direccion);
     printf("Telefono:%s\n",telefono);
    
  printf("\nCantidad \t Codigo \t Detalle \t P/U \t Precio Total \n");
        
  printf("%d\t\t\t OUEFI\t\t Llantas\t $150\t\t  $%.2f\n",num1,precio);
    printf("%d\t\t\t GTYUW\t\t Kit.Pa\t\t $55\t\t $%.2f\n",num2,precio1);     
      printf("%d\t\t\t AAEVW\t\t Kit.Em\t\t $180\t\t $%.2f\n",num3,precio2);
        printf("%d\t\t\t EOKAS\t\t Faro\t\t $70\t\t  $%.2f\n",num4,precio3);
          printf("%d\t\t\t QWONB\t\t Radiador\t $170\t\t  $%.2f\n",num5,precio4);
        
  printf("\nSubtotal:\t$%.2f\n",subtotal);
  printf("Descuento:\t$%.2f \n",descuento);
  printf("IVA 12%:\t$%.2f\n",iva);   
  printf("Total:\t\t$%.2f\n",total1);
  printf("--------------------------------------------------------\n" );
      printf("\n");
    
      break;
    
   }

      //  } else if (strcmp(sn, "NO") == 0 || strcmp(sn, "no") == 0){
        //    printf("GRACIAS POR USAR EL PROGRAMA\n");
        //} else{
          //  printf("Respuesta inválida. Por favor, ingrese 'SI' o 'NO'.\n");
        //}

    } while (op != 7);

    printf("GRACIAS POR USAR EL PROGRAMA\n");
   
    return 0;

}
    
