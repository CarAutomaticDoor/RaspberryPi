#include "server.h"
#include "led.h"
#include <string.h>

int client;
// char input[1024] = { 0 };
// char messageArr[1024] = { 0 };

int main() {
    client = init_server();
    init_gpio();

    while(1) {
        char *recv_message = read_server(client);
        if ( recv_message == NULL ){
            printf("client disconnected\n");
            break;
        }

        write_server(client, recv_message);

        printf("main recv : %s", recv_message);

        /* 문 열기 */
        if (strcmp(recv_message, "00OOFF\n") == 0) {  //문자열 같음
            printf("same\n");
            digitalWrite(LED1, 1);
        } else {
            printf("not same\n");
            digitalWrite(LED1, 0);
        }

        /* 문 닫기 */

        /* 잠금, 잠금해제*/
    }
}