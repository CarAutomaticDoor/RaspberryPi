#ifndef __SERVER_H__
#define __SERVER_H__
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/sdp.h>
#include <bluetooth/sdp_lib.h>
#include <bluetooth/rfcomm.h>

extern int client;

int _str2uuid( const char *uuid_str, uuid_t *uuid );
sdp_session_t *register_service(uint8_t rfcomm_channel);
int init_server();
char * read_server(int client);
void write_server(int client, char *message);

#endif