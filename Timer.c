#include <SimpleTimer.h>

SimpleTimer timer;

void turn_off_pump()
{
	// turn off pump
	print("Pump off!\n");
	toggle(pump_timer);
}

void turn_on_pump()
{
	// turn on pump here
	print("Pump on!\n");
	timer.setTimeout(60000, turn_off_pump();
	toggle(pump_timer);
}

void off_light()
{
	// off light
	print("Light off!\n");
	toggle(light_timer);
}

void on_light()
{
	// turn on light
	print("Light on!\n");
	timer.setTimeout(432000000, off_light);
	toggle(light_timer);
}

void set_up()
{
	pump_timer = timer.setInterval(3600000, turn_on_pump);
	light_timer = timer.setInterval(432000000, toggle_light);
}

void main()
{
	set_up();
}
