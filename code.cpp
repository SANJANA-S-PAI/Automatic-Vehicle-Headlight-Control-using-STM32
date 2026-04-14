#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/* -------------------- LCD Configuration -------------------- */
// Change to 0x3F if required
LiquidCrystal_I2C lcd(0x27, 16, 2);

/* -------------------- Pin Definitions -------------------- */
#define LDR_PIN        PA0
#define BUTTON_PIN     PA1
#define LED_PWM        PA8

/* -------------------- Threshold Values -------------------- */
#define DAY_THRESHOLD       1300
#define EVENING_THRESHOLD   2600

int ldrValue = 0;
int pwmValue = 0;

void setup()
{
    /* Configure Pins */
    pinMode(LDR_PIN, INPUT_ANALOG);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_PWM, PWM);

    /* Initialize I2C and LCD */
    Wire.begin();
    lcd.init();
    lcd.backlight();

    lcd.setCursor(0, 0);
    lcd.print("Auto Headlight");
    lcd.setCursor(0, 1);
    lcd.print("System Ready");
    delay(1500);
    lcd.clear();

    /* Ensure LED is OFF initially */
    analogWrite(LED_PWM, 0);
}

void loop()
{
    /* Read Ambient Light */
    ldrValue = analogRead(LDR_PIN);   // ADC range: 0–4095

    /* Check Ignition (Push Button) */
    if (digitalRead(BUTTON_PIN) == LOW)   // Ignition ON
    {
        lcd.setCursor(0, 0);
        lcd.print("Ignition ON   ");

        /* LDR Behavior:
           Bright Light  -> LOW ADC value
           Dark Condition -> HIGH ADC value */

        if (ldrValue < DAY_THRESHOLD)
        {
            // DAY MODE
            pwmValue = 0;   // LED OFF
            lcd.setCursor(0, 1);
            lcd.print("Day Mode      ");
        }
        else if (ldrValue < EVENING_THRESHOLD)
        {
            // EVENING MODE
            pwmValue = 102;  // ~40% Brightness
            lcd.setCursor(0, 1);
            lcd.print("Evening Mode  ");
        }
        else
        {
            // NIGHT MODE
            pwmValue = 255;  // 100% Brightness
            lcd.setCursor(0, 1);
            lcd.print("Night Mode    ");
        }

        analogWrite(LED_PWM, pwmValue);
    }
    else
    {
        // Ignition OFF
        analogWrite(LED_PWM, 0);

        lcd.setCursor(0, 0);
        lcd.print("Ignition OFF  ");
        lcd.setCursor(0, 1);
        lcd.print("Light OFF     ");
    }

    delay(300);
}
