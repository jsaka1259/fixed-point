#ifndef _FR32_H_
#define _FR32_H_

#ifndef __SIZEOF_FLOAT__
#error "__SIZEOF_FLOAT__ is undefined"
#endif
#if __SIZEOF_FLOAT__ != 4
#error "__SIZEOF_FLOAT__ is not 4"
#endif

#define FMSB ((uint8_t)(((__SIZEOF_FLOAT__) << 3) - 1))
#define SFT_LIMIT(sft) (((uint8_t)(sft) > (FMSB)) ? (FMSB) : (uint8_t)(sft))

#ifndef M_PIH
#define M_PIH 1.57079632F
#endif

extern int32_t float_to_fr32(float real, uint8_t sft);
extern float fr32_to_float(int32_t fr32, uint8_t sft);
extern int32_t mul_fr32(int32_t a, int32_t b, uint8_t sft);
extern int32_t div_fr32(int32_t a, int32_t b, uint8_t sft);
extern int32_t float_to_fr32_pih(uint8_t sft);
extern int32_t cos_fr32(int32_t x, uint8_t sft);
extern int32_t sin_fr32(int32_t x, uint8_t sft);

#endif
