#include "server.h"
#include "send.h"
#include <string.h>

int client;

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
            digitalWrite(OPEN, 1);
        } else {
            digitalWrite(OPEN, 0);
        }

        /* 문 닫기 */
        if (strcmp(recv_message, "00CCFF\n") == 0) {
            digitalWrite(CLOSE, 1);
        } else {
            digitalWrite(CLOSE, 0);
        }

        /* 잠금, 잠금해제*/
        if (strcmp(recv_message, "00LLFF\n") == 0) {
            digitalWrite(LOCK, 1);
        } else {
            digitalWrite(LOCK, 0);
        }
    }
}