#ifndef RECEIVER_H
#define RECEIVER_H
#include<stdio.h>
#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int16_t receieve_message(void);
void send_message(char no[100]);
#endif // RECEIVER_H
