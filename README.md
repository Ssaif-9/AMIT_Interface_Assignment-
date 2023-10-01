
# Assignment 1
• Using the DIO in the AVR make a LED OUT.
• Make a simple code that blinks the led in two ways by using bitwise operators

# Assignment 2
Init your LCD on the 4 bits mode and make two push buttons connected to the external interrupted pins.
• The LCD presents numbers between zero to nine
• The first push buttons work to increase the value that’s shown on the LCD, when it reaches the maximum (nine) it will not change
• The second push buttons work to decrease the value that’s shown in the LCD, when it reaches the minimum (zero) it will not change

# Assignment 3
• INIT keypad and LCD.
• Make a simple calculator.
• That takes only take a number between (0,9).
• it just a do the basic operation (+, -, *, /) depend on the user input.

# Assignment 4
• Using external interrupt make two push buttons of rising edge as interrupt initialization.
• Make three LEDs as output
• When you press the first push button the first led is on, and when you press it again then the two LEDs are on, and when pressed for the third time, three LEDs are on.
• The second push button decreases the number of LEDs on, if three LEDs are on, they will be two, and this way until there are no LEDs on when you press it again, it will do nothing.

# Assignment 5
• INIT your LCD in 4 bits mode and INIT ADC driver.
• Connect the Potentiometer to the ADC pin and then calculate the volt produced by changing the Potentiometer value.
• Present the volte value in mV on the LCD

# Assignment 6 (soon)
• Init PWM in fast mode and ADC.
• Connect the DC motor on the PWM pin and the Potentiometer on the ADC pin.
• Make a program that changes the DC motor speed by changing the potentiometer value.

# Assignment 7
• Init UART.
• Make a LED as OUTPUT.
• Make a simple code that takes a value from the user by using the virtual terminal on proteus or by using the Bluetooth module that’s included in your kit components.
• When the user sends 1 the LED will be ON and when the user sends 0 the LED will be OFF.


# Assignment 8
• By using two microcontrollers connected by SPI communication Protocol, the first microcontroller will be used for pressing a pushbutton that will send a signal to the second microcontroller.
• The second microcontroller will receive a signal from the first microcontroller and when received, a LED will be turned on, and will send a signal to the first to print on the LCD “led is on”.