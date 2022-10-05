/*
 * marcos.h
 *
 *  Created on: 2017. gada 20. febr.
 *      Author: Roberts
 */

#ifndef COMMON_MARCOS_H_
#define COMMON_MARCOS_H_

/* Function return values   */
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

/* Bit Configuration Macros	*/
#define MASK_SET(REG,BIT) 			REG |= BIT	/* Sets the particular bit(s)		*/
#define MASK_CLEAR(REG,BIT) 		REG &=~BIT	/* Sets the particular bit(s)		*/
#define MASK_CHECK(REG,BIT)			REG & BIT	/* Checks the particular bit(s)		*/
#define MASK_TOGGLE(REG,BIT) 		REG^=BIT	/* Toggles the particular bit(s)	*/

#define ADDRESS_OF(ADDR)            &ADDR       /* Convert value to address         */

#define FALSE   0
#define TRUE    !FALSE

/* Non-blocking code state machine macros   */
#define NON_BLOCKING_CODE_BEGIN     static uint8_t state = 0; switch(state){ case 0:
#define NON_BLOCKING_CODE_WAIT(x)   state++; case 1: if(x == 0){break;} state++; case 2:
#define NON_BLOCKING_CODE_END       state = 0; break; default: break;}

#endif /* COMMON_MARCOS_H_ */
