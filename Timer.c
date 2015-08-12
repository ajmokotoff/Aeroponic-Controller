#include <SimpleTimer.h>

SimpleTimer timer;

void turn_off_pump()
{
	//turn off pump here
}

void turn_on_pump()
{
	// turn on pump here
	timer.setTimeout(60000, turn_off_pump();
}

void toggle_light()
{
	print "hello";
}

void set_up()
{
	timer.setInterval(3600000, turn_on_pump);
	timer.setInterval(432000000, toggle_light);
}
