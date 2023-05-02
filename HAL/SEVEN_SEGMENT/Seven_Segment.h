/*
 * Seven_Segment.h
 *
 *  Created on: Jan 19, 2023
 *      Author: AMIT
 */
#include "Seven_Segment_Config.h"

#ifndef HAL_SEVEN_SEGMENT_SEVEN_SEGMENT_H_
#define HAL_SEVEN_SEGMENT_SEVEN_SEGMENT_H_

void Seven_Segment_Init(void);

void Seven_Segment_write_Number(uint8 number);

void Seven_Segment1_Enable(void);
void Seven_Segment2_Enable(void);

void Seven_Segment1_Disable(void);
void Seven_Segment2_Disable(void);

#endif /* HAL_SEVEN_SEGMENT_SEVEN_SEGMENT_H_ */
