/*
 * marcos.h
 *
 *  Created on: 2017. gada 20. febr.
 *      Author: Roberts
 */

#ifndef COMMON_MARCOS_H_
#define COMMON_MARCOS_H_

/*	Bit Configuration Macros	*/
#define MASK_SET(REG,BIT) 			REG |= BIT	/* Sets the particular bit(s)		*/
#define MASK_CLEAR(REG,BIT) 		REG &=~BIT	/* Sets the particular bit(s)		*/
#define MASK_CHECK(REG,BIT)			REG & BIT	/* Checks the particular bit(s)		*/
#define MASK_TOGGLE(REG,BIT) 		REG^=BIT	/* Toggles the particular bit(s)	*/

#define ADDRESS_OF(ADDR)            &ADDR       /* Convert value to address         */

#endif /* COMMON_MARCOS_H_ */
