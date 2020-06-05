#include <16F876.h>
#fuses XT,NOWDT,NOPROTECT,NOLVP
#use delay(clock= 4000000)        

#include <LCD1.c>            // Incluimos el driver LCD1.c que contiene las funciones de control del LCD.
#include <kbd1.c>            // Incluimos el driver kbd1.c que contiene las funciones de control del Teclado.
        

void main()

{

   char k; 
   int8  x;
      
   lcd_init();             // Inicializamos el LCD.
   kbd_init();              // Inicializamos el Teclado.
  
   port_b_pullups(TRUE);          // Habilitamos las Resistencias pull up inernas en el puerto B
   
                          
   while (TRUE)
   
   {
      
      do
         {

         k=kbd_getc();            // Leemos el caracter del teclado
         x=k-'0';                 // Conversión numérica
      
         }

      while (k==0);         // Lee el Teclado constantemente si se pulsa una tecla K es didtinto de cero




      lcd_gotoxy(1,1);      // Posicionamos el Cursor del LCD en la posición 1 línea 1.
            printf(lcd_putc,"Car=%1c",k);   // Escribimos 1 digitos de la variable "k" en formato caracter. 
                  // (Imprime carácter)

      lcd_gotoxy(8,1);      // Posicionamos el Cursor del LCD en la posición 8 línea 1.
      printf(lcd_putc,"Num=%3u",x);   // Escribimos 3 digitos de la variable "x" en formato entero y sin signo.
                  // Imprime valor numérico   
                 
   }
}
