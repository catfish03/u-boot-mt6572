#ifndef _DT_BINDINGS_CLK_MT6580_H
#define _DT_BINDINGS_CLK_MT6580_H

/* Clocks */
#define CLK_APMIXED_ARMPLL 1
#define CLK_APMIXED_MAINPLL 2
#define CLK_APMIXED_UNIVPLL 3
#define CLK_APMIXED_MCUPLL 4
#define CLK_APMIXED_WHPLL 5
#define CLK_APMIXED_WPLL 6

#define CLK_TOP_MPLL 7
#define CLK_TOP_MPLL_D6 8
#define CLK_TOP_MPLL_D7 9
#define CLK_TOP_MPLL_D8 10
#define CLK_TOP_MPLL_D10 11
#define CLK_TOP_MPLL_D12 12

#define CLK_TOP_UPLL 13
#define CLK_TOP_UPLL_D6 14
#define CLK_TOP_UPLL_D7 15
#define CLK_TOP_UPLL_D12 16
#define CLK_TOP_UPLL_D24 17

/* Muxes */
#define CLK_TOP_UART0_SEL 17
#define CLK_TOP_MSDC0_SEL 18
#define CLK_TOP_UART1_SEL 19
#define CLK_TOP_MSDC1_SEL 20
#define CLK_TOP_MMSYS_PWM_SEL 21

/* Gates */
#define CLK_TOP_MMSYS_PWM 0
#define CLK_TOP_I2C0 1
#define CLK_TOP_I2C1 2
#define CLK_TOP_UART0 3
#define CLK_TOP_UART1 4
#define CLK_TOP_I2C2 5
#define CLK_TOP_MSDC0 6
#define CLK_TOP_MSDC1 7
#define CLK_TOP_APXGPT 8

#define CLK_MMSYS_PWM_MM 0
#define CLK_MMSYS_PWM_26M 1


#endif /* _DT_BINDINGS_CLK_MT6580_H */
