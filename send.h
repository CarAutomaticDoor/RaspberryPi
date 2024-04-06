#ifndef __LED_H__
#define __LED_H__

#include <stdio.h>    
#include <wiringPi.h> 

#define OPEN 2  //GPIO2
#define CLOSE 3
#define LOCK 4

void init_gpio(void);

#endif