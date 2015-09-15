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
  timer.setTimeout(15000, turn_off_pump);
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
  timer.setTimeout(20000, off_light);
  timer.toggle(light_timer);
}

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting!");
  pump_timer = timer.setInterval(10000, turn_on_pump);
  light_timer = timer.setInterval(20000, on_light);
}

void loop()
{
  timer.run();
}


