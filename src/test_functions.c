//------------------------------------------------
// #### PROJECT: O3 TREATMENT - Custom Board #####
// ## Internal Test Functions Module
// ##
// ## @Author: Med
// ## @Editor: Emacs - ggtags
// ## @TAGS:   Global
// ##
// #### TEST_FUNCTIONS.C #########################
//------------------------------------------------

// Includes --------------------------------------------------------------------
#include "test_functions.h"
#include "hard.h"
#include "tim.h"
// #include "gpio.h"
// #include "usart.h"
// #include "dmx_receiver.h"

#include <stdio.h>


// Externals -------------------------------------------------------------------
// extern volatile unsigned char dmx_buff_data[];
extern volatile unsigned char Packet_Detected_Flag;
extern volatile unsigned short DMX_channel_selected;
extern volatile unsigned char DMX_channel_quantity;

// Globals ---------------------------------------------------------------------


// Module Private Types & Macros -----------------------------------------------


// Module Private Functions ----------------------------------------------------
void TF_Led (void);
void TF_Led_Dmx (void);
void TF_Tim3 (void);
void TF_Tim3_On_Off (void);
void TF_Dmx_Packet (void);
void TF_Dmx_Packet_Data (void);


// Module Functions ------------------------------------------------------------
void TF_Hardware_Tests (void)
{
    // TF_Led();    //simple led functionality
    TF_Led_Dmx ();
    // TF_Tim3 ();
    // TF_Tim3_On_Off ();    

    // TF_Dmx_Packet ();
    // TF_Dmx_Packet_Data ();
    
}


void TF_Led (void)
{
    while (1)
    {
        if (Led_Is_On())
            Led_Off();
        else
            Led_On();

        Wait_ms(1000);
    }
}


void TF_Led_Dmx (void)
{
    while (1)
    {
        if (Led_Dmx_Is_On())
        {
            // Led_On();
            Led_Dmx_Off ();
        }
        else
        {
            // Led_Off();
            Led_Dmx_On ();
        }

        Wait_ms(250);
    }
}


void TF_Tim3 (void)
{
    TIM3_Init ();

    TIM3_Channels_Update (960 >> 1);

    while (1);
}


void TF_Tim3_On_Off (void)
{
    TIM3_Init ();

    while (1)
    {
        Led_On();
        TIM3_Channels_Update (960 >> 1);
        Wait_ms(5000);
        
        Led_Off();
        TIM3_Channels_Update (0);
        Wait_ms(5000);
    }
}



// void TF_Dmx_Packet (void)
// {
//     Usart1Config();
//     TIM_14_Init();
//     DMX_channel_selected = 1;
//     DMX_channel_quantity = 2;
//     DMX_EnableRx();

//     while (1)
//     {
//         if (Packet_Detected_Flag)
//         {
//             Packet_Detected_Flag = 0;
//             LED_ON;
//             Wait_ms(2);
//             LED_OFF;
//         }
//     }
// }


// void TF_Dmx_Packet_Data (void)
// {
//     // Init LCD
//     LCD_UtilsInit();
//     CTRL_BKL_ON;
//     LCD_ClearScreen();
//     Wait_ms(1000);

//     // Init DMX
//     Usart1Config();
//     TIM_14_Init();
//     DMX_channel_selected = 1;
//     DMX_channel_quantity = 2;
//     DMX_EnableRx();

//     unsigned char dmx_data1 = 0;
//     unsigned char dmx_data2 = 0;    

//     while (1)
//     {
//         if (Packet_Detected_Flag)
//         {
//             Packet_Detected_Flag = 0;
//             LED_ON;

//             if (dmx_buff_data[0] == 0)
//             {
//                 char s_lcd [20] = { 0 };

//                 if (dmx_data1 != dmx_buff_data[1])
//                 {
//                     sprintf(s_lcd, "ch1: %03d", dmx_buff_data[1]);
//                     LCD_Writel1(s_lcd);
//                     dmx_data1 = dmx_buff_data[1];
//                 }

//                 if (dmx_data2 != dmx_buff_data[2])
//                 {
//                     sprintf(s_lcd, "ch2: %03d", dmx_buff_data[2]);
//                     LCD_Writel2(s_lcd);
//                     dmx_data2 = dmx_buff_data[2];
//                 }
//             }
            
//             LED_OFF;
//         }
//     }
// }



//--- end of file ---//
