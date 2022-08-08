/* Gaurd */
#ifndef SWPWM_INTERFACE_H_
#define SWPWM_INTERFACE_H_

void SWPWM_init(uint32_t frequency_kh, uint8_t dutycycle);

void SWPWM_start(void);

void SWPWM_changeDutyCycle(uint8_t newDutyCycle);

void SWPWM_stop(void);


#endif