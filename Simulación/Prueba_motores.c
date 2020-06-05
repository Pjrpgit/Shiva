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
   TRISC= 0B00000000;
   TRISA= 0B001011;
   portC= 0B00000000;
   //setup_timer_2(T2_DIV_BY_16,249,1);           // setup_timer(Prescaler,PR2,Postscaler)
                     // Configuración timer2. Si el Periodo = 16mS ----> T = 16000uS
                     // T = [PR2+1] x Tcm x Postscaler x Prescaler
                     // PR2 puede valer de 0 a 255.
                     // Tcm es el tiempo de Ciclo Maquina.  Tcm = 4/Fosc = 4/1.000.000 hz = 4uS.
                     // Prescaler puede valer 1,4,16
                     // Postscaler puede valer 1.
                     // 16000uS = [PR2+1] x 4 x 16 x 1

                     // PR2 =[T/(Tcm x Preescaler x Postscaler)]-1
                     // PR2 =[16000uS/(4uS x 16 x 1)]-1 = 249          (en C 249)
   
   
   //setup_ccp2(CCP_PWM);                         // CCP2 en modo PWM (Salida por RC1)
   //setup_ccp1(CCP_PWM);                         // CCP1 en modo PWM (Salida por RC2)
   


   lcd_init();             // Inicializamos el LCD.
   kbd_init();              // Inicializamos el Teclado.

   port_b_pullups(TRUE);          // Habilitamos las Resistencias pull up inernas en el puerto B
   
   
   while(1){
            rc2=0;
            rc1=0;
            lcd_gotoxy(1,1);
            printf(lcd_putc, "Mod Prue.Motor", );
            rc5=0;
            ra2=0;
            rc0=0;
            ra4=0;
            //set_pwm1_duty(1000);
            //set_pwm2_duty(1000);
            delay_ms(2000);
            lcd_gotoxy(1,2);
            printf(lcd_putc, "\fMot. Izq", );
            rc5=1;
            ra2=0;
            rc0=0;
            ra4=0;
            //set_pwm1_duty(1000);
            //set_pwm2_duty(0);
            delay_ms(4000);
            lcd_gotoxy(1,2);
            printf(lcd_putc, "\fMot. Der", );
            rc5=0;
            ra2=0;
            rc0=1;
            ra4=0;
            //set_pwm1_duty(0);
            //set_pwm2_duty(1000);      
            delay_ms(4000);
            lcd_gotoxy(1,2);
            printf(lcd_putc, "\fAdelante", );
            rc5=1;
            ra2=0;
            rc0=1;
            ra4=0;
            //set_pwm1_duty(0);
            set_pwm2_duty(0);            
            delay_ms(4000);
            lcd_gotoxy(1,2);
            printf(lcd_putc, "\fAtras", );
            rc5=0;
            ra2=1;
            rc0=0;
            ra4=1;
            //set_pwm1_duty(512);
            //set_pwm2_duty(512); 
            delay_ms(4000);
            


 
    }
                         
}

