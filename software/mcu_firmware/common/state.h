#ifndef COMMON_STATE_H_
#define COMMON_STATE_H_

#include <stdint.h>
#include <stdbool.h>

#define __CAT(x, y) x ## y
#define CAT(x, y) __CAT(x, y)

#define BEGIN() static uint32_t state=0; switch(state) { case 0:
#define WAIT(x) do {state = CAT(99,__LINE__); case CAT(99,__LINE__): if(x){return false;}else{state=__LINE__;}; case __LINE__:; } while (0)
#define WAITRET(x) do {state = CAT(99,__LINE__); case CAT(99,__LINE__): if(x){return true;}else{state=__LINE__;}; case __LINE__:; } while (0)
#define RESET() do { state=0; } while (0); return false
#define END() do {state = CAT(99,__LINE__); case CAT(99,__LINE__): ; } while (0);} return true
#define RESETANDEND(name) do { state=0; } while (0); } return true

#endif /* COMMON_STATE_H_ */
