// Incluir la libreria de la direccion https://www.itead.cc/blog/nextion-tutorial-based-on-nextion-arduino-library, del link del literal 1.
// Modificar la carpeta NexConfig como dice en la pagina del link arriba.

#include "NexButton.h"
#include "NexText.h"

NexButton a0 = NexButton(1, 3, "a0");
NexButton a1 = NexButton(1, 4, "a1");
NexButton a2 = NexButton(1, 5, "a2");
NexButton a3 = NexButton(1, 6, "a3");

char buffer[10] = {0};

NexTouch *nex_Listen_List[] = 
{
    &a0,
    &a1,
    &a2,
    &a3,
    NULL
};

/**
 * Button to return the response.
 * 
 * @param ptr - the parameter was transmitted to pop event function pointer. 
 * 
 */
void a0PopCallback(void *ptr)
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
void a1PopCallback(void *ptr)
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
void a2PopCallback(void *ptr)
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
void a3PopCallback(void *ptr)
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
    a0.attachPop(a0PopCallback, &a0);
    a1.attachPop(a1PopCallback, &a1);
    a2.attachPop(a2PopCallback, &a2);
    a3.attachPop(a3PopCallback, &a3);
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
