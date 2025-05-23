#include <dm.h>
#include "pinctrl-mtk-common.h"

#define PIN_FIELD_GPIO(_s_pin, _e_pin, _s_addr, _x_addrs, _s_bit, _x_bits) \
  PIN_FIELD_BASE_CALC(_s_pin, _e_pin, GPIO_BASE, _s_addr, _x_addrs, \
                      _s_bit, _x_bits, 32, 0)

#define PIN_FIELD_BASE(_s_pin, _e_pin, _i_base, _s_addr, _x_addrs, _s_bit, \
          _x_bits)\
  PIN_FIELD_BASE_CALC(_s_pin, _e_pin, _i_base, _s_addr, _x_addrs, _s_bit, \
                      _x_bits, 32, 0)

enum {
  GPIO_BASE,
  IOCFG_T_BASE,
  IOCFG_B_BASE,
  IOCFG_L_BASE,
  IOCFG_R_BASE,
};

static const char *const mt6572_pinctrl_register_base_names[] = {
  "gpio", "iocfg_t",
  "iocfg_b", "iocfg_l", "iocfg_r",
};

static const struct mtk_pin_desc mt6572_pins[] = {
  MTK_PIN(0,  "GPIO0",      DRV_FIXED),
  MTK_PIN(1,  "GPIO1",      DRV_FIXED),
  MTK_PIN(2,  "GPIO2",      DRV_FIXED),
  MTK_PIN(3,  "GPIO3",      DRV_FIXED),
  MTK_PIN(4,  "GPIO4",      DRV_FIXED),
  MTK_PIN(5,  "GPIO5",      DRV_FIXED),
  MTK_PIN(6,  "GPIO6",      DRV_FIXED),
  MTK_PIN(7,  "GPIO7",      DRV_FIXED),
  MTK_PIN(8,  "GPIO8",      DRV_FIXED),
  MTK_PIN(9,  "GPIO9",      DRV_GRP0 ),
  MTK_PIN(10, "GPIO10",     DRV_GRP0 ),
  MTK_PIN(11, "GPIO11",     DRV_GRP0 ),
  MTK_PIN(12, "GPIO12",     DRV_GRP0 ),
  MTK_PIN(13, "GPIO13",     DRV_GRP0 ),
  MTK_PIN(14, "GPIO14",     DRV_GRP0 ),
  MTK_PIN(15, "GPIO15",     DRV_GRP0 ),
  MTK_PIN(16, "GPIO16",     DRV_GRP0 ),
  MTK_PIN(17, "EINT1",      DRV_GRP0 ),
  MTK_PIN(18, "GPIO18",     DRV_GRP0 ),
  MTK_PIN(19, "GPIO19",     DRV_GRP0 ),
  MTK_PIN(20, "GPIO20",     DRV_GRP0 ),
  MTK_PIN(21, "GPIO21",     DRV_GRP0 ),
  MTK_PIN(22, "GPIO22",     DRV_FIXED),
  MTK_PIN(23, "GPIO23",     DRV_FIXED),
  MTK_PIN(24, "GPIO24",     DRV_FIXED),
  MTK_PIN(25, "GPIO25",     DRV_FIXED),
  MTK_PIN(26, "GPIO26",     DRV_FIXED),
  MTK_PIN(27, "GPIO27",     DRV_FIXED),
  MTK_PIN(28, "GPIO28",     DRV_FIXED),
  MTK_PIN(29, "GPIO29",     DRV_FIXED),
  MTK_PIN(30, "GPIO30",     DRV_FIXED),
  MTK_PIN(31, "GPIO31",     DRV_FIXED),
  MTK_PIN(32, "GPIO32",     DRV_FIXED),
  MTK_PIN(33, "GPIO33",     DRV_FIXED),
  MTK_PIN(34, "GPIO34",     DRV_FIXED),
  MTK_PIN(35, "GPIO35",     DRV_FIXED),
  MTK_PIN(36, "GPIO36",     DRV_FIXED),
  MTK_PIN(37, "GPIO37",     DRV_FIXED),
  MTK_PIN(38, "GPIO38",     DRV_FIXED),
  MTK_PIN(39, "GPIO39",     DRV_FIXED),
  MTK_PIN(40, "GPIO40",     DRV_FIXED),
  MTK_PIN(41, "MSDC0_CLK",  DRV_GRP4 ),
  MTK_PIN(42, "MSDC0_CMD",  DRV_GRP4 ),
  MTK_PIN(43, "MSDC0_DAT0", DRV_GRP4 ),
  MTK_PIN(44, "MSDC0_DAT1", DRV_GRP4 ),
  MTK_PIN(45, "MSDC0_DAT2", DRV_GRP4 ),
  MTK_PIN(46, "MSDC0_DAT3", DRV_GRP4 ),
  MTK_PIN(47, "MSDC0_DAT4", DRV_GRP4 ),
  MTK_PIN(48, "MSDC0_DAT5", DRV_GRP4 ),
  MTK_PIN(49, "MSDC0_DAT6", DRV_GRP4 ),
  MTK_PIN(50, "MSDC0_DAT7", DRV_GRP4 ),
  MTK_PIN(51, "MSDC0_RSTB", DRV_GRP4 ),
  MTK_PIN(52, "MSDC1_CLK",  DRV_GRP2 ),
  MTK_PIN(53, "MSDC1_CMD",  DRV_GRP2 ),
  MTK_PIN(54, "MSDC1_DAT3", DRV_GRP2 ),
  MTK_PIN(55, "MSDC1_DAT2", DRV_GRP2 ),
  MTK_PIN(56, "MSDC1_DAT1", DRV_GRP2 ),
  MTK_PIN(57, "MSDC1_DAT0", DRV_GRP2 ),
  MTK_PIN(58, "GPIO58",     DRV_FIXED),
  MTK_PIN(59, "GPIO59",     DRV_FIXED),
  MTK_PIN(60, "GPIO60",     DRV_FIXED),
  MTK_PIN(61, "GPIO61",     DRV_FIXED),
  MTK_PIN(62, "GPIO62",     DRV_FIXED),
  MTK_PIN(63, "GPIO63",     DRV_FIXED),
  MTK_PIN(64, "KPCOL0",     DRV_GRP2 ),
  MTK_PIN(65, "KPROW1",     DRV_GRP2 ),
  MTK_PIN(66, "DISP_PWM",   DRV_FIXED),
  MTK_PIN(67, "KPCOL1",     DRV_GRP2 ),
  MTK_PIN(68, "DSI_TE",     DRV_FIXED),
  MTK_PIN(69, "KPROW0",     DRV_GRP2 ),
  MTK_PIN(70, "LCM_RST",    DRV_GRP0 ),
  MTK_PIN(71, "GPIO71",     DRV_FIXED),
  MTK_PIN(72, "GPIO72",     DRV_FIXED),
  MTK_PIN(73, "GPIO73",     DRV_FIXED),
  MTK_PIN(74, "GPIO74",     DRV_FIXED),
  MTK_PIN(75, "GPIO75",     DRV_FIXED),
  MTK_PIN(76, "GPIO76",     DRV_FIXED),
  MTK_PIN(77, "URXD1",      DRV_GRP2 ),
  MTK_PIN(78, "UTXD1",      DRV_GRP2 ),
  MTK_PIN(79, "VM1",        DRV_GRP0 ),
  MTK_PIN(80, "VM0",        DRV_GRP0 ),
  MTK_PIN(81, "BPI_BUS11",  DRV_GRP0 ),
  MTK_PIN(82, "BPI_BUS10",  DRV_GRP0 ),
  MTK_PIN(83, "BPI_BUS9",   DRV_GRP0 ),
  MTK_PIN(84, "BPI_BUS8",   DRV_GRP0 ),
  MTK_PIN(85, "BPI_BUS7",   DRV_GRP0 ),
  MTK_PIN(86, "BPI_BUS6",   DRV_GRP0 ),
  MTK_PIN(87, "BPI_BUS5",   DRV_GRP0 ),
  MTK_PIN(88, "BPI_BUS4",   DRV_GRP0 ),
  MTK_PIN(89, "BPI_BUS3",   DRV_GRP0 ),
  MTK_PIN(90, "BPI_BUS2",   DRV_GRP0 ),
  MTK_PIN(91, "BPI_BUS1",   DRV_GRP0 ),
  MTK_PIN(92, "BPI_BUS0",   DRV_GRP0 ),
};


static const struct mtk_pin_field_calc mt6572_pin_mode_range[] = {
  PIN_FIELD_GPIO(0, 92, 0x54, 0x10, 0, 4),
};

static const struct mtk_pin_field_calc mt6572_pin_dir_range[] = {
  PIN_FIELD_GPIO(0, 92, 0x0, 0xc, 0, 1),
};

static const struct mtk_pin_field_calc mt6572_pin_di_range[] = {
  PIN_FIELD_GPIO(0, 92, 0x48, 0x4, 0, 1),
};

static const struct mtk_pin_field_calc mt6572_pin_do_range[] = {
  PIN_FIELD_GPIO(0, 92, 0x24, 0xc, 0, 1),
};

static const struct mtk_pin_field_calc mt6572_pin_smt_range[] = {
  PIN_FIELD_BASE(0, 0, IOCFG_T_BASE, 0x054, 0xc, 0, 1),
  PIN_FIELD_BASE(1, 1, IOCFG_T_BASE, 0x054, 0xc, 1, 1),
  PIN_FIELD_BASE(2, 2, IOCFG_T_BASE, 0x054, 0xc, 2, 1),
  PIN_FIELD_BASE(3, 3, IOCFG_T_BASE, 0x054, 0xc, 3, 1),
  PIN_FIELD_BASE(4, 4, IOCFG_R_BASE, 0x054, 0xc, 6, 1),
  PIN_FIELD_BASE(5, 5, IOCFG_R_BASE, 0x054, 0xc, 7, 1),
  PIN_FIELD_BASE(6, 6, IOCFG_R_BASE, 0x054, 0xc, 8, 1),
  PIN_FIELD_BASE(7, 7, IOCFG_R_BASE, 0x054, 0xc, 9, 1),
  PIN_FIELD_BASE(8, 8, IOCFG_R_BASE, 0x054, 0xc, 10, 1),
  PIN_FIELD_BASE(9, 9, IOCFG_B_BASE, 0x054, 0xc, 2, 1),
  PIN_FIELD_BASE(10, 10, IOCFG_B_BASE, 0x054, 0xc, 3, 1),
  PIN_FIELD_BASE(11, 11, IOCFG_B_BASE, 0x054, 0xc, 4, 1),
  PIN_FIELD_BASE(12, 12, IOCFG_B_BASE, 0x054, 0xc, 5, 1),
  PIN_FIELD_BASE(13, 13, IOCFG_B_BASE, 0x054, 0xc, 6, 1),
  PIN_FIELD_BASE(14, 14, IOCFG_B_BASE, 0x054, 0xc, 7, 1),
  PIN_FIELD_BASE(15, 15, IOCFG_B_BASE, 0x054, 0xc, 8, 1),
  PIN_FIELD_BASE(16, 16, IOCFG_B_BASE, 0x054, 0xc, 9, 1),
  PIN_FIELD_BASE(17, 17, IOCFG_B_BASE, 0x054, 0xc, 21, 1),
  PIN_FIELD_BASE(18, 18, IOCFG_B_BASE, 0x054, 0xc, 22, 1),
  PIN_FIELD_BASE(19, 19, IOCFG_B_BASE, 0x054, 0xc, 23, 1),
  PIN_FIELD_BASE(20, 20, IOCFG_B_BASE, 0x054, 0xc, 24, 1),
  PIN_FIELD_BASE(21, 21, IOCFG_B_BASE, 0x054, 0xc, 25, 1),
  PIN_FIELD_BASE(22, 22, IOCFG_L_BASE, 0x030, 0xc, 0, 1),
  PIN_FIELD_BASE(23, 23, IOCFG_L_BASE, 0x030, 0xc, 1, 1),
  PIN_FIELD_BASE(24, 24, IOCFG_L_BASE, 0x030, 0xc, 2, 1),
  PIN_FIELD_BASE(25, 25, IOCFG_L_BASE, 0x030, 0xc, 3, 1),
  PIN_FIELD_BASE(26, 26, IOCFG_L_BASE, 0x030, 0xc, 5, 1),
  PIN_FIELD_BASE(27, 27, IOCFG_L_BASE, 0x030, 0xc, 6, 1),
  PIN_FIELD_BASE(28, 28, IOCFG_L_BASE, 0x030, 0xc, 7, 1),
  PIN_FIELD_BASE(29, 29, IOCFG_L_BASE, 0x030, 0xc, 9, 1),
  PIN_FIELD_BASE(30, 30, IOCFG_L_BASE, 0x030, 0xc, 11, 1),
  PIN_FIELD_BASE(31, 31, IOCFG_L_BASE, 0x030, 0xc, 10, 1),
  PIN_FIELD_BASE(32, 32, IOCFG_L_BASE, 0x030, 0xc, 8, 1),
  PIN_FIELD_BASE(33, 33, IOCFG_L_BASE, 0x030, 0xc, 4, 1),
  PIN_FIELD_BASE(34, 34, IOCFG_L_BASE, 0x030, 0xc, 13, 1),
  PIN_FIELD_BASE(41, 41, IOCFG_B_BASE, 0x054, 0xc, 18, 1),
  PIN_FIELD_BASE(42, 42, IOCFG_B_BASE, 0x054, 0xc, 20, 1),
  PIN_FIELD_BASE(43, 43, IOCFG_B_BASE, 0x054, 0xc, 17, 1),
  PIN_FIELD_BASE(44, 44, IOCFG_B_BASE, 0x054, 0xc, 16, 1),
  PIN_FIELD_BASE(45, 45, IOCFG_B_BASE, 0x054, 0xc, 15, 1),
  PIN_FIELD_BASE(46, 46, IOCFG_B_BASE, 0x054, 0xc, 14, 1),
  PIN_FIELD_BASE(47, 47, IOCFG_B_BASE, 0x054, 0xc, 13, 1),
  PIN_FIELD_BASE(48, 48, IOCFG_B_BASE, 0x054, 0xc, 12, 1),
  PIN_FIELD_BASE(49, 49, IOCFG_B_BASE, 0x054, 0xc, 11, 1),
  PIN_FIELD_BASE(50, 50, IOCFG_B_BASE, 0x054, 0xc, 10, 1),
  PIN_FIELD_BASE(51, 51, IOCFG_B_BASE, 0x054, 0xc, 19, 1),
  PIN_FIELD_BASE(52, 52, IOCFG_R_BASE, 0x054, 0xc, 0, 1),
  PIN_FIELD_BASE(53, 53, IOCFG_R_BASE, 0x054, 0xc, 1, 1),
  PIN_FIELD_BASE(54, 54, IOCFG_R_BASE, 0x054, 0xc, 2, 1),
  PIN_FIELD_BASE(55, 55, IOCFG_R_BASE, 0x054, 0xc, 3, 1),
  PIN_FIELD_BASE(56, 56, IOCFG_R_BASE, 0x054, 0xc, 4, 1),
  PIN_FIELD_BASE(57, 57, IOCFG_R_BASE, 0x054, 0xc, 5, 1),
  PIN_FIELD_BASE(58, 58, IOCFG_R_BASE, 0x054, 0xc, 14, 1),
  PIN_FIELD_BASE(59, 59, IOCFG_T_BASE, 0x054, 0xc, 6, 1),
  PIN_FIELD_BASE(60, 60, IOCFG_T_BASE, 0x054, 0xc, 8, 1),
  PIN_FIELD_BASE(61, 61, IOCFG_R_BASE, 0x054, 0xc, 15, 1),
  PIN_FIELD_BASE(62, 62, IOCFG_T_BASE, 0x054, 0xc, 9, 1),
  PIN_FIELD_BASE(63, 63, IOCFG_T_BASE, 0x054, 0xc, 11, 1),
  PIN_FIELD_BASE(64, 64, IOCFG_T_BASE, 0x054, 0xc, 4, 1),
  PIN_FIELD_BASE(65, 65, IOCFG_T_BASE, 0x054, 0xc, 5, 1),
  PIN_FIELD_BASE(66, 66, IOCFG_R_BASE, 0x054, 0xc, 11, 1),
  PIN_FIELD_BASE(67, 67, IOCFG_T_BASE, 0x054, 0xc, 7, 1),
  PIN_FIELD_BASE(68, 68, IOCFG_R_BASE, 0x054, 0xc, 12, 1),
  PIN_FIELD_BASE(69, 69, IOCFG_T_BASE, 0x054, 0xc, 10, 1),
  PIN_FIELD_BASE(70, 70, IOCFG_R_BASE, 0x054, 0xc, 13, 1),
  PIN_FIELD_BASE(71, 71, IOCFG_R_BASE, 0x054, 0xc, 16, 1),
  PIN_FIELD_BASE(72, 72, IOCFG_R_BASE, 0x054, 0xc, 17, 1),
  PIN_FIELD_BASE(73, 73, IOCFG_R_BASE, 0x054, 0xc, 18, 1),
  PIN_FIELD_BASE(74, 74, IOCFG_R_BASE, 0x054, 0xc, 19, 1),
  PIN_FIELD_BASE(75, 75, IOCFG_R_BASE, 0x054, 0xc, 20, 1),
  PIN_FIELD_BASE(76, 76, IOCFG_R_BASE, 0x054, 0xc, 21, 1),
  PIN_FIELD_BASE(77, 77, IOCFG_B_BASE, 0x054, 0xc, 0, 1),
  PIN_FIELD_BASE(78, 78, IOCFG_B_BASE, 0x054, 0xc, 1, 1),
  PIN_FIELD_BASE(79, 79, IOCFG_T_BASE, 0x054, 0xc, 12, 1),
  PIN_FIELD_BASE(80, 80, IOCFG_T_BASE, 0x054, 0xc, 13, 1),
  PIN_FIELD_BASE(81, 81, IOCFG_T_BASE, 0x054, 0xc, 14, 1),
  PIN_FIELD_BASE(82, 82, IOCFG_T_BASE, 0x054, 0xc, 15, 1),
  PIN_FIELD_BASE(83, 83, IOCFG_T_BASE, 0x054, 0xc, 16, 1),
  PIN_FIELD_BASE(84, 84, IOCFG_T_BASE, 0x054, 0xc, 17, 1),
  PIN_FIELD_BASE(85, 85, IOCFG_T_BASE, 0x054, 0xc, 18, 1),
  PIN_FIELD_BASE(86, 86, IOCFG_T_BASE, 0x054, 0xc, 19, 1),
  PIN_FIELD_BASE(87, 87, IOCFG_T_BASE, 0x054, 0xc, 20, 1),
  PIN_FIELD_BASE(88, 88, IOCFG_T_BASE, 0x054, 0xc, 21, 1),
  PIN_FIELD_BASE(89, 89, IOCFG_T_BASE, 0x054, 0xc, 22, 1),
  PIN_FIELD_BASE(90, 90, IOCFG_T_BASE, 0x054, 0xc, 23, 1),
  PIN_FIELD_BASE(91, 91, IOCFG_T_BASE, 0x054, 0xc, 24, 1),
  PIN_FIELD_BASE(92, 92, IOCFG_T_BASE, 0x054, 0xc, 25, 1),
};

static const struct mtk_pin_field_calc mt6572_pin_ies_range[] = {  
  PIN_FIELD_BASE(0, 0, IOCFG_T_BASE, 0x03C, 0xc, 0, 1),
  PIN_FIELD_BASE(1, 1, IOCFG_T_BASE, 0x03C, 0xc, 1, 1),
  PIN_FIELD_BASE(2, 2, IOCFG_T_BASE, 0x03C, 0xc, 2, 1),
  PIN_FIELD_BASE(3, 3, IOCFG_T_BASE, 0x03C, 0xc, 3, 1),
  PIN_FIELD_BASE(4, 4, IOCFG_R_BASE, 0x03C, 0xc, 6, 1),
  PIN_FIELD_BASE(5, 5, IOCFG_R_BASE, 0x03C, 0xc, 7, 1),
  PIN_FIELD_BASE(6, 6, IOCFG_R_BASE, 0x03C, 0xc, 8, 1),
  PIN_FIELD_BASE(7, 7, IOCFG_R_BASE, 0x03C, 0xc, 9, 1),
  PIN_FIELD_BASE(8, 8, IOCFG_R_BASE, 0x03C, 0xc, 10, 1),
  PIN_FIELD_BASE(9, 9, IOCFG_B_BASE, 0x03C, 0xc, 2, 1),
  PIN_FIELD_BASE(10, 10, IOCFG_B_BASE, 0x03C, 0xc, 3, 1),
  PIN_FIELD_BASE(11, 11, IOCFG_B_BASE, 0x03C, 0xc, 4, 1),
  PIN_FIELD_BASE(12, 12, IOCFG_B_BASE, 0x03C, 0xc, 5, 1),
  PIN_FIELD_BASE(13, 13, IOCFG_B_BASE, 0x03C, 0xc, 6, 1),
  PIN_FIELD_BASE(14, 14, IOCFG_B_BASE, 0x03C, 0xc, 7, 1),
  PIN_FIELD_BASE(15, 15, IOCFG_B_BASE, 0x03C, 0xc, 8, 1),
  PIN_FIELD_BASE(16, 16, IOCFG_B_BASE, 0x03C, 0xc, 9, 1),
  PIN_FIELD_BASE(17, 17, IOCFG_B_BASE, 0x03C, 0xc, 21, 1),
  PIN_FIELD_BASE(18, 18, IOCFG_B_BASE, 0x03C, 0xc, 22, 1),
  PIN_FIELD_BASE(19, 19, IOCFG_B_BASE, 0x03C, 0xc, 23, 1),
  PIN_FIELD_BASE(20, 20, IOCFG_B_BASE, 0x03C, 0xc, 24, 1),
  PIN_FIELD_BASE(21, 21, IOCFG_B_BASE, 0x03C, 0xc, 25, 1),
  PIN_FIELD_BASE(22, 22, IOCFG_L_BASE, 0x018, 0xc, 0, 1),
  PIN_FIELD_BASE(23, 23, IOCFG_L_BASE, 0x018, 0xc, 1, 1),
  PIN_FIELD_BASE(24, 24, IOCFG_L_BASE, 0x018, 0xc, 2, 1),
  PIN_FIELD_BASE(25, 25, IOCFG_L_BASE, 0x018, 0xc, 3, 1),
  PIN_FIELD_BASE(26, 26, IOCFG_L_BASE, 0x018, 0xc, 5, 1),
  PIN_FIELD_BASE(27, 27, IOCFG_L_BASE, 0x018, 0xc, 6, 1),
  PIN_FIELD_BASE(28, 28, IOCFG_L_BASE, 0x018, 0xc, 7, 1),
  PIN_FIELD_BASE(29, 29, IOCFG_L_BASE, 0x018, 0xc, 9, 1),
  PIN_FIELD_BASE(30, 30, IOCFG_L_BASE, 0x018, 0xc, 11, 1),
  PIN_FIELD_BASE(31, 31, IOCFG_L_BASE, 0x018, 0xc, 10, 1),
  PIN_FIELD_BASE(32, 32, IOCFG_L_BASE, 0x018, 0xc, 8, 1),
  PIN_FIELD_BASE(33, 33, IOCFG_L_BASE, 0x018, 0xc, 4, 1),
  PIN_FIELD_BASE(34, 34, IOCFG_L_BASE, 0x018, 0xc, 13, 1),
  PIN_FIELD_BASE(35, 35, IOCFG_R_BASE, 0xC0 , 0xc, 0, 1),
  PIN_FIELD_BASE(36, 36, IOCFG_R_BASE, 0xC0 , 0xc, 1, 1),
  PIN_FIELD_BASE(37, 37, IOCFG_R_BASE, 0xC0 , 0xc, 2, 1),
  PIN_FIELD_BASE(38, 38, IOCFG_R_BASE, 0xC0 , 0xc, 3, 1),
  PIN_FIELD_BASE(39, 39, IOCFG_R_BASE, 0xC0 , 0xc, 4, 1),
  PIN_FIELD_BASE(40, 40, IOCFG_R_BASE, 0xC0 , 0xc, 5, 1),
  PIN_FIELD_BASE(41, 41, IOCFG_B_BASE, 0x03C, 0xc, 18, 1),
  PIN_FIELD_BASE(42, 42, IOCFG_B_BASE, 0x03C, 0xc, 20, 1),
  PIN_FIELD_BASE(43, 43, IOCFG_B_BASE, 0x03C, 0xc, 17, 1),
  PIN_FIELD_BASE(44, 44, IOCFG_B_BASE, 0x03C, 0xc, 16, 1),
  PIN_FIELD_BASE(45, 45, IOCFG_B_BASE, 0x03C, 0xc, 15, 1),
  PIN_FIELD_BASE(46, 46, IOCFG_B_BASE, 0x03C, 0xc, 14, 1),
  PIN_FIELD_BASE(47, 47, IOCFG_B_BASE, 0x03C, 0xc, 13, 1),
  PIN_FIELD_BASE(48, 48, IOCFG_B_BASE, 0x03C, 0xc, 12, 1),
  PIN_FIELD_BASE(49, 49, IOCFG_B_BASE, 0x03C, 0xc, 11, 1),
  PIN_FIELD_BASE(50, 50, IOCFG_B_BASE, 0x03C, 0xc, 10, 1),
  PIN_FIELD_BASE(51, 51, IOCFG_B_BASE, 0x03C, 0xc, 19, 1),
  PIN_FIELD_BASE(52, 52, IOCFG_R_BASE, 0x03C, 0xc, 0, 1),
  PIN_FIELD_BASE(53, 53, IOCFG_R_BASE, 0x03C, 0xc, 1, 1),
  PIN_FIELD_BASE(54, 54, IOCFG_R_BASE, 0x03C, 0xc, 2, 1),
  PIN_FIELD_BASE(55, 55, IOCFG_R_BASE, 0x03C, 0xc, 3, 1),
  PIN_FIELD_BASE(56, 56, IOCFG_R_BASE, 0x03C, 0xc, 4, 1),
  PIN_FIELD_BASE(57, 57, IOCFG_R_BASE, 0x03C, 0xc, 5, 1),
  PIN_FIELD_BASE(58, 58, IOCFG_R_BASE, 0x03C, 0xc, 14, 1),
  PIN_FIELD_BASE(59, 59, IOCFG_T_BASE, 0x03C, 0xc, 6, 1),
  PIN_FIELD_BASE(60, 60, IOCFG_T_BASE, 0x03C, 0xc, 8, 1),
  PIN_FIELD_BASE(61, 61, IOCFG_R_BASE, 0x03C, 0xc, 15, 1),
  PIN_FIELD_BASE(62, 62, IOCFG_T_BASE, 0x03C, 0xc, 9, 1),
  PIN_FIELD_BASE(63, 63, IOCFG_T_BASE, 0x03C, 0xc, 11, 1),
  PIN_FIELD_BASE(64, 64, IOCFG_T_BASE, 0x03C, 0xc, 4, 1),
  PIN_FIELD_BASE(65, 65, IOCFG_T_BASE, 0x03C, 0xc, 5, 1),
  PIN_FIELD_BASE(66, 66, IOCFG_R_BASE, 0x03C, 0xc, 11, 1),
  PIN_FIELD_BASE(67, 67, IOCFG_T_BASE, 0x03C, 0xc, 7, 1),
  PIN_FIELD_BASE(68, 68, IOCFG_R_BASE, 0x03C, 0xc, 12, 1),
  PIN_FIELD_BASE(69, 69, IOCFG_T_BASE, 0x03C, 0xc, 10, 1),
  PIN_FIELD_BASE(70, 70, IOCFG_R_BASE, 0x03C, 0xc, 13, 1),
  PIN_FIELD_BASE(71, 71, IOCFG_R_BASE, 0x03C, 0xc, 16, 1),
  PIN_FIELD_BASE(72, 72, IOCFG_R_BASE, 0x03C, 0xc, 17, 1),
  PIN_FIELD_BASE(73, 73, IOCFG_R_BASE, 0x03C, 0xc, 18, 1),
  PIN_FIELD_BASE(74, 74, IOCFG_R_BASE, 0x03C, 0xc, 19, 1),
  PIN_FIELD_BASE(75, 75, IOCFG_R_BASE, 0x03C, 0xc, 20, 1),
  PIN_FIELD_BASE(76, 76, IOCFG_R_BASE, 0x03C, 0xc, 21, 1),
  PIN_FIELD_BASE(77, 77, IOCFG_B_BASE, 0x03C, 0xc, 0, 1),
  PIN_FIELD_BASE(78, 78, IOCFG_B_BASE, 0x03C, 0xc, 1, 1),
  PIN_FIELD_BASE(79, 79, IOCFG_T_BASE, 0x03C, 0xc, 12, 1),
  PIN_FIELD_BASE(80, 80, IOCFG_T_BASE, 0x03C, 0xc, 13, 1),
  PIN_FIELD_BASE(81, 81, IOCFG_T_BASE, 0x03C, 0xc, 14, 1),
  PIN_FIELD_BASE(82, 82, IOCFG_T_BASE, 0x03C, 0xc, 15, 1),
  PIN_FIELD_BASE(83, 83, IOCFG_T_BASE, 0x03C, 0xc, 16, 1),
  PIN_FIELD_BASE(84, 84, IOCFG_T_BASE, 0x03C, 0xc, 17, 1),
  PIN_FIELD_BASE(85, 85, IOCFG_T_BASE, 0x03C, 0xc, 18, 1),
  PIN_FIELD_BASE(86, 86, IOCFG_T_BASE, 0x03C, 0xc, 19, 1),
  PIN_FIELD_BASE(87, 87, IOCFG_T_BASE, 0x03C, 0xc, 20, 1),
  PIN_FIELD_BASE(88, 88, IOCFG_T_BASE, 0x03C, 0xc, 21, 1),
  PIN_FIELD_BASE(89, 89, IOCFG_T_BASE, 0x03C, 0xc, 22, 1),
  PIN_FIELD_BASE(90, 90, IOCFG_T_BASE, 0x03C, 0xc, 23, 1),
  PIN_FIELD_BASE(91, 91, IOCFG_T_BASE, 0x03C, 0xc, 24, 1),
  PIN_FIELD_BASE(92, 92, IOCFG_T_BASE, 0x03C, 0xc, 25, 1),
};

static const struct mtk_pin_field_calc mt6572_pin_pullen_range[] = {
  PIN_FIELD_BASE(0, 0, IOCFG_T_BASE, 0x000, 0xc, 0, 1),
  PIN_FIELD_BASE(1, 1, IOCFG_T_BASE, 0x000, 0xc, 1, 1),
  PIN_FIELD_BASE(2, 2, IOCFG_T_BASE, 0x000, 0xc, 2, 1),
  PIN_FIELD_BASE(3, 3, IOCFG_T_BASE, 0x000, 0xc, 3, 1),
  PIN_FIELD_BASE(4, 4, IOCFG_R_BASE, 0x000, 0xc, 0, 1),
  PIN_FIELD_BASE(5, 5, IOCFG_R_BASE, 0x000, 0xc, 1, 1),
  PIN_FIELD_BASE(6, 6, IOCFG_R_BASE, 0x000, 0xc, 2, 1),
  PIN_FIELD_BASE(7, 7, IOCFG_R_BASE, 0x000, 0xc, 3, 1),
  PIN_FIELD_BASE(8, 8, IOCFG_R_BASE, 0x000, 0xc, 4, 1),
  PIN_FIELD_BASE(9, 9, IOCFG_B_BASE, 0x000, 0xc, 2, 1),
  PIN_FIELD_BASE(10, 10, IOCFG_B_BASE, 0x000, 0xc, 3, 1),
  PIN_FIELD_BASE(11, 11, IOCFG_B_BASE, 0x000, 0xc, 4, 1),
  PIN_FIELD_BASE(12, 12, IOCFG_B_BASE, 0x000, 0xc, 5, 1),
  PIN_FIELD_BASE(13, 13, IOCFG_B_BASE, 0x000, 0xc, 6, 1),
  PIN_FIELD_BASE(14, 14, IOCFG_B_BASE, 0x000, 0xc, 7, 1),
  PIN_FIELD_BASE(15, 15, IOCFG_B_BASE, 0x000, 0xc, 8, 1),
  PIN_FIELD_BASE(16, 16, IOCFG_B_BASE, 0x000, 0xc, 9, 1),
  PIN_FIELD_BASE(17, 17, IOCFG_B_BASE, 0x000, 0xc, 10, 1),
  PIN_FIELD_BASE(18, 18, IOCFG_B_BASE, 0x000, 0xc, 11, 1),
  PIN_FIELD_BASE(19, 19, IOCFG_B_BASE, 0x000, 0xc, 12, 1),
  PIN_FIELD_BASE(20, 20, IOCFG_B_BASE, 0x000, 0xc, 13, 1),
  PIN_FIELD_BASE(21, 21, IOCFG_B_BASE, 0x000, 0xc, 14, 1),
  PIN_FIELD_BASE(22, 22, IOCFG_L_BASE, 0x000, 0xc, 0, 1),
  PIN_FIELD_BASE(23, 23, IOCFG_L_BASE, 0x000, 0xc, 1, 1),
  PIN_FIELD_BASE(24, 24, IOCFG_L_BASE, 0x000, 0xc, 2, 1),
  PIN_FIELD_BASE(25, 25, IOCFG_L_BASE, 0x000, 0xc, 3, 1),
  PIN_FIELD_BASE(26, 26, IOCFG_L_BASE, 0x000, 0xc, 6, 1),
  PIN_FIELD_BASE(27, 27, IOCFG_L_BASE, 0x000, 0xc, 7, 1),
  PIN_FIELD_BASE(28, 28, IOCFG_L_BASE, 0x000, 0xc, 8, 1),
  PIN_FIELD_BASE(29, 29, IOCFG_L_BASE, 0x000, 0xc, 10, 1),
  PIN_FIELD_BASE(30, 30, IOCFG_L_BASE, 0x000, 0xc, 12, 1),
  PIN_FIELD_BASE(31, 31, IOCFG_L_BASE, 0x000, 0xc, 11, 1),
  PIN_FIELD_BASE(32, 32, IOCFG_L_BASE, 0x000, 0xc, 9, 1),
  PIN_FIELD_BASE(33, 33, IOCFG_L_BASE, 0x000, 0xc, 5, 1),
  PIN_FIELD_BASE(34, 34, IOCFG_L_BASE, 0x000, 0xc, 14, 1),
  PIN_FIELD_BASE(35, 35, IOCFG_R_BASE, 0x0A8, 0xc, 0, 1),
  PIN_FIELD_BASE(36, 36, IOCFG_R_BASE, 0x0A8, 0xc, 1, 1),
  PIN_FIELD_BASE(37, 37, IOCFG_R_BASE, 0x0A8, 0xc, 2, 1),
  PIN_FIELD_BASE(38, 38, IOCFG_R_BASE, 0x0A8, 0xc, 3, 1),
  PIN_FIELD_BASE(39, 39, IOCFG_R_BASE, 0x0A8, 0xc, 4, 1),
  PIN_FIELD_BASE(40, 40, IOCFG_R_BASE, 0x0A8, 0xc, 5, 1),
  PIN_FIELD_BASE(41, 41, IOCFG_B_BASE, 0x030, 0xc, 8, 1),
  PIN_FIELD_BASE(42, 42, IOCFG_B_BASE, 0x030, 0xc, 10, 1),
  PIN_FIELD_BASE(43, 43, IOCFG_B_BASE, 0x030, 0xc, 7, 1),
  PIN_FIELD_BASE(44, 44, IOCFG_B_BASE, 0x030, 0xc, 6, 1),
  PIN_FIELD_BASE(45, 45, IOCFG_B_BASE, 0x030, 0xc, 5, 1),
  PIN_FIELD_BASE(46, 46, IOCFG_B_BASE, 0x030, 0xc, 4, 1),
  PIN_FIELD_BASE(47, 47, IOCFG_B_BASE, 0x030, 0xc, 3, 1),
  PIN_FIELD_BASE(48, 48, IOCFG_B_BASE, 0x030, 0xc, 2, 1),
  PIN_FIELD_BASE(49, 49, IOCFG_B_BASE, 0x030, 0xc, 1, 1),
  PIN_FIELD_BASE(50, 50, IOCFG_B_BASE, 0x030, 0xc, 0, 1),
  PIN_FIELD_BASE(51, 51, IOCFG_B_BASE, 0x030, 0xc, 9, 1),
  PIN_FIELD_BASE(52, 52, IOCFG_R_BASE, 0x030, 0xc, 0, 1),
  PIN_FIELD_BASE(53, 53, IOCFG_R_BASE, 0x030, 0xc, 1, 1),
  PIN_FIELD_BASE(54, 54, IOCFG_R_BASE, 0x030, 0xc, 2, 1),
  PIN_FIELD_BASE(55, 55, IOCFG_R_BASE, 0x030, 0xc, 3, 1),
  PIN_FIELD_BASE(56, 56, IOCFG_R_BASE, 0x030, 0xc, 4, 1),
  PIN_FIELD_BASE(57, 57, IOCFG_R_BASE, 0x030, 0xc, 5, 1),
  PIN_FIELD_BASE(58, 58, IOCFG_R_BASE, 0x000, 0xc, 8, 1),
  PIN_FIELD_BASE(59, 59, IOCFG_T_BASE, 0x000, 0xc, 18, 1),
  PIN_FIELD_BASE(60, 60, IOCFG_T_BASE, 0x000, 0xc, 19, 1),
  PIN_FIELD_BASE(61, 61, IOCFG_R_BASE, 0x000, 0xc, 9, 1),
  PIN_FIELD_BASE(62, 62, IOCFG_T_BASE, 0x000, 0xc, 20, 1),
  PIN_FIELD_BASE(63, 63, IOCFG_T_BASE, 0x000, 0xc, 21, 1),
  PIN_FIELD_BASE(64, 64, IOCFG_T_BASE, 0x030, 0xc, 0, 1),
  PIN_FIELD_BASE(65, 65, IOCFG_T_BASE, 0x030, 0xc, 1, 1),
  PIN_FIELD_BASE(66, 66, IOCFG_R_BASE, 0x000, 0xc, 5, 1),
  PIN_FIELD_BASE(67, 67, IOCFG_T_BASE, 0x030, 0xc, 2, 1),
  PIN_FIELD_BASE(68, 68, IOCFG_R_BASE, 0x000, 0xc, 6, 1),
  PIN_FIELD_BASE(69, 69, IOCFG_T_BASE, 0x030, 0xc, 3, 1),
  PIN_FIELD_BASE(70, 70, IOCFG_R_BASE, 0x000, 0xc, 7, 1),
  PIN_FIELD_BASE(71, 71, IOCFG_R_BASE, 0x000, 0xc, 10, 1),
  PIN_FIELD_BASE(72, 72, IOCFG_R_BASE, 0x000, 0xc, 11, 1),
  PIN_FIELD_BASE(73, 73, IOCFG_R_BASE, 0x000, 0xc, 12, 1),
  PIN_FIELD_BASE(74, 74, IOCFG_R_BASE, 0x000, 0xc, 13, 1),
  PIN_FIELD_BASE(75, 75, IOCFG_R_BASE, 0x000, 0xc, 14, 1),
  PIN_FIELD_BASE(76, 76, IOCFG_R_BASE, 0x000, 0xc, 15, 1),
  PIN_FIELD_BASE(77, 77, IOCFG_B_BASE, 0x000, 0xc, 0, 1),
  PIN_FIELD_BASE(78, 78, IOCFG_B_BASE, 0x000, 0xc, 1, 1),
  PIN_FIELD_BASE(79, 79, IOCFG_T_BASE, 0x000, 0xc, 4, 1),
  PIN_FIELD_BASE(80, 80, IOCFG_T_BASE, 0x000, 0xc, 5, 1),
  PIN_FIELD_BASE(81, 81, IOCFG_T_BASE, 0x000, 0xc, 6, 1),
  PIN_FIELD_BASE(82, 82, IOCFG_T_BASE, 0x000, 0xc, 7, 1),
  PIN_FIELD_BASE(83, 83, IOCFG_T_BASE, 0x000, 0xc, 8, 1),
  PIN_FIELD_BASE(84, 84, IOCFG_T_BASE, 0x000, 0xc, 9, 1),
  PIN_FIELD_BASE(85, 85, IOCFG_T_BASE, 0x000, 0xc, 10, 1),
  PIN_FIELD_BASE(86, 86, IOCFG_T_BASE, 0x000, 0xc, 11, 1),
  PIN_FIELD_BASE(87, 87, IOCFG_T_BASE, 0x000, 0xc, 12, 1),
  PIN_FIELD_BASE(88, 88, IOCFG_T_BASE, 0x000, 0xc, 13, 1),
  PIN_FIELD_BASE(89, 89, IOCFG_T_BASE, 0x000, 0xc, 14, 1),
  PIN_FIELD_BASE(90, 90, IOCFG_T_BASE, 0x000, 0xc, 15, 1),
  PIN_FIELD_BASE(91, 91, IOCFG_T_BASE, 0x000, 0xc, 16, 1),
  PIN_FIELD_BASE(92, 92, IOCFG_T_BASE, 0x000, 0xc, 17, 1),
};

static const struct mtk_pin_field_calc mt6572_pin_pullsel_range[] = {
  PIN_FIELD_BASE(0, 0, IOCFG_T_BASE, 0x00C, 0xc, 0, 1),
  PIN_FIELD_BASE(1, 1, IOCFG_T_BASE, 0x00C, 0xc, 1, 1),
  PIN_FIELD_BASE(2, 2, IOCFG_T_BASE, 0x00C, 0xc, 2, 1),
  PIN_FIELD_BASE(3, 3, IOCFG_T_BASE, 0x00C, 0xc, 3, 1),
  PIN_FIELD_BASE(4, 4, IOCFG_R_BASE, 0x00C, 0xc, 0, 1),
  PIN_FIELD_BASE(5, 5, IOCFG_R_BASE, 0x00C, 0xc, 1, 1),
  PIN_FIELD_BASE(6, 6, IOCFG_R_BASE, 0x00C, 0xc, 2, 1),
  PIN_FIELD_BASE(7, 7, IOCFG_R_BASE, 0x00C, 0xc, 3, 1),
  PIN_FIELD_BASE(8, 8, IOCFG_R_BASE, 0x00C, 0xc, 4, 1),
  PIN_FIELD_BASE(9, 9, IOCFG_B_BASE, 0x00C, 0xc, 2, 1),
  PIN_FIELD_BASE(10, 10, IOCFG_B_BASE, 0x00C, 0xc, 3, 1),
  PIN_FIELD_BASE(11, 11, IOCFG_B_BASE, 0x00C, 0xc, 4, 1),
  PIN_FIELD_BASE(12, 12, IOCFG_B_BASE, 0x00C, 0xc, 5, 1),
  PIN_FIELD_BASE(13, 13, IOCFG_B_BASE, 0x00C, 0xc, 6, 1),
  PIN_FIELD_BASE(14, 14, IOCFG_B_BASE, 0x00C, 0xc, 7, 1),
  PIN_FIELD_BASE(15, 15, IOCFG_B_BASE, 0x00C, 0xc, 8, 1),
  PIN_FIELD_BASE(16, 16, IOCFG_B_BASE, 0x00C, 0xc, 9, 1),
  PIN_FIELD_BASE(17, 17, IOCFG_B_BASE, 0x00C, 0xc, 10, 1),
  PIN_FIELD_BASE(18, 18, IOCFG_B_BASE, 0x00C, 0xc, 11, 1),
  PIN_FIELD_BASE(19, 19, IOCFG_B_BASE, 0x00C, 0xc, 12, 1),
  PIN_FIELD_BASE(20, 20, IOCFG_B_BASE, 0x00C, 0xc, 13, 1),
  PIN_FIELD_BASE(21, 21, IOCFG_B_BASE, 0x00C, 0xc, 14, 1),
  PIN_FIELD_BASE(22, 22, IOCFG_L_BASE, 0x00C, 0xc, 0, 1),
  PIN_FIELD_BASE(23, 23, IOCFG_L_BASE, 0x00C, 0xc, 1, 1),
  PIN_FIELD_BASE(24, 24, IOCFG_L_BASE, 0x00C, 0xc, 2, 1),
  PIN_FIELD_BASE(25, 25, IOCFG_L_BASE, 0x00C, 0xc, 3, 1),
  PIN_FIELD_BASE(26, 26, IOCFG_L_BASE, 0x00C, 0xc, 6, 1),
  PIN_FIELD_BASE(27, 27, IOCFG_L_BASE, 0x00C, 0xc, 7, 1),
  PIN_FIELD_BASE(28, 28, IOCFG_L_BASE, 0x00C, 0xc, 8, 1),
  PIN_FIELD_BASE(29, 29, IOCFG_L_BASE, 0x00C, 0xc, 10, 1),
  PIN_FIELD_BASE(30, 30, IOCFG_L_BASE, 0x00C, 0xc, 12, 1),
  PIN_FIELD_BASE(31, 31, IOCFG_L_BASE, 0x00C, 0xc, 11, 1),
  PIN_FIELD_BASE(32, 32, IOCFG_L_BASE, 0x00C, 0xc, 9, 1),
  PIN_FIELD_BASE(33, 33, IOCFG_L_BASE, 0x00C, 0xc, 5, 1),
  PIN_FIELD_BASE(34, 34, IOCFG_L_BASE, 0x00C, 0xc, 14, 1),
  PIN_FIELD_BASE(35, 35, IOCFG_R_BASE, 0x0B4, 0xc, 0, 1),
  PIN_FIELD_BASE(36, 36, IOCFG_R_BASE, 0x0B4, 0xc, 1, 1),
  PIN_FIELD_BASE(37, 37, IOCFG_R_BASE, 0x0B4, 0xc, 2, 1),
  PIN_FIELD_BASE(38, 38, IOCFG_R_BASE, 0x0B4, 0xc, 3, 1),
  PIN_FIELD_BASE(39, 39, IOCFG_R_BASE, 0x0B4, 0xc, 4, 1),
  PIN_FIELD_BASE(40, 40, IOCFG_R_BASE, 0x0B4, 0xc, 5, 1),
  PIN_FIELD_BASE(41, 41, IOCFG_B_BASE, 0x018, 0xc, 8, 1),
  PIN_FIELD_BASE(42, 42, IOCFG_B_BASE, 0x018, 0xc, 10, 1),
  PIN_FIELD_BASE(43, 43, IOCFG_B_BASE, 0x018, 0xc, 7, 1),
  PIN_FIELD_BASE(44, 44, IOCFG_B_BASE, 0x018, 0xc, 6, 1),
  PIN_FIELD_BASE(45, 45, IOCFG_B_BASE, 0x018, 0xc, 5, 1),
  PIN_FIELD_BASE(46, 46, IOCFG_B_BASE, 0x018, 0xc, 4, 1),
  PIN_FIELD_BASE(47, 47, IOCFG_B_BASE, 0x018, 0xc, 3, 1),
  PIN_FIELD_BASE(48, 48, IOCFG_B_BASE, 0x018, 0xc, 2, 1),
  PIN_FIELD_BASE(49, 49, IOCFG_B_BASE, 0x018, 0xc, 1, 1),
  PIN_FIELD_BASE(50, 50, IOCFG_B_BASE, 0x018, 0xc, 0, 1),
  PIN_FIELD_BASE(51, 51, IOCFG_B_BASE, 0x018, 0xc, 9, 1),
  PIN_FIELD_BASE(52, 52, IOCFG_R_BASE, 0x018, 0xc, 0, 1),
  PIN_FIELD_BASE(53, 53, IOCFG_R_BASE, 0x018, 0xc, 1, 1),
  PIN_FIELD_BASE(54, 54, IOCFG_R_BASE, 0x018, 0xc, 2, 1),
  PIN_FIELD_BASE(55, 55, IOCFG_R_BASE, 0x018, 0xc, 3, 1),
  PIN_FIELD_BASE(56, 56, IOCFG_R_BASE, 0x018, 0xc, 4, 1),
  PIN_FIELD_BASE(57, 57, IOCFG_R_BASE, 0x018, 0xc, 5, 1),
  PIN_FIELD_BASE(58, 58, IOCFG_R_BASE, 0x00C, 0xc, 8, 1),
  PIN_FIELD_BASE(61, 61, IOCFG_R_BASE, 0x00C, 0xc, 9, 1),
  PIN_FIELD_BASE(64, 64, IOCFG_T_BASE, 0x018, 0xc, 0, 1),
  PIN_FIELD_BASE(65, 65, IOCFG_T_BASE, 0x018, 0xc, 1, 1),
  PIN_FIELD_BASE(66, 66, IOCFG_R_BASE, 0x00C, 0xc, 5, 1),
  PIN_FIELD_BASE(67, 67, IOCFG_T_BASE, 0x018, 0xc, 2, 1),
  PIN_FIELD_BASE(68, 68, IOCFG_R_BASE, 0x00C, 0xc, 6, 1),
  PIN_FIELD_BASE(69, 69, IOCFG_T_BASE, 0x018, 0xc, 3, 1),
  PIN_FIELD_BASE(70, 70, IOCFG_R_BASE, 0x00C, 0xc, 7, 1),
  PIN_FIELD_BASE(71, 71, IOCFG_R_BASE, 0x00C, 0xc, 10, 1),
  PIN_FIELD_BASE(72, 72, IOCFG_R_BASE, 0x00C, 0xc, 11, 1),
  PIN_FIELD_BASE(73, 73, IOCFG_R_BASE, 0x00C, 0xc, 12, 1),
  PIN_FIELD_BASE(74, 74, IOCFG_R_BASE, 0x00C, 0xc, 13, 1),
  PIN_FIELD_BASE(75, 75, IOCFG_R_BASE, 0x00C, 0xc, 14, 1),
  PIN_FIELD_BASE(76, 76, IOCFG_R_BASE, 0x00C, 0xc, 15, 1),
  PIN_FIELD_BASE(77, 77, IOCFG_B_BASE, 0x00C, 0xc, 0, 1),
  PIN_FIELD_BASE(78, 78, IOCFG_B_BASE, 0x00C, 0xc, 1, 1),
  PIN_FIELD_BASE(79, 79, IOCFG_T_BASE, 0x00C, 0xc, 4, 1),
  PIN_FIELD_BASE(80, 80, IOCFG_T_BASE, 0x00C, 0xc, 5, 1),
  PIN_FIELD_BASE(81, 81, IOCFG_T_BASE, 0x00C, 0xc, 6, 1),
  PIN_FIELD_BASE(82, 82, IOCFG_T_BASE, 0x00C, 0xc, 7, 1),
  PIN_FIELD_BASE(83, 83, IOCFG_T_BASE, 0x00C, 0xc, 8, 1),
  PIN_FIELD_BASE(84, 84, IOCFG_T_BASE, 0x00C, 0xc, 9, 1),
  PIN_FIELD_BASE(85, 85, IOCFG_T_BASE, 0x00C, 0xc, 10, 1),
  PIN_FIELD_BASE(86, 86, IOCFG_T_BASE, 0x00C, 0xc, 11, 1),
  PIN_FIELD_BASE(87, 87, IOCFG_T_BASE, 0x00C, 0xc, 12, 1),
  PIN_FIELD_BASE(88, 88, IOCFG_T_BASE, 0x00C, 0xc, 13, 1),
  PIN_FIELD_BASE(89, 89, IOCFG_T_BASE, 0x00C, 0xc, 14, 1),
  PIN_FIELD_BASE(90, 90, IOCFG_T_BASE, 0x00C, 0xc, 15, 1),
  PIN_FIELD_BASE(91, 91, IOCFG_T_BASE, 0x00C, 0xc, 16, 1),
  PIN_FIELD_BASE(92, 92, IOCFG_T_BASE, 0x00C, 0xc, 17, 1),
};

static const struct mtk_pin_field_calc mt6572_pin_drv_range[] = {
  PIN_FIELD_BASE(0, 3, IOCFG_T_BASE, 0x6c, 0xc, 0, 2),
  PIN_FIELD_BASE(4, 8, IOCFG_R_BASE, 0x6c, 0xc, 18, 2),
  PIN_FIELD_BASE(9, 16, IOCFG_B_BASE, 0x6c, 0xc, 4, 2),
  PIN_FIELD_BASE(17, 21, IOCFG_B_BASE, 0x78, 0xc, 21, 2),
  PIN_FIELD_BASE(22, 25, IOCFG_L_BASE, 0x48, 0xc, 0, 2),
  PIN_FIELD_BASE(26, 28, IOCFG_L_BASE, 0x48, 0xc, 10, 2),
  PIN_FIELD_BASE(29, 29, IOCFG_L_BASE, 0x48, 0xc, 18, 2),
  PIN_FIELD_BASE(30, 30, IOCFG_L_BASE, 0x48, 0xc, 22, 2),
  PIN_FIELD_BASE(31, 31, IOCFG_L_BASE, 0x48, 0xc, 20, 2),
  PIN_FIELD_BASE(32, 32, IOCFG_L_BASE, 0x48, 0xc, 16, 2),
  PIN_FIELD_BASE(33, 33, IOCFG_L_BASE, 0x48, 0xc, 8, 2),
  PIN_FIELD_BASE(34, 34, IOCFG_L_BASE, 0x48, 0xc, 26, 2),
  PIN_FIELD_BASE(41, 41, IOCFG_B_BASE, 0x78, 0xc, 12, 3),
  PIN_FIELD_BASE(42, 42, IOCFG_B_BASE, 0x78, 0xc, 18, 3),
  PIN_FIELD_BASE(43, 43, IOCFG_B_BASE, 0x78, 0xc, 9, 3),
  PIN_FIELD_BASE(44, 44, IOCFG_B_BASE, 0x78, 0xc, 6, 3),
  PIN_FIELD_BASE(45, 45, IOCFG_B_BASE, 0x78, 0xc, 3, 3),
  PIN_FIELD_BASE(46, 46, IOCFG_B_BASE, 0x78, 0xc, 0, 3),
  PIN_FIELD_BASE(47, 47, IOCFG_B_BASE, 0x6c, 0xc, 29, 3),
  PIN_FIELD_BASE(48, 48, IOCFG_B_BASE, 0x6c, 0xc, 26, 3),
  PIN_FIELD_BASE(49, 49, IOCFG_B_BASE, 0x6c, 0xc, 23, 3),
  PIN_FIELD_BASE(50, 50, IOCFG_B_BASE, 0x6c, 0xc, 20, 3),
  PIN_FIELD_BASE(51, 51, IOCFG_B_BASE, 0x78, 0xc, 15, 3),
  PIN_FIELD_BASE(52, 57, IOCFG_R_BASE, 0x6c, 0xc, 0, 3),
  PIN_FIELD_BASE(58, 58, IOCFG_R_BASE, 0x78, 0xc, 2, 2),
  PIN_FIELD_BASE(61, 61, IOCFG_R_BASE, 0x78, 0xc, 4, 2),
  PIN_FIELD_BASE(64, 65, IOCFG_T_BASE, 0x6c, 0xc, 8, 2),
  PIN_FIELD_BASE(66, 66, IOCFG_R_BASE, 0x6c, 0xc, 28, 2),
  PIN_FIELD_BASE(67, 67, IOCFG_T_BASE, 0x6c, 0xc, 12, 2),
  PIN_FIELD_BASE(68, 68, IOCFG_R_BASE, 0x6c, 0xc, 30, 2),
  PIN_FIELD_BASE(69, 69, IOCFG_T_BASE, 0x6c, 0xc, 14, 2),
  PIN_FIELD_BASE(70, 70, IOCFG_R_BASE, 0x78, 0xc, 0, 2),
  PIN_FIELD_BASE(71, 76, IOCFG_R_BASE, 0x78, 0xc, 6, 2),
  PIN_FIELD_BASE(77, 78, IOCFG_B_BASE, 0x6c, 0xc, 0, 2),
  PIN_FIELD_BASE(79, 86, IOCFG_T_BASE, 0x6c, 0xc, 16, 2),
  PIN_FIELD_BASE(87, 92, IOCFG_T_BASE, 0x78, 0xc, 0, 2),
};

static const struct mtk_pin_field_calc mt6572_pin_pupd_range[] = {
  PIN_FIELD_BASE(41, 41, IOCFG_B_BASE, 0x18, 0xc, 8, 1),
  PIN_FIELD_BASE(42, 42, IOCFG_B_BASE, 0x18, 0xc, 10, 1),
  PIN_FIELD_BASE(43, 43, IOCFG_B_BASE, 0x18, 0xc, 7, 1),
  PIN_FIELD_BASE(44, 44, IOCFG_B_BASE, 0x18, 0xc, 6, 1),
  PIN_FIELD_BASE(45, 45, IOCFG_B_BASE, 0x18, 0xc, 5, 1),
  PIN_FIELD_BASE(46, 46, IOCFG_B_BASE, 0x18, 0xc, 4, 1),
  PIN_FIELD_BASE(47, 47, IOCFG_B_BASE, 0x18, 0xc, 3, 1),
  PIN_FIELD_BASE(48, 48, IOCFG_B_BASE, 0x18, 0xc, 2, 1),
  PIN_FIELD_BASE(49, 49, IOCFG_B_BASE, 0x18, 0xc, 1, 1),
  PIN_FIELD_BASE(50, 50, IOCFG_B_BASE, 0x18, 0xc, 0, 1),
  PIN_FIELD_BASE(51, 51, IOCFG_B_BASE, 0x18, 0xc, 9, 1),
  PIN_FIELD_BASE(52, 57, IOCFG_R_BASE, 0x18, 0xc, 0, 1),
  PIN_FIELD_BASE(64, 65, IOCFG_T_BASE, 0x18, 0xc, 0, 1),
  PIN_FIELD_BASE(67, 67, IOCFG_T_BASE, 0x18, 0xc, 2, 1),
  PIN_FIELD_BASE(69, 69, IOCFG_T_BASE, 0x18, 0xc, 3, 1),
};

static const struct mtk_pin_field_calc mt6572_pin_r0_range[] = {
  PIN_FIELD_BASE(41, 41, IOCFG_B_BASE, 0x24, 0xc, 8, 1),
  PIN_FIELD_BASE(42, 42, IOCFG_B_BASE, 0x24, 0xc, 10, 1),
  PIN_FIELD_BASE(43, 43, IOCFG_B_BASE, 0x24, 0xc, 7, 1),
  PIN_FIELD_BASE(44, 44, IOCFG_B_BASE, 0x24, 0xc, 6, 1),
  PIN_FIELD_BASE(45, 45, IOCFG_B_BASE, 0x24, 0xc, 5, 1),
  PIN_FIELD_BASE(46, 46, IOCFG_B_BASE, 0x24, 0xc, 4, 1),
  PIN_FIELD_BASE(47, 47, IOCFG_B_BASE, 0x24, 0xc, 3, 1),
  PIN_FIELD_BASE(48, 48, IOCFG_B_BASE, 0x24, 0xc, 2, 1),
  PIN_FIELD_BASE(49, 49, IOCFG_B_BASE, 0x24, 0xc, 1, 1),
  PIN_FIELD_BASE(50, 50, IOCFG_B_BASE, 0x24, 0xc, 0, 1),
  PIN_FIELD_BASE(51, 51, IOCFG_B_BASE, 0x24, 0xc, 9, 1),
  PIN_FIELD_BASE(52, 57, IOCFG_R_BASE, 0x24, 0xc, 0, 1),
  PIN_FIELD_BASE(64, 65, IOCFG_T_BASE, 0x24, 0xc, 0, 1),
  PIN_FIELD_BASE(67, 67, IOCFG_T_BASE, 0x24, 0xc, 2, 1),
  PIN_FIELD_BASE(69, 69, IOCFG_T_BASE, 0x24, 0xc, 3, 1),
};

static const struct mtk_pin_field_calc mt6572_pin_r1_range[] = {
  PIN_FIELD_BASE(41, 41, IOCFG_B_BASE, 0x30, 0xc, 8, 1),
  PIN_FIELD_BASE(42, 42, IOCFG_B_BASE, 0x30, 0xc, 10, 1),
  PIN_FIELD_BASE(43, 43, IOCFG_B_BASE, 0x30, 0xc, 7, 1),
  PIN_FIELD_BASE(44, 44, IOCFG_B_BASE, 0x30, 0xc, 6, 1),
  PIN_FIELD_BASE(45, 45, IOCFG_B_BASE, 0x30, 0xc, 5, 1),
  PIN_FIELD_BASE(46, 46, IOCFG_B_BASE, 0x30, 0xc, 4, 1),
  PIN_FIELD_BASE(47, 47, IOCFG_B_BASE, 0x30, 0xc, 3, 1),
  PIN_FIELD_BASE(48, 48, IOCFG_B_BASE, 0x30, 0xc, 2, 1),
  PIN_FIELD_BASE(49, 49, IOCFG_B_BASE, 0x30, 0xc, 1, 1),
  PIN_FIELD_BASE(50, 50, IOCFG_B_BASE, 0x30, 0xc, 0, 1),
  PIN_FIELD_BASE(51, 51, IOCFG_B_BASE, 0x30, 0xc, 9, 1),
  PIN_FIELD_BASE(52, 57, IOCFG_R_BASE, 0x30, 0xc, 0, 1),
  PIN_FIELD_BASE(64, 65, IOCFG_T_BASE, 0x30, 0xc, 0, 1),
  PIN_FIELD_BASE(67, 67, IOCFG_T_BASE, 0x30, 0xc, 2, 1),
  PIN_FIELD_BASE(69, 69, IOCFG_T_BASE, 0x30, 0xc, 3, 1),
};

static const struct mtk_pin_reg_calc mt6572_reg_cals[] = {
  [PINCTRL_PIN_REG_MODE] = MTK_RANGE(mt6572_pin_mode_range),
  [PINCTRL_PIN_REG_DIR] = MTK_RANGE(mt6572_pin_dir_range),
  [PINCTRL_PIN_REG_DI] = MTK_RANGE(mt6572_pin_di_range),
  [PINCTRL_PIN_REG_DO] = MTK_RANGE(mt6572_pin_do_range),
  [PINCTRL_PIN_REG_IES] = MTK_RANGE(mt6572_pin_ies_range),
  [PINCTRL_PIN_REG_SMT] = MTK_RANGE(mt6572_pin_smt_range),
  [PINCTRL_PIN_REG_PULLSEL] = MTK_RANGE(mt6572_pin_pullsel_range),
  [PINCTRL_PIN_REG_PULLEN] = MTK_RANGE(mt6572_pin_pullen_range),
  [PINCTRL_PIN_REG_DRV] = MTK_RANGE(mt6572_pin_drv_range),
  [PINCTRL_PIN_REG_PUPD] = MTK_RANGE(mt6572_pin_pupd_range),
  [PINCTRL_PIN_REG_R0] = MTK_RANGE(mt6572_pin_r0_range),
  [PINCTRL_PIN_REG_R1] = MTK_RANGE(mt6572_pin_r1_range),
};

static const int mt6572_msdc0_pins[] =  { 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, };
static const int mt6572_msdc0_funcs[] = { 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  };
static const int mt6572_msdc1_pins[] =  { 52, 53, 54, 55, 56, 57, };
static const int mt6572_msdc1_funcs[] = { 1,  1,  1,  1,  1,  1,  };

static const struct mtk_group_desc mt6572_groups[] = {
  PINCTRL_PIN_GROUP("msdc0", mt6572_msdc0),
  PINCTRL_PIN_GROUP("msdc1", mt6572_msdc1),
};

static const char *const mt6572_msdc_groups[] = { "msdc0", "msdc1" };

static const struct mtk_function_desc mt6572_functions[] = {
  {"msdc", mt6572_msdc_groups, ARRAY_SIZE(mt6572_msdc_groups)},
};

static const struct mtk_pinctrl_soc mt6572_data = {
  .name = "mt6572_pinctrl",
  .reg_cal = mt6572_reg_cals,
  .pins = mt6572_pins,
  .npins = ARRAY_SIZE(mt6572_pins),
  .grps = mt6572_groups,
  .ngrps = ARRAY_SIZE(mt6572_groups),
  .funcs = mt6572_functions,
  .nfuncs = ARRAY_SIZE(mt6572_functions),
  .base_names = mt6572_pinctrl_register_base_names,
  .nbase_names = ARRAY_SIZE(mt6572_pinctrl_register_base_names),
  .base_calc = 1,
  .gpio_mode = 0,
  .rev = MTK_PINCTRL_V1,
};

static int mtk_pinctrl_mt6572_probe(struct udevice *dev)
{
  int err = mtk_pinctrl_common_probe(dev, &mt6572_data);
  if (err)
    return err;

  // WORKAROUND: set msdc1 pins mode to "msdc mode"
  // This is required to get msdc1 work
  // Based on downstream kernel source code
  // version: 3.18.35
  // file: drivers/mmc/host/mediatek/mt6580/sd.c
  // line: 1577
  mtk_i_rmw(dev, IOCFG_R_BASE, 0xA4, 0xffffffff, 0x3f);

  return 0;
}

static const struct udevice_id mt6572_pctrl_match[] = {
  { .compatible = "mediatek,mt6572-pinctrl" },
  { }
};

U_BOOT_DRIVER(mt6572_pinctrl) = {
  .name = "mt6572_pinctrl",
  .id = UCLASS_PINCTRL,
  .of_match = mt6572_pctrl_match,
  .ops = &mtk_pinctrl_ops,
  .bind = mtk_pinctrl_common_bind,
  .probe = mtk_pinctrl_mt6572_probe,
  .priv_auto = sizeof(struct mtk_pinctrl_priv),
};
