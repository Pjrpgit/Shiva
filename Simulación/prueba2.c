#include <16F876.h>
#device adc=10            // Conversor Analogico Digital de 10 bit el PIC 16F876A puede trabajar con 8 o 10 bit de resolucion.

#fuses XT,NOWDT,NOPROTECT,NOLVP
#use delay(clock= 4000000)        

#include <LCD1.c>            // Incluimos el driver LCD1.c que contiene las funciones de control del LCD.
#include <kbd1.c>            // Incluimos el driver kbd1.c que contiene las funciones de control del Teclado.
        

void main()

{

   char k; 
   int16 q;
   float y;
   float s;
   float x;
   float z;
   float l;
      
   lcd_init();             // Inicializamos el LCD.
   kbd_init();              // Inicializamos el Teclado.
   
   setup_ccp2(CCP_PWM);                         // CCP2 en modo PWM (Salida por RC1)
   setup_ccp1(CCP_PWM);                         // CCP1 en modo PWM (Salida por RC2)
   setup_timer_2(T2_DIV_BY_16,249,1);
   
   setup_adc_ports(0100);
   
   setup_adc(ADC_CLOCK_INTERNAL);             // Fuente de reloj RC interno.
   set_adc_channel(0);                    // HabilitaciOn canal 0 "AN0"
   port_b_pullups(TRUE);          // Habilitamos las Resistencias pull up inernas en el puerto B
   printf(lcd_putc,"Seleccion Modo");

   do
         {                       
         k=kbd_getc();            // Leemos el caracter del teclado
         x=k-'0'; // Conversión numérica
         }
   while (k==0);         // Lee el Teclado constantemente si no se pulsa una tecla 
   
   printf(lcd_putc,"\f");
   switch(k){
   
      case('*'):
         lcd_gotoxy(1,1);
         printf(lcd_putc, "Modo Motores", );  
         break;
      case('1'):
         lcd_gotoxy(1,1);      
         printf(lcd_putc,"El 1",);   // Escribimos 1 digitos de la variable "k" en formato caracter.
         break;
      default:
         lcd_gotoxy(1,1);      
         printf(lcd_putc,"Modo Medidor",);   // Escribimos 1 digitos de la variable "k" en formato caracter.
         break;
   }   
   while(1){
      delay_us(20);               // Retardo de 20uS necesaria para respetar el tiempo de Adquisicion Tad.
      q=read_adc();                        // Lectura canal 0   "AN0"
      y=5.0 * q / 1024.0;                 // Conversion a tension del codigo digital "q".
      if (2.1>=y<=2.4){
         z=y-2.1;
         s=(2*z)/40;
         x=0.08+s;
         l=(1/x)-0.42;
         lcd_gotoxy(1,2);
         printf(lcd_putc, "Distancia=%f",l);
        
      }
      if (1.4>=y<2.1){
         l=1/(0.08+(0.017*y-2.1)/0.33)-0.42;
         lcd_gotoxy(1,2);
         printf(lcd_putc, "Distancia=%f",l);
      }
         
      
      if (0.7>=y<1.4){
         z=y-1.4;
         s=(2*z)/40;
         x=0.05+s;
         l=(1/x)-0.42;
         lcd_gotoxy(1,2);
         printf(lcd_putc, "Distancia=%f",l);
      }
      
      if (y<0.7){
         lcd_gotoxy(1,2);
         printf(lcd_putc, "OutofRank",);    
      }
      if (y>2.4){
         lcd_gotoxy(1,2);
         printf(lcd_putc, "OutofRank",);
      }
   }
}

