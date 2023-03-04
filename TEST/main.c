#include <msp430.h>

int estado = 0;

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;           // stop watchdog timer

    //Leds
    P4DIR |= BIT7;                      //Configuro el puerto 4.7 como salida
    P1DIR |= BIT0;                      //Configuro el puerto 1.0 como salida

    //Buzzer
    P2DIR |= BIT0;
    P2OUT &= ~BIT0;

    //Boton
    P2DIR &= ~BIT1;                     //Habilitar boton
    P2REN |= BIT1;                      //Habilitar resistencia
    P2OUT |= BIT1;                      //Habilitar pullup

    //Timmer, interrupciones y Modo de baja potencia
    TA0CTL  |=  TASSEL__ACLK |  MC__UP;
    TA0CCR0 = 1000;                     //Determina hasta donde cuenta
    TA0CCTL0 |= CCIE;                   //Se habilita la interrupcion del registro captura/comparacion del Timer 0
    _BIS_SR(LPM0_bits + GIE);           //Modo dormido LPM0 e Interrupciones globales
}

//Interrupción y Autómata
#pragma vector=TIMER0_A0_VECTOR                 //Interrupcion, esta linea no se modifica
__interrupt void Automata (void)                //Solo modificar el Nombre que es para referirse
{
    if(estado == 0 && !(P2IN & BIT1)){         //Sonido FA
        estado = 1;
    }
    if(estado == 1 && (P2IN & BIT1)){          //Pausa
        estado = 2;
    }

    if(estado == 2 && !(P2IN & BIT1)){         //Sonido FA
        estado = 3;
    }
    if(estado == 3 && (P2IN & BIT1)){          //Pausa
        estado = 4;
    }

    if(estado == 4 && !(P2IN & BIT1)){         //Sonido FA
        estado = 5;
    }
    if(estado == 5 && (P2IN & BIT1)){          //Pausa
        estado = 6;
    }

    if(estado == 6 && !(P2IN & BIT1)){         //Sonido FA
        estado = 7;
    }
    if(estado == 7 && (P2IN & BIT1)){          //Pausa
        estado = 8;
    }

    if(estado == 8 && !(P2IN & BIT1)){         //Sonido FA
        estado = 9;
    }
    if(estado == 9 && (P2IN & BIT1)){          //Pausa
        estado = 10;
    }

    if(estado == 10 && !(P2IN & BIT1)){        //Sonido FA
        estado = 11;
    }
    if(estado == 11 && (P2IN & BIT1)){         //Pausa
        estado = 12;
    }

    if(estado == 12 && !(P2IN & BIT1)){        //Sonido FA
        estado = 13;
    }
    if(estado == 13 && (P2IN & BIT1)){         //Pausa
        estado = 14;
    }

    if(estado == 14 && !(P2IN & BIT1)){        //Sonido FA
        estado = 15;
    }
    if(estado == 15 && (P2IN & BIT1)){         //Pausa
        estado = 16;
    }

    if(estado == 16 && !(P2IN & BIT1)){        //Sonido FA
        estado = 17;
    }
    if(estado == 17 && (P2IN & BIT1)){         //Pausa
        estado = 18;
    }

    if(estado == 18 && !(P2IN & BIT1)){        //Sonido FA
        estado = 19;
    }
    if(estado == 19 && (P2IN & BIT1)){         //Pausa
        estado = 20;
    }

    if(estado == 20 && !(P2IN & BIT1)){        //Sonido FA
        estado = 21;
    }
    if(estado == 21 && (P2IN & BIT1)){         //Pausa
        estado = 22;
    }

    if(estado == 22 && !(P2IN & BIT1)){        //Sonido FA
        estado = 23;
    }
    if(estado == 23 && (P2IN & BIT1)){         //Pausa
        estado = 24;
    }

    if(estado == 24 && !(P2IN & BIT1)){        //Sonido FA
        estado = 25;
    }
    if(estado == 25 && (P2IN & BIT1)){         //Pausa
        estado = 26;
    }

    if(estado == 26 && !(P2IN & BIT1)){        //Sonido FA
        estado = 27;
    }
    if(estado == 27 && (P2IN & BIT1)){         //Pausa
        estado = 28;
    }

    if(estado == 28 && !(P2IN & BIT1)){        //Sonido FA
        estado = 29;
    }
    if(estado == 29 && (P2IN & BIT1)){         //Pausa
        estado = 30;
    }

    if(estado == 30 && !(P2IN & BIT1)){        //Sonido FA
        estado = 31;
    }
    if(estado == 31 && (P2IN & BIT1)){         //Pausa
        estado = 32;
    }

    if(estado == 32 && !(P2IN & BIT1)){        //Sonido FA
        estado = 33;
    }
    if(estado == 33 && (P2IN & BIT1)){         //Pausa
        estado = 34;
    }

    if(estado == 34 && !(P2IN & BIT1)){        //Sonido FA
        estado = 35;
    }
    if(estado == 35 && (P2IN & BIT1)){         //Pausa
        estado = 36;
    }

    if(estado == 36 && !(P2IN & BIT1)){        //Sonido FA
        estado = 37;
    }
    if(estado == 37 && (P2IN & BIT1)){         //Pausa
        estado = 38;
    }

    if(estado == 38 && !(P2IN & BIT1)){        //Sonido FA
        estado = 39;
    }
    if(estado == 39 && (P2IN & BIT1)){         //Pausa
        estado = 40;
    }

    if(estado == 40 && !(P2IN & BIT1)){        //Sonido FA
        estado = 41;
    }
    if(estado == 41 && (P2IN & BIT1)){         //Pausa
        estado = 42;
    }

    if(estado == 42 && !(P2IN & BIT1)){        //Sonido FA
        estado = 43;
    }
    if(estado == 43 && (P2IN & BIT1)){         //Pausa
        estado = 44;
    }

    if(estado == 44 && !(P2IN & BIT1)){        //Sonido FA
        estado = 45;
    }
    if(estado == 45 && (P2IN & BIT1)){         //Pausa
        estado = 46;
    }

    if(estado == 46 && !(P2IN & BIT1)){        //Sonido FA
        estado = 47;
    }
    if(estado == 47 && (P2IN & BIT1)){         //Pausa
        estado = 48;
    }

    if(estado == 48 && !(P2IN & BIT1)){        //Sonido FA
        estado = 49;
    }
    if(estado == 49 && (P2IN & BIT1)){         //Pausa
        estado = 50;
    }

    if(estado == 50 && !(P2IN & BIT1)){        //Sonido FA
        estado = 51;
    }
    if(estado == 51 && (P2IN & BIT1)){         //Pausa
        estado = 52;
    }

    if(estado == 52 && !(P2IN & BIT1)){        //Sonido FA
        estado = 53;
    }
    if(estado == 53 && (P2IN & BIT1)){         //Pausa
        estado = 54;
    }

    if(estado == 54 && !(P2IN & BIT1)){        //Sonido FA
        estado = 55;
    }
    if(estado == 55 && (P2IN & BIT1)){         //Pausa
        estado = 56;
    }

    if(estado == 56 && !(P2IN & BIT1)){        //Sonido FA
        estado = 57;
    }

    if(estado == 57 && !(P2IN & BIT1)){        //Sonido FA
        estado = 58;
    }
    if(estado == 58 && (P2IN & BIT1)){         //Pausa
        estado = 59;
    }
    if(estado == 56 && !(P2IN & BIT1)){        //Sonido FA
        estado = 60;
    }

    if(estado == 60 && !(P2IN & BIT1)){        //Sonido FA
        estado = 61;
    }
    if(estado == 61 && (P2IN & BIT1)){         //Pausa
        estado = 62;
    }

    if(estado == 62 && !(P2IN & BIT1)){        //Sonido FA
        estado = 63;
    }
    if(estado == 63 && (P2IN & BIT1)){         //Pausa
        estado = 64;
    }

    if(estado == 64 && !(P2IN & BIT1)){        //Sonido FA
        estado = 65;
    }
    if(estado == 65 && (P2IN & BIT1)){         //Pausa
        estado = 66;
    }

    if(estado == 66 && !(P2IN & BIT1)){        //Sonido FA
        estado = 67;
    }
    if(estado == 67 && (P2IN & BIT1)){         //Pausa
        estado = 68;
    }

    if(estado == 68 && !(P2IN & BIT1)){        //Sonido FA
        estado = 69;
    }
    if(estado == 69 && (P2IN & BIT1)){         //Pausa
        estado = 70;
    }

    if(estado == 70 && !(P2IN & BIT1)){        //Sonido FA
        estado = 71;
    }
    if(estado == 71 && (P2IN & BIT1)){         //Pausa
        estado = 72;
    }

    if(estado == 72 && !(P2IN & BIT1)){        //Sonido FA
        estado = 73;
    }
    if(estado == 73 && (P2IN & BIT1)){         //Pausa
        estado = 74;
    }

    if(estado == 74 && !(P2IN & BIT1)){        //Sonido FA
        estado = 75;
    }
    if(estado == 75 && (P2IN & BIT1)){         //Pausa
        estado = 76;
    }

    if(estado == 76 && !(P2IN & BIT1)){        //Sonido FA
        estado = 77;
    }
    if(estado == 77 && (P2IN & BIT1)){         //Pausa
        estado = 78;
    }

    if(estado == 78 && !(P2IN & BIT1)){        //Sonido FA
        estado = 79;
    }
    if(estado == 79 && (P2IN & BIT1)){         //Pausa
        estado = 80;
    }

    if(estado == 80 && !(P2IN & BIT1)){        //Sonido FA
        estado = 81;
    }
    if(estado == 81 && (P2IN & BIT1)){         //Pausa
        estado = 82;
    }

    if(estado == 82 && !(P2IN & BIT1)){        //Sonido FA
        estado = 83;
    }
    if(estado == 83 && (P2IN & BIT1)){         //Pausa
        estado = 84;
    }

    if(estado == 84 && !(P2IN & BIT1)){        //Sonido FA
        estado = 85;
    }
    if(estado == 85 && (P2IN & BIT1)){         //Pausa
        estado = 86;
    }

    if(estado == 86 && !(P2IN & BIT1)){        //Sonido FA
        estado = 87;
    }
    if(estado == 87 && (P2IN & BIT1)){         //Pausa
        estado = 88;
    }

    if(estado == 88 && !(P2IN & BIT1)){        //Sonido FA
        estado = 89;
    }
    if(estado == 89 && (P2IN & BIT1)){         //Pausa
        estado = 90;
    }

    if(estado == 90 && !(P2IN & BIT1)){        //Sonido FA
        estado = 91;
    }
    if(estado == 91 && (P2IN & BIT1)){         //Pausa
        estado = 92;
    }

    if(estado == 92 && !(P2IN & BIT1)){        //Sonido FA
        estado = 93;
    }
    if(estado == 93 && (P2IN & BIT1)){         //Pausa
        estado = 94;
    }

    if(estado == 94 && !(P2IN & BIT1)){        //Sonido FA
        estado = 0;
    }

    P4OUT &= ~BIT7;
    P1OUT &= ~BIT0;

    //Lógica de salida
    switch (estado){
    case 1:
        TA0CCR0 = 47;
        P2OUT ^= BIT0;
        break;
    case 2:
        P2OUT &= ~BIT0;
        break;

    case 3:
        TA0CCR0 = 47;
        P2OUT ^= BIT0;
        break;
    case 4:
        P2OUT &= ~BIT0;
        break;

    case 5:
        TA0CCR0 = 37;
        P2OUT ^= BIT0;
        break;
    case 6:
        P2OUT &= ~BIT0;
        break;

    case 7:
        TA0CCR0 = 59;
        P2OUT ^= BIT0;
        break;
    case 8:
        P2OUT &= ~BIT0;
        break;

    case 9:
        TA0CCR0 = 55;
        P2OUT ^= BIT0;
        break;
    case 10:
        P2OUT &= ~BIT0;
        break;

    case 11:
        TA0CCR0 = 59;
        P2OUT ^= BIT0;
        break;
    case 12:
        P2OUT &= ~BIT0;
        break;

    case 13:
        TA0CCR0 = 47;
        P2OUT ^= BIT0;
        break;
    case 14:
        P2OUT &= ~BIT0;
        break;

    case 15:
        TA0CCR0 = 47;
        P2OUT ^= BIT0;
        break;
    case 16:
        P2OUT &= ~BIT0;
        break;

    case 17:
        TA0CCR0 = 37;
        P2OUT ^= BIT0;
        break;
    case 18:
        P2OUT &= ~BIT0;
        break;

    case 19:
        TA0CCR0 = 59;
        P2OUT ^= BIT0;
        break;
    case 20:
        P2OUT &= ~BIT0;
        break;

    case 21:
        TA0CCR0 = 53;
        P2OUT ^= BIT0;
        break;
    case 22:
        P2OUT &= ~BIT0;
        break;

    case 23:
        TA0CCR0 = 59;
        P2OUT ^= BIT0;
        break;
    case 24:
        P2OUT &= ~BIT0;
        break;

    case 25:
        TA0CCR0 = 37;
        P2OUT ^= BIT0;
        break;
    case 26:
        P2OUT &= ~BIT0;
        break;

    case 27:
        TA0CCR0 = 59;
        P2OUT ^= BIT0;
        break;
    case 28:
        P2OUT &= ~BIT0;
        break;

    case 29:
        TA0CCR0 = 35;
        P2OUT ^= BIT0;
        break;
    case 30:
        P2OUT &= ~BIT0;
        break;

    case 31:
        TA0CCR0 = 37;
        P2OUT ^= BIT0;
        break;
    case 32:
        P2OUT &= ~BIT0;
        break;

    case 33:
        TA0CCR0 = 37;
        P2OUT ^= BIT0;
        break;
    case 34:
        P2OUT &= ~BIT0;
        break;

    case 35:
        TA0CCR0 = 42;
        P2OUT ^= BIT0;
        break;
    case 36:
        P2OUT &= ~BIT0;
        break;

    case 37:
        TA0CCR0 = 42;
        P2OUT ^= BIT0;
        break;
    case 38:
        P2OUT &= ~BIT0;
        break;

    case 39:
        TA0CCR0 = 59;
        P2OUT ^= BIT0;
        break;
    case 40:
        P2OUT &= ~BIT0;
        break;

    case 41:
        TA0CCR0 = 37;
        P2OUT ^= BIT0;
        break;
    case 42:
        P2OUT &= ~BIT0;
        break;

    case 43:
        TA0CCR0 = 42;
        P2OUT ^= BIT0;
        break;
    case 44:
        P2OUT &= ~BIT0;
        break;

    case 45:
        TA0CCR0 = 47;
        P2OUT ^= BIT0;
        break;
    case 46:
        P2OUT &= ~BIT0;
        break;

    case 47:
        TA0CCR0 = 47;
        P2OUT ^= BIT0;
        break;
    case 48:
        P2OUT &= ~BIT0;
        break;

    case 49:
        TA0CCR0 = 47;
        P2OUT ^= BIT0;
        break;
    case 50:
        P2OUT &= ~BIT0;
        break;

    case 51:
        TA0CCR0 = 35;
        P2OUT ^= BIT0;
        break;
    case 52:
        P2OUT &= ~BIT0;
        break;

    case 53:
        TA0CCR0 = 56;
        P2OUT ^= BIT0;
        break;
    case 54:
        P2OUT &= ~BIT0;
        break;

//FA'
    case 55:
        TA0CCR0 = 44;
        P2OUT ^= BIT0;
        break;
    case 56:
        P2OUT &= ~BIT0;
        break;
//FA'
    case 57:
        TA0CCR0 = 44;
        P2OUT ^= BIT0;
        break;
    case 58:
        P2OUT &= ~BIT0;
        break;
//FA'
    case 59:
        TA0CCR0 = 44;
        P2OUT ^= BIT0;
        break;
    case 60:
        P2OUT &= ~BIT0;
        break;
//MI'
    case 61:
        TA0CCR0 = 50;
        P2OUT ^= BIT0;
        break;
    case 62:
        P2OUT &= ~BIT0;
        break;
//DO'
    case 63:
        TA0CCR0 = 59;
        P2OUT ^= BIT0;
        break;
    case 64:
        P2OUT &= ~BIT0;
        break;

//DO'
    case 65:
        TA0CCR0 = 59;
        P2OUT ^= BIT0;
        break;
    case 66:
        P2OUT &= ~BIT0;
        break;
//MI'
    case 67:
        TA0CCR0 = 44;
        P2OUT ^= BIT0;
        break;
    case 68:
        P2OUT &= ~BIT0;
        break;
//MI'
    case 69:
        TA0CCR0 = 44;
        P2OUT ^= BIT0;
        break;
    case 70:
        P2OUT &= ~BIT0;
        break;
//RE'
    case 71:
        TA0CCR0 = 53;
        P2OUT ^= BIT0;
        break;
    case 72:
        P2OUT &= ~BIT0;
        break;
//DO'--
    case 73:
        TA0CCR0 = 59;
        P2OUT ^= BIT0;
        break;
    case 74:
        P2OUT &= ~BIT0;
        break;
//DO'
    case 75:
        TA0CCR0 = 59;
        P2OUT ^= BIT0;
        break;
    case 76:
        P2OUT &= ~BIT0;
        break;
//SIb
    case 77:
        TA0CCR0 = 35;
        P2OUT ^= BIT0;
        break;
    case 78:
        P2OUT &= ~BIT0;
        break;
//SIb
    case 79:
        TA0CCR0 = 35;
        P2OUT ^= BIT0;
        break;
    case 80:
        P2OUT &= ~BIT0;
        break;
//SIb
    case 81:
        TA0CCR0 = 35;
        P2OUT ^= BIT0;
        break;
    case 82:
        P2OUT &= ~BIT0;
        break;
//LA
    case 83:
        TA0CCR0 = 37;
        P2OUT ^= BIT0;
        break;
    case 84:
        P2OUT &= ~BIT0;
        break;
//LA
    case 85:
        TA0CCR0 = 37;
        P2OUT ^= BIT0;
        break;
    case 86:
        P2OUT &= ~BIT0;
        break;
//LA
    case 87:
        TA0CCR0 = 37;
        P2OUT ^= BIT0;
        break;
    case 88:
        P2OUT &= ~BIT0;
        break;
//SOL
    case 89:
        TA0CCR0 = 42;
        P2OUT ^= BIT0;
        break;
    case 90:
        P2OUT &= ~BIT0;
        break;
//SOL
    case 91:
        TA0CCR0 = 42;
        P2OUT ^= BIT0;
        break;
    case 92:
        P2OUT &= ~BIT0;
        break;
//FA------
    case 93:
        TA0CCR0 = 47;
        P2OUT ^= BIT0;
        break;
    case 94:
        P2OUT &= ~BIT0;
        break;

    default:
        P1OUT |= BIT0;
        P2OUT &= ~BIT0;
        break;
    }
}

