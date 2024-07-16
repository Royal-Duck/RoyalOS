#include "../lib/OS_debug.h"

void kmain(void); // called when starting

void kmain(void){
	OS_debug_E9P_puts("test!\n");
	OS_debug_E9P_putn(-1264, true); // TODO : fix the error : refer to OS_debug.h TODO about the function
	OS_debug_E9P_puts("\n");
	while (1){}
}
