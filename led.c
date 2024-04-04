#include "led.h"

#include <stdio.h>    
#include <wiringPi.h> 

void init_gpio(void) {
    if(wiringPiSetupGpio() < 0){  // 이 함수를 통해 BCM핀을 사용하겠다고 선언 및 핀 초기화
        printf("Unable to setup wiring Pi");
        return;                                
    }

    pinMode(LED1, OUTPUT);
}