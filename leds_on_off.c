#include "contiki.h"
#include <stdio.h>
#include "dev/leds.h"  // To control the LEDs in the simulation`

PROCESS(led_on_off_process, "LED on/off process");
AUTOSTART_PROCESSES(&led_on_off_process);
static struct etimer timer;

PROCESS_THREAD(led_on_off_process, ev, data)
{
    PROCESS_BEGIN();

    /* Setup a periodic timer that expires after 2 seconds. */
    etimer_set(&timer, CLOCK_SECOND * 2);

    while(1) {
        PROCESS_WAIT_EVENT();

        if(ev == PROCESS_EVENT_TIMER) {  // If the timer event occurs
            leds_toggle(LEDS_ALL);  // Toggle LEDs
            printf("LED is toggling\n");
            etimer_reset(&timer);  // Reset the etimer to continue toggling
        }
    }

    PROCESS_END();
}

