#include "head.h"

int main(void)
{
    double data[2];
    uint32_t zuo,you;
    configure();
    while(1)
    {
        if(UARTRead(1,UART_rec)==1)
        {
//           UARTprintf(1,UART_rec);
            delay_ms(100);
            if(UART_rec[0]==0x50)
            {
                UARTprintf(0,"RECEIVE 0X50");
                my_bytnum(UART_rec+1,data,100.0);
                my_bytnum(UART_rec+3,data+1,100.0);
                UARTprintf(0,data);
                UARTprintf(0,"\n");
                if(UART_rec[5]==0x60)
                {
                    UARTprintf(0,"GO OR DOWN IS OK\n");
                    if(UART_rec[6]==0x63)
                    {
                        zuo = 8000+40*data[0]-10*data[1];
                        you = 8000+40*data[0]+10*data[1];
                    }
                    else if(UART_rec[5]==0x64)
                    {
                        zuo = 8000+40*data[0]+10*data[1];
                        you = 8000+40*data[0]-10*data[1];
                    }
                    else if(UART_rec[5]==0x65)
                    {
                        zuo = 1000;
                        you = 1000;
                    }
                    else
                    {
                        Motor1Disanable;
                        Motor2Disanable;
                    }
                    Motor1Z(zuo);
                    Motor2Z(you);
                    UARTprintf(0,"UP IS OK\n");
                }
                else if(UART_rec[5]==0x61)
                {
                    if(UART_rec[6]==0x63)
                    {
                        zuo = 8000+40*data[0]-10*data[1];
                        you = 8000+40*data[0]+10*data[1];
                    }
                    else if(UART_rec[5]==0x64)
                    {
                        zuo = 8000+40*data[0]+10*data[1];
                        you = 8000+40*data[0]-10*data[1];
                    }
                    else if(UART_rec[5]==0x65)
                    {
                        zuo = 8000+40*data[0];
                        you = 8000+40*data[0];
                    }
                    else
                    {
                        Motor1Disanable;
                        Motor2Disanable;
                    }
                    Motor1F(zuo);
                    Motor2F(you);
                    UARTprintf(0,"DOWM IS OK\n");
                }
                else if(UART_rec[5]==0x62)
                {
                    Motor1Disanable;
                    Motor2Disanable;
                    UARTprintf(0,"STOP IS OK\n");
                }
                else
                {
                    ;
                }
            }
//            else
//            {
//                ;
//            }
        }
        delay_ms(100);
//        UARTprintf(1,"OK\n");
//
    }
}
