#ifndef SENDER_H
#define SENDER_H
#include <stdio.h>
#include <mqueue.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
void send_message1(char no[100]);
int16_t receieve_message1();
#endif
