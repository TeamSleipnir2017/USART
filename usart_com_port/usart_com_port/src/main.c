
/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include "asf.h"
#include "conf_board.h"



static void configure_console(void)
{
	const usart_serial_options_t uart_serial_options = {
		.baudrate = 115200,
		.paritytype = UART_MR_PAR_NO
	};

	/* Configure console UART. */
	sysclk_enable_peripheral_clock(CONSOLE_UART_ID);
	stdio_serial_init(CONSOLE_UART, &uart_serial_options);
}

//Send Integers over to terminal
void print_long(unsigned long data)
{
	unsigned long div = 1000000000;		// Divider to divide data with
	char start = 0;
	char cnt = 10;
	for (int i = 1; i <= cnt; i++)
	{
		char send = data / div + 48; // calculate the Ascii for each number
		if(send != 48 || start == 1 || i == cnt)
		{
			//Wait until hardware is ready to send data, UDRE0 = Data register empty
			putchar(send);
			start = 1;
		}
		data %= div;
		div /= 10;
	}
	putchar(10);
}



int main(void)
{
	/* Initialize the SAM system. */
	sysclk_init();
	board_init();

	/* Configure UART for debug message output. */
	configure_console();

	/* Output example information. */
	puts("B");
	
	putchar('a');
	
	print_long(567);
	
	print_long(765);
	
	while (1) {
		
	}
}
