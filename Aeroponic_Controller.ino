#include </home/mok/Arduino/Aeroponic_Controller/SimpleTimer.h>

SimpleTimer timer;

int pump_timer;
int light_timer;

void turn_off_pump()
{
  // turn off pump
  Serial.println("Pump off!");
  timer.toggle(pump_timer);
}

void turn_on_pump()
{
  // turn on pump here
  Serial.println("Pump on!");
  timer.setTimeout(60000, turn_off_pump);
  timer.toggle(pump_timer);
}

void off_light()
{
  // off light
  Serial.println("Light off!");
  timer.toggle(light_timer);
}

void on_light()
{
  // turn on light
  Serial.println("Light on!");
  timer.setTimeout(432000000, off_light);
  timer.toggle(light_timer);
}

void setup()
{
  Serial.begin(9600);
  pump_timer = timer.setInterval(3600000, turn_on_pump);
  light_timer = timer.setInterval(432000000, on_light);
}

void loop()
{
  timer.run();
}

