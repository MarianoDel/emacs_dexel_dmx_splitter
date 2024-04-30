//----------------------------------------------
// #### DEXEL 2CH PROJECT - Custom Board ####
// ##
// ## @Author: Med
// ## @Editor: Emacs - ggtags
// ## @TAGS:   Global
// ##
// #### HARD.C #################################
//----------------------------------------------
#include "hard.h"
#include "stm32f0xx.h"


// Module Private Types & Macros -----------------------------------------------


// Externals -------------------------------------------------------------------


// Globals ---------------------------------------------------------------------


// Module Private Functions ----------------------------------------------------


// Module Functions ------------------------------------------------------------
void Led_On (void)
{
    LED_ON;
}


void Led_Off (void)
{
    LED_OFF;
}


unsigned char Led_Is_On (void)
{
    return LED;
}


void Led_Dmx_On (void)
{
    LED_DMX_ON;
}


void Led_Dmx_Off (void)
{
    LED_DMX_OFF;
}


unsigned char Led_Dmx_Is_On (void)
{
    return LED_DMX;
}



//--- end of file ---//


