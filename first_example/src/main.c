/**********************************************************************
 * First Example - Blinks the LEDs connected to the 4C port at 100 Khz
 * rev 1 - shabaz - Nov 2024
 * For this example, attach an oscilloscope to (say) pin X0D21 (P4C3)
 * on the evaluation board. You should see a square wave at 100 KHz.
 **********************************************************************/

// includes
#include <platform.h>
#include <xcore/port.h>
#include <syscall.h>
#include <print.h>

// global variables
port_t led_port = XS1_PORT_4C;
xclock_t clock_handle = XS1_CLKBLK_1;

//main function
int main() {
    int led_state = 0;
    port_timestamp_t tstamp;

    printstr("First Example is Running\n");

    // enable resources before any other operations on them
    port_enable(led_port);
    clock_enable(clock_handle);

    // configure the clock to 1 MHz
    clock_set_source_clk_ref(clock_handle); // set the clock source to 100 MHz, i.e. 10 nsec period
    clock_set_divide(clock_handle, 50); // divide the clock by 2*50 (100) to get 1 MHz, i.e. 1 usec period

    // start the clock, and assign it to the port counter
    clock_start(clock_handle);
    port_set_clock(led_port, clock_handle);
    
    // forever loop
    while(1) {
        // toggle the state variable
        led_state = !led_state;
        //port_out will be immediate, unless there is a count condition set
        if (led_state) {
            port_out(led_port, 0xf);
        } else {
            port_out(led_port, 0x0);
        }
        // determine the precise count value that the port update occurred at:
        tstamp = port_get_trigger_time(led_port);
        // set a condition that the next port update must occur exactly 5 usec later
        port_set_trigger_time(led_port, tstamp + 5); // 5 usec
        // the next port_out will pause until the count value set.
    }
    
    return 0;  // warning on this line is OK
}
