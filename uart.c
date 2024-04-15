#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>

#include "server.h"
#include "send.h"

int client;

int main () {
    int serial_port ;

    client = init_server();
    // init_gpio();
    if ((serial_port = serialOpen ("/dev/ttyAMA1", 115200)) < 0)	/* open serial port */
    {
        fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
        return 1 ;
    }

    if (wiringPiSetup () == -1)					/* initializes wiringPi setup */
    {
        fprintf (stdout, "Unable to start wiringPi: %s\n", strerror (errno)) ;
        return 1 ;
    }

    while(1){

        //블루투스 통신
        char *recv_message = read_server(client);
        if ( recv_message == NULL ){
            printf("client disconnected\n");
            break;
        }


        printf("main recv : %s", recv_message);

        
        //uart 통신
        if (recv_message[2] == 'O') {  //문 열기
            printf("open\n");
            serialPutchar(serial_port, '1');
            
        } 
        else if (recv_message[2] == 'C') {  //문 닫기
            printf("close\n");
            serialPutchar(serial_port, '2');
        }
        else if (recv_message[2] == 'L') {  //잠금
            printf("lock\n");
            serialPutchar(serial_port, '3');
        }


        // if(dat == '1') {
        //   printf ("%c", dat);
        //   serialPutchar(serial_port, dat);		/* transmit character serially on port */
        //   // for(int i=0;i<500000; i++){}
        //   serialFlush(serial_port);
        //   delay(1000);
        // }
    }
    serialClose(serial_port);
}