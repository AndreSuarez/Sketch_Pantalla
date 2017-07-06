#include "NexButton.h"
#include "NexText.h"

NexButton b0 = NexButton(0, 2, "b0");
NexButton b1 = NexButton(0, 3, "b1");
NexButton b2 = NexButton(0, 4, "b2");
NexButton b3 = NexButton(0, 5, "b3");

char buffer[10] = {0};

NexTouch *nex_Listen_List[] = 
{
    &b0,
    &b1,
    &b2,
    &b3,
    NULL
};

/**
 * Button to return the response.
 * 
 * @param ptr - the parameter was transmitted to pop event function pointer. 
 * 
 */
void b0PopCallback(void *ptr)
{
    NexButton *btn = (NexButton *)ptr;
    memset(buffer, 0, sizeof(buffer));
    btn->getText(buffer, sizeof(buffer));
    if (strcmp(buffer,"ON"))
    {
        digitalWrite(9, HIGH);
        strcpy(buffer, "ON");
    }
    else
    {
        digitalWrite(9, LOW);
        strcpy(buffer, "OFF");
    }
    btn->setText(buffer);
   
}

/**
 * Button to return the response.
 * 
 * @param ptr - the parameter was transmitted to pop event function pointer. 
 * 
 */
void b1PopCallback(void *ptr)
{
    NexButton *btn = (NexButton *)ptr;
    memset(buffer, 0, sizeof(buffer));
    btn->getText(buffer, sizeof(buffer));
    if (strcmp(buffer,"ON"))
    {
         digitalWrite(10, HIGH);
         strcpy(buffer, "ON");
    }
    else
    {
        digitalWrite(10, LOW);
        strcpy(buffer, "OFF");
    }
    btn->setText(buffer);
    
}
/**
 * Button to return the response.
 * 
 * @param ptr - the parameter was transmitted to pop event function pointer. 
 * 
 */
void b2PopCallback(void *ptr)
{
    NexButton *btn = (NexButton *)ptr;
    memset(buffer, 0, sizeof(buffer));
    btn->getText(buffer, sizeof(buffer));
    if (strcmp(buffer,"ON"))
    {
        digitalWrite(11, HIGH);
        strcpy(buffer, "ON");
     
    }
    else
    {
        digitalWrite(11, LOW);
        strcpy(buffer, "OFF");
    }
    btn->setText(buffer);
    
}
/**
 * Button to return the response.
 * 
 * @param ptr - the parameter was transmitted to pop event function pointer. 
 * 
 */
void b3PopCallback(void *ptr)
{
    NexButton *btn = (NexButton *)ptr;
    memset(buffer, 0, sizeof(buffer));
    btn->getText(buffer, sizeof(buffer));
    if (strcmp(buffer,"ON"))
    {
        digitalWrite(12, HIGH);
        strcpy(buffer, "ON");
    }
    else
    {
        digitalWrite(12, LOW);
        strcpy(buffer, "OFF");
    }
    btn->setText(buffer);
    
}

void setup(void)
{
    nexInit();
    b0.attachPop(b0PopCallback, &b0);
    b1.attachPop(b1PopCallback, &b1);
    b2.attachPop(b2PopCallback, &b2);
    b3.attachPop(b3PopCallback, &b3);
//setting port OUTPUT
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
//initializing  port 
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
}

void loop(void)
{
    nexLoop(nex_Listen_List);
}
