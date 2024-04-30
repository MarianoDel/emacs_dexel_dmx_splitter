//---------------------------------------------
// ## @Author: Med
// ## @Editor: Emacs - ggtags
// ## @TAGS:   Global
// ## @CPU:    STM32F030
// ##
// #### TIM.H #################################
//---------------------------------------------
#ifndef _TIM_H_
#define _TIM_H_


// Exported Types Constants and Macros -----------------------------------------


// Module Exported Functions -----------------------------------------
void TIM_1_Init(void);

void TIM3_Init(void);
void TIM3_Channels_Update (unsigned short a);
void TIM3_IRQHandler (void);

void TIM_6_Init (void);
void TIM14_IRQHandler (void);
void TIM_14_Init(void);
void TIM16_IRQHandler (void);
void TIM16_Init(void);
void TIM16Enable (void);
void TIM16Disable (void);
void TIM17_IRQHandler (void);
void TIM_17_Init(void);
void Update_TIM1_CH1 (unsigned short);
void Update_TIM1_CH2 (unsigned short);
void Update_TIM1_CH4 (unsigned short);
void Update_TIM3_CH1 (unsigned short);
void Update_TIM3_CH2 (unsigned short);
void Update_TIM3_CH3 (unsigned short);
void Update_TIM3_CH4 (unsigned short);

void Wait_ms (unsigned short wait);

#endif    /* _TIM_H_ */

//--- end of file ---//
