//----------------------------------------------
// #### DEXEL 2CH PROJECT - Custom Board ####
// ##
// ## @Author: Med
// ## @Editor: Emacs - ggtags
// ## @TAGS:   Global
// ##
// #### HARD.H #################################
//----------------------------------------------
#ifndef _HARD_H_
#define _HARD_H_

#include "stm32f0xx.h"


//-- Defines For Configuration -------------------
//---- Configuration for Hardware Versions -------


//---- Features Configuration --------------------


//---- End of Features Configuration -------------

//--- Sanity Checks ------------------------------
//--- End of Sanity Checks -----------------------

// Exported Pinout Names -------------------------------------------------------

//GPIOF pin0
//GPIOF pin1    NC

//GPIOA pin0    
//GPIOA pin1    
//GPIOA pin2    
//GPIOA pin3    NC

//GPIOA pin4
#define LED_DMX    ((GPIOA->ODR & 0x0010) != 0)
#define LED_DMX_ON    (GPIOA->BSRR = 0x00000010)
#define LED_DMX_OFF    (GPIOA->BSRR = 0x00100000)

//GPIOA pin5    NC

//GPIOA pin6    TIM3_CH1
//GPIOA pin7    TIM3_CH2
//GPIOB pin0    TIM3_CH3
//GPIOB pin1    TIM3_CH4

//GPIOA pin8    Exti input
#define DMX_INPUT    ((GPIOA->IDR & 0x0100) != 0)

//GPIOA pin9    NC

//GPIOA pin10    Usart1 Rx

//GPIOA pin11
//GPIOA pin12
//GPIOA pin13
//GPIOA pin14    NC

//GPIOA pin15    
#define LED    ((GPIOA->ODR & 0x8000) != 0)
#define LED_ON    (GPIOA->BSRR = 0x00008000)
#define LED_OFF    (GPIOA->BSRR = 0x80000000)

//GPIOB pin3
//GPIOB pin4
//GPIOB pin5
//GPIOB pin4
//GPIOB pin5
//GPIOB pin6
//GPIOB pin7    NC


// Exported Types & Macros -----------------------------------------------------


//--- Stringtify Utils -----------------------
#define str_macro(s) #s


// Module Exported Functions ---------------------------------------------------
void Led_On (void);
void Led_Off (void);
unsigned char Led_Is_On (void);
void Led_Dmx_On (void);
void Led_Dmx_Off (void);
unsigned char Led_Dmx_Is_On (void);

    
#endif /* _HARD_H_ */

//--- end of file ---//

