/*
 *  UNIDAD PROFESIONAL INTERDISCIPLINARIA DE INGENIERÍA CAMPUS ZACATECAS
 *                     INSTITUTO POLITÉCNICO NACIONAL
 *
 *              Unidad de aprendizaje: Sistemas en Chip
 *              Alumno: Alejandro Tamayo Castro
 *
 * Descripción:
 * Generacion de Automata de 4 estados, gobernado por un boton
 */
#include <msp430.h>

char estado = 'A';
/**
 * main.c
 */
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;           // stop watchdog timer

    //Leds
    P4DIR |= BIT7;                      //Configuro el puerto 4.7 como salida
    P1DIR |= BIT0;                      //Configuro el puerto 1.0 como salida
    P2DIR |= BIT0;
    P2OUT &= ~BIT0;


    //Boton
    P2DIR &= ~BIT1;                     //Habilitar boton
    P2REN |= BIT1;                      //Habilitar resistencia
    P2OUT |= BIT1;                      //Habilitar pullup

    //Timmer, interrupciones y Modo de baja potencia
    TA0CTL |= TASSEL_ACLK | MC_UP;
    TA0CCR0 = 1000;                     //Determina hasta donde cuenta
    TA0CCTL0 |= CCIE;                   //Se habilita la interrupcion del registro captura/comparacion del Timer 0
    _BIS_SR(LPM0_bits + GIE);           //Modo dormido LPM0 e Interrupciones globales
}

//Interrupción y Autómata
#pragma vector=TIMER0_A0_VECTOR                 //Interrupcion, esta linea no se modifica
__interrupt void Automata (void)                //Solo modificar el Nombre que es para referirse
{
    //Lógica de estado siguiente
    if (estado == 'A' && !(P2IN & BIT1)){       //Si estoy en A y presiono
        estado = 'B';
    }
    if (estado == 'B' && (P2IN & BIT1)){        //Si estoy en B y no presiono
        estado = 'C';
    }
    if (estado == 'C' && !(P2IN & BIT1)){       //Si estoy en C y presiono
        estado = 'D';
    }
    if (estado == 'D' && (P2IN & BIT1)){        //Si estoy en D y no presiono
        estado = 'A';
    }

    //Lógica de salida
    switch (estado){
    case 'B':
        TA0CCR0 = 63;
        P2OUT ^= BIT0;
        break;
    case 'C':
        TA0CCR0 = 56;
        P2OUT ^= BIT0;
        break;
    case 'D':
        TA0CCR0 = 49;
        P2OUT ^= BIT0;
        break;
    default:
        TA0CCR0 = 46;
        P2OUT ^= BIT0;
        break;
    }
