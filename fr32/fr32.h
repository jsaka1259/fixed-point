#ifndef _FR32_H_
#define _FR32_H_

#define FMSB 31
#define SFT_LIMIT(sft) (((uint8_t)(sft) > (FMSB)) ? (FMSB) : (uint8_t)(sft))

#define M_PIH 1.5707963267341256

extern int32_t float_to_fr32(float real, uint8_t sft);
extern int32_t float_to_fr32_pih(uint8_t sft);
extern int32_t double_to_fr32(double real, uint8_t sft);
extern int32_t double_to_fr32_pih(uint8_t sft);
extern float fr32_to_float(int32_t fr32, uint8_t sft);
extern double fr32_to_double(int32_t fr32, uint8_t sft);
extern int32_t mul_fr32(int32_t a, int32_t b, uint8_t sft);
extern int32_t div_fr32(int32_t a, int32_t b, uint8_t sft);
extern int32_t cos_fr32(int32_t x, uint8_t sft);
extern int32_t sin_fr32(int32_t x, uint8_t sft);

#endif
