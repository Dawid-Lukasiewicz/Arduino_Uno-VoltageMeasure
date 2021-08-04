#include <LiquidCrystal.h>

#define LED_amount 6

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

volatile int Divisor = 1024 / LED_amount;

void setup()
{
    lcd.begin(16, 2);
    for (uint8_t i = 13; i > 13 - LED_amount; i--)
    {
        pinMode(i, OUTPUT);
    }
}

void loop()
{
    // ADC read
    uint16_t ADC_Value = analogRead(PIN_A0);
    // uint8_t LED_level = ADC_Value / Divisor;
    uint8_t LED_level = map(ADC_Value, 0, 1023, 0, 7);

    // LCD display
    float Voltage = ADC_Value * 5.0 / 1024;
    lcd.setCursor(0, 0);
    lcd.print("Voltage ");
    lcd.print(Voltage);
    lcd.print(" V");

    // LED visualization
    for (uint8_t i = 13; i > 13 - LED_amount; i--)
    {
        digitalWrite(i, LOW);
    }
    for (uint8_t i = 13; i > 13 - LED_level; i--)
    {
        digitalWrite(i, HIGH);
    }
}
