#include </home/mok/Arduino/Aeroponic_Controller/SimpleTimer.h>

SimpleTimer timer;

int pump_timer, light_timer;
const int pump_pin = 12;
const int light_pin = 13;

void turn_off_pump()
{
  // turn off pump
  Serial.println("Pump off!");
  digitalWrite(pump_pin, LOW);
  timer.toggle(pump_timer);
  Serial.println(digitalRead(pump_pin));
}

void turn_on_pump()
{
  // turn on pump here
  Serial.println("Pump on!");
  digitalWrite(pump_pin, HIGH);
  timer.setTimeout(15000, turn_off_pump);
  timer.toggle(pump_timer);
  Serial.println(digitalRead(pump_pin));
}

void off_light()
{
  // off light
  Serial.println("Light off!");
  digitalWrite(light_pin, LOW);
  timer.toggle(light_timer);
  Serial.println(digitalRead(light_pin));
}

void on_light()
{
  // turn on light
  Serial.println("Light on!");
  digitalWrite(light_pin, HIGH);
  timer.setTimeout(20000, off_light);
  timer.toggle(light_timer);
  Serial.println(digitalRead(light_pin));
}

void setup()
{
  Serial.begin(9600);
  pinMode(pump_pin, OUTPUT);
  pinMode(light_pin, OUTPUT);
  Serial.println("Starting!");
  pump_timer = timer.setInterval(10000, turn_on_pump);
  light_timer = timer.setInterval(20000, on_light);
}

void loop()
{
  digitalWrite(pump_pin, LOW);
  digitalWrite(light_pin, LOW);
  timer.run();
}


