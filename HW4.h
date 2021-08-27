//
//  HW 4.h
//  
//
//  Created by Terry Delaney on 3/23/2021.
//

#ifndef HW_4_h
#define HW_4_h

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int ctrlc;
int sigreceived;
struct sigaction intaction;
struct sigaction alarmaction;
sigset_t intblock;
sigset_t intunblock;

void countctrlc(int signo);
void proceed(int signo);
void ignorectrlc(int signo);

#endif /* HW_4_h */
