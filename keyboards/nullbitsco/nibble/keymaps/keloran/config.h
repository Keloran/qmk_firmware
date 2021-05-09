#pragma once
#define OLED_SLEEP_TIMEOUT 30000
#define OLED_SCREENS 1

#define LAYOUT_nibble_keloran( \
         K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E,      K0F, \
    R01, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E,      K1F, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C,      K2E,      K2F, \
         K31,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C,      K3E, K3F, \
         K41, K42, K43,                K46,           K49, K4A, K4B,      K4C, K4E, K4F  \
) { \
    {___, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F}, \
    {R01, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F}, \
    {K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, ___, K2E, K2F}, \
    {___, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, ___, K3E, K3F}, \
    {___, K41, K42, K43, ___, ___, K46, ___, ___, K49, K4A, K4B, K4C, ___, K4E, K4F}  \
}
