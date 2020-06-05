#include <16F876.h>
#device adc=10            // Conversor Analogico Digital de 10 bit el PIC 16F876A puede trabajar con 8 o 10 bit de resolucion.

#fuses XT,NOWDT,NOPROTECT,NOLVP
#use delay(clock= 1000000)        

#include <LCD1.c>            // Incluimos el driver LCD1.c que contiene las funciones de control del LCD.
#include <kbd1.c>            // Incluimos el driver kbd1.c que contiene las funciones de control del Teclado.
#include <math.h>
#BYTE TRISC = 0x87               // TRISC en 87h.
#BYTE portC = 0x07               // PORTC en 07h.
#BYTE TRISA = 0x85               // TRISB en 86h.
#BYTE portA = 0x05               // PORTB en 06h.
#BIT rc0 = 0x07.0 
#BIT rc1 = 0x07.1
#BIT rc2 = 0x07.2
#BIT rc5 = 0x07.5
#BIT ra0 = 0x05.0
#BIT ra1 = 0x05.1
#BIT ra2 = 0x05.2
#BIT ra3 = 0x05.3
#BIT ra4 = 0x05.4
#BIT ra5 = 0x05.5


 

void main()

{
   char k; 
   int16 q;
   float x;
   float l;
   float p;
   float r;
   float s;
   float i;
   float e;
   TRISC= 0B00000000;
   TRISA= 0B001011;
   portC= 0B00000000;
   
   setup_adc_ports(0100);
   lcd_init();             // Inicializamos el LCD.
   kbd_init();              // Inicializamos el Teclado.
   setup_adc(ADC_CLOCK_INTERNAL);             // Fuente de reloj RC interno.
   set_adc_channel(0); 
   port_b_pullups(TRUE);          // Habilitamos las Resistencias pull up inernas en el puerto B
   printf(lcd_putc,"Prueb Sensor"); 
   printf(lcd_putc,"\f");
 
   while(1){
            lcd_gotoxy(1,1);      
            printf(lcd_putc,"Funcion polinom",);   // Escribimos 1 digitos de la variable "k" en formato caracter.
            delay_us(20);               // Retardo de 20uS necesaria para respetar el tiempo de Adquisicion Tad.
            q = read_adc();                        // Lectura canal 0   "AN0"
            p = 5.0 * q / 1024.0;                 // Conversion a tension del codigo digital "q".
            r=p*p;
            s=p*p*p;
            i=p*p*p*p; 
            e=((16.75*i)-119.26*s)+(311.7*r)-(365.71*p)+184.03;
            lcd_gotoxy(1,2);      
            printf(lcd_putc,"L=%01.2f", e);                  
            
   }                      
}

