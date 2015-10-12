#include </home/oflaisher/arduino-1.6.5-r5/Aeroponic_Controller/SimpleTimer.h>

SimpleTimer timer;
int pump_timer, light_timer;
const int pump_pin = 12; // pump is digital pin 12
const int light_pin = 13; // light is digital pin 13

void turn_off_pump()
{
        // turn off pump
        Serial.println("Pump off!");
        digitalWrite(pump_pin, LOW);
        timer.setTimeout(18000, turn_on_pump); //1800000 is 30 minutes off until pump toggles on
        timer.toggle(pump_timer);
        Serial.println(digitalRead(pump_pin));
}

void turn_on_pump()
{
        // turn on pump here
        Serial.println("Pump on!");
        digitalWrite(pump_pin, HIGH);
        timer.toggle(pump_timer);
        Serial.println(digitalRead(pump_pin));
}

void off_light()
{
        // off light
        Serial.println("Light off!");
        digitalWrite(light_pin, LOW);
        timer.setTimeout(43200, on_light); //432000000 is 12 hrs on until light toggles on
        timer.toggle(light_timer);
        Serial.println(digitalRead(light_pin));
}

void on_light()
{
        // turn on light
        Serial.println("Light on!");
        digitalWrite(light_pin, HIGH);
        timer.toggle(light_timer);
        Serial.println(digitalRead(light_pin));
}

void setup()
{
        Serial.begin(9600);
        pinMode(pump_pin, OUTPUT);
        pinMode(light_pin, OUTPUT);
        Serial.println("Starting!");
        Serial.println(digitalRead(pump_pin));
        Serial.println(digitalRead(light_pin));
        pump_timer = timer.setInterval(60000, turn_off_pump); //60000 means it takes 1 min for pump to turn off
        light_timer = timer.setInterval(43200, off_light); //432000000 means it takes 12 hr for light to turn off
}

void loop()
{
        digitalWrite(pump_pin, HIGH); // HIGH here means system starts at high voltage or on
        digitalWrite(light_pin, HIGH); // HIGH here means system starts at high voltage or on
        timer.run();
}

