//----------------------------------------------------
// #### DEXEL DMX SPLITTER PROJECT - Custom Board ####
// ##
// ## @Author: Med
// ## @Editor: Emacs - ggtags
// ## @TAGS:   Global
// ##
// #### MAIN.C #######################################
//----------------------------------------------------

// Includes --------------------------------------------------------------------
#include "hard.h"
#include "stm32f0xx.h"

#include "gpio.h"
#include "tim.h"
#include "usart.h"

#include "test_functions.h"
#include "dmx_receiver.h"

#include <stdio.h>
#include <string.h>


// Module Types Constants and Macros -------------------------------------------
typedef enum {
    MAIN_INIT,
    MAIN_WAIT_DMX_PSU_OFF,
    MAIN_DMX_PSU_ON
    
} main_state_e;


// Externals -------------------------------------------------------------------
// for the dmx
volatile unsigned char dmx_buff_data[SIZEOF_DMX_BUFFER_DATA];
volatile unsigned char Packet_Detected_Flag = 0;
volatile unsigned short DMX_channel_selected = 0;
volatile unsigned char DMX_channel_quantity = 0;
volatile unsigned char dmx_receive_flag = 0;


// Globals ---------------------------------------------------------------------
//-- Timers globals ----------------------------------
volatile unsigned short timer_standby = 0;
volatile unsigned short timer_dmx_led = 0;
volatile unsigned short wait_ms_var = 0;



// Module Private Functions ----------------------------------------------------
void TimingDelay_Decrement(void);
void EXTI4_15_IRQHandler(void);
void SysTickError (void);


// Module Functions ------------------------------------------------------------
int main(void)
{
    //GPIO Configuration.
    GPIO_Config();

    //Systick Timer
    if (SysTick_Config(48000))
        SysTickError();

    // Begin Hardware Tests - check test_functions module
    // TF_Hardware_Tests ();
    // End Hard Tests -------------------------------

    // Hardware Inits. ---------------------------    

    // Tim3 for psu
    TIM3_Init ();
    
    // Usart and Timer for DMX
    Usart1Config ();
    TIM_14_Init ();
    DMX_DisableRx ();

    
    // Production Program ---------------------------
    main_state_e main_state = MAIN_INIT;
    unsigned char packet_cnt = 0;
    
    while (1)
    {
        switch (main_state)
        {
        case MAIN_INIT:
            // led always on if power
            // Led_On ();
            Led_Dmx_On ();

            // reception variables
            DMX_channel_selected = 1;
            DMX_channel_quantity = 1;

            // packet reception enable
            DMX_EnableRx();

            main_state++;
            break;

        case MAIN_WAIT_DMX_PSU_OFF:

            if (Packet_Detected_Flag)
            {
                Packet_Detected_Flag = 0;
                packet_cnt++;
                timer_standby = 2000;
            }

            if (!timer_standby)
            {
                packet_cnt = 0;
            }
            else if (packet_cnt > 5)    // 5 packets in 2 secs
            {
                main_state = MAIN_DMX_PSU_ON;

                // enable psu
                TIM3_Channels_Update (960 >> 1);
            }
            break;

        case MAIN_DMX_PSU_ON:
            if (Packet_Detected_Flag)
            {
                Packet_Detected_Flag = 0;
                timer_standby = 2000;
            }

            if (!timer_dmx_led)
            {
                timer_dmx_led = 250;

                if (Led_Dmx_Is_On())
                    Led_Dmx_Off ();
                else
                    Led_Dmx_On ();
            }
            
            if (!timer_standby)    // no packets in 2secs
            {
                main_state = MAIN_WAIT_DMX_PSU_OFF;

                // disable psu
                TIM3_Channels_Update (0);

                // led dmx always on
                Led_Dmx_On ();
            }
            break;

        default:
            main_state = MAIN_INIT;
            break;
        }
        
    }    //end of while 1

    return 0;
}

//--- End of Main ---//


void TimingDelay_Decrement(void)
{
    if (wait_ms_var)
        wait_ms_var--;

    if (timer_standby)
        timer_standby--;

    if (timer_dmx_led)
        timer_dmx_led--;
    
    DMX_Int_Millis_Handler();
    
}


void EXTI4_15_IRQHandler(void)
{
    DMX_Int_Break_Handler();
    EXTI->PR |= 0x00000100;    //PA8
}


void SysTickError (void)
{
    //Capture systick error...
    while (1)
    {
        if (LED)
            LED_OFF;
        else
            LED_ON;

        for (unsigned char i = 0; i < 255; i++)
        {
            asm ("nop \n\t"
                 "nop \n\t"
                 "nop \n\t" );
        }
    }
}

//--- end of file ---//

