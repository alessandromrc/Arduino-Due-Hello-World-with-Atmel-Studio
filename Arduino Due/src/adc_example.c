#include <string.h>
#include "asf.h"
#include "conf_board.h"

static void configure_console(void)
{
	const usart_serial_options_t uart_serial_options = {
		.baudrate = CONF_UART_BAUDRATE,
		.paritytype = CONF_UART_PARITY
	};

	/* Configure console UART. */
	sysclk_enable_peripheral_clock(CONSOLE_UART_ID);
	stdio_serial_init(CONF_UART, &uart_serial_options);
}
/*
static volatile uint32_t gs_ul_ms_ticks = 0;

void SysTick_Handler(void)
{
	gs_ul_ms_ticks++;
}
static void mdelay(uint32_t ul_dly_ticks)
{
	uint32_t ul_cur_ticks;

	ul_cur_ticks = gs_ul_ms_ticks;
	while ((gs_ul_ms_ticks - ul_cur_ticks) < ul_dly_ticks);
}
*/

int main(void)
{
	/* Initialize the SAM system. */
	sysclk_init();
	board_init();
	configure_console();
	puts("Hello World");
}