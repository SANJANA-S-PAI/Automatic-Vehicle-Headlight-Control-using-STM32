
🚗 Automatic Vehicle Headlight Control using STM32
Intelligent embedded system for automatic headlight switching and brightness control using ambient light detection.

📌 Overview
This project implements an Automatic Vehicle Headlight Control System using an STM32 microcontroller.

The system monitors ambient light intensity using an LDR sensor and automatically switches vehicle headlights ON/OFF based on environmental conditions.

Brightness is dynamically controlled using PWM to ensure optimal illumination while minimizing power consumption.

🛠 Technologies Used

    •	STM32F103 Microcontroller
    •	Embedded C
    •	LDR (Light Dependent Resistor)
    •	N-Channel MOSFET
    •	LM2596 Buck Converter
    •	16x2 LCD (I2C)
    •	PWM Brightness Control
    •	ADC-Based Light Sensing

⚙ System Specifications

    •	Supply Voltage: 12V
    •	Logic Voltage: 5V (Buck Converter)
    •	MCU Core Voltage: 3.3V
    •	ADC Resolution: 12-bit (0–4095)
    •	PWM Output Pin: PA8
    •	Light Sensor Input: PA0

🧠 Working Principle

    1.	12V battery powers the LED headlight.
    2.	Buck converter steps down voltage to 5V.
    3.	LDR senses ambient light and sends analog signal to STM32 ADC.
    4.	STM32 compares ADC value with predefined thresholds.
    5.	Based on light condition:
       
        •	Day Mode → Headlight OFF
        •	Evening Mode → Dim Brightness
        •	Night Mode → Full Brightness
      	
    7.	MOSFET switches the 12V headlight.
    8.	PWM controls brightness level.
    9.	LCD displays system status in real time.



▶ Operating Modes

    Mode	   Condition	   PWM Duty Cycle 	  Headlight Status
    
    Day	        Bright	          0%	              OFF
    
    Evening	    Medium	          40%	              DIM
    
    Night	    Dark	         100%	            FULL ON


📌 Applications

    •	Smart Vehicle Headlight Systems
    •	Automotive Safety Enhancement
    •	Energy Efficient Lighting Systems
    •	Embedded Automotive Control

🚀 Future Improvements

    •	Automatic high-beam/low-beam switching
    •	Rain & fog detection integration
    •	CAN bus integration
    •	Automotive-grade PCB implementation

👩‍💻 Author

Sanjana S Pai

Electronics & Instrumentation Engineering
