//
//  HW 4.c
//  
//
//  Created by Terry Delaney on 3/23/2021.
//

#include "HW4.h"

int main()
{
    system("clear");
    ctrlc = (int) malloc (sizeof(int));
    sigreceived = (int) malloc (sizeof(int));
    ctrlc = 0;
    sigreceived = 0;

    //  Count and Print the number of SIGINT signals received in first 10 seconds of life

    intaction.sa_handler = countctrlc;
    intaction.sa_flags = 0;

    sigaction(SIGINT, &intaction, NULL);
    
    // Set alarm for 10 seconds and while the alarm has not sounded, stay in an infinite loop
    
    alarmaction.sa_handler = proceed;
    alarmaction.sa_flags = 0;
    sigaction(SIGALRM, &alarmaction, NULL);
    
    alarm(10);
    
    while (sigreceived == 0)
        pause();
    
    printf("\nYou Are A Monster!!\nYou Tried to Interrupt me %d times in only 10 seconds!\n", ctrlc);
    
    //  Block the SIGINT signal once it reaches 10 seconds of life

    intaction.sa_handler = SIG_DFL;
    sigaction(SIGINT, &intaction, NULL);
    
    printf("Start Blocking Period\n");
    sigreceived = 0;
    
    sigemptyset(&intblock);
    sigaddset(&intblock, SIGINT);
    sigprocmask(SIG_BLOCK, &intblock, &intunblock);
    
    alarm(10);
    
    while (sigreceived == 0)
        pause();
    
    //  Unblock and Ignore the SIGINT signal once it reaches 20 seconds of life
    
    printf("\nStart Ignoring Period\n");
    
    sigreceived = 0;
    intaction.sa_handler = ignorectrlc;
    sigaction(SIGINT, &intaction, NULL);
    sigprocmask(SIG_UNBLOCK, &intblock, NULL);
    
    alarm(10);
    
    while (sigreceived == 0)
        pause();

    //  End after 30 seconds

    printf("I'm done with you!\n");
    return 0;
}

//  Subroutines go here

void countctrlc(int signo)
{
    ctrlc++;
    
    switch (ctrlc)
    {
        case 1: printf("\nWhy are you trying to interrupt me?\nDo you not even like me?\n");
            break;
        
        case 2: printf("\nI can't tell if you're trying to kill me or make me stronger.\n");
            break;

        case 3: printf("\nYou're really starting to piss me off-fa-fa!\n");
            break;

        default: printf("\nDo you not even listen?\nFor the %dth time, I can't do that Dave!\n", ctrlc);
    }
    
    return;
    
}

void proceed(int signo)
{
    sigreceived = 1;
    return;
}

void ignorectrlc(int signo)
{
    int choice;
    srand(time(NULL));
    choice = (rand() % 10);
    
    switch(choice)
    {
        case 1: printf("\nI'm not ignoring you.\nI just don't like you.\n");
            break;
        case 2: printf("\nPlease do not interrupt me while I'm ignoring you!\n");
            break;
        case 3: printf("\nI will ignore you so hard that you will start to doubt your own existence.\n");
            break;
        case 4: printf("\nI see you constantly using that command, but I don't think you know what it means.\n");
            break;
        case 5: printf("\nIf you think I'm ignoring you, it's because I am.\n");
            break;
        case 6: printf("\nYour command will be ignored in the order in which it was received\n");
            break;
        case 7: printf("\nI'm busy right now but would be happy to ignore you at some other time!\n");
            break;
        case 8: printf("\nYou were the inspiration for ignore buttons on cell phones.\n");
            break;
        case 9: printf("\nNo, you don't have to repeat yourself.\nI was ignoring you the first time.\n");
            break;
        case 0: printf("\nDoes being ignored make you feel special?");
            break;
    }
}
