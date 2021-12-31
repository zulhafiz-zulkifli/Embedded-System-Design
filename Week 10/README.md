# Week 10 Examples (Interfacing with Motors)

## Example 1, 2, 3

Use Blinky class to flash LED ON and OFF for 1s.

Use Blinky class to generate PWM signal at PB5 with 200µs on and 300µs off time.

Use Blinky class to generate PWM signal at PB5 with 100µs on and 200µs off time.

<details>
<summary>CIRCUIT DIAGRAM</summary>
<img src="./Ex 3/Circuit Diagram.PNG">
</details>

<details>
<summary>PROTOTYPE</summary>
<img src="./Ex 3/Prototype.jpg">
</details>

## Example 4, 5

Use the DCMotor class to generate a 50Hz PWM waveform at PB0 with 50% duty cycle.

Use the DCMotor class to generate a 1kHz PWM waveform at PB0 with 20% duty cycle.

<details>
<summary>VIDEO</summary>
...
</details>

<details>
<summary>CIRCUIT DIAGRAM</summary>
<img src="./Ex 5/Circuit Diagram.PNG">
</details>

<details>
<summary>PROTOTYPE</summary>
<img src="./Ex 5/Prototype.jpg">
</details>

## Example 6, 7

Drive 4 DC Motors connected to PB0, PB1, PB2 and PB3 with 20%, 40%, 60%, and 80% duty cycles at 500Hz.

Drive 4 DC Motors connected to PB0, PB1, PB2 and PB3 with 20%, 40%, 60%, and 80% duty cycles at 1kHz.

<details>
<summary>VIDEO</summary>
...
</details>

<details>
<summary>CIRCUIT DIAGRAM</summary>
<img src="./Ex 7/Circuit Diagram.PNG">
</details>

<details>
<summary>PROTOTYPE</summary>
<img src="./Ex 7/Prototype.jpg">
</details>

## Example 8

Use PID class and a sensor to continuously adjust the speed of a DC motor as part of a control system. 

<details>
<summary>VIDEO</summary>
...
</details>

<details>
<summary>CIRCUIT DIAGRAM</summary>
<img src="./Ex 8/Circuit Diagram.PNG">
</details>

<details>
<summary>PROTOTYPE</summary>
<img src="./Ex 8/Prototype.jpg">
</details>

## Example 9

4 servo motors are attached to PB0, PB1, PB2 and PB3. Use Servo class to make these servos turn 90° with pulse width of 1.5ms.

<details>
<summary>VIDEO</summary>
...
</details>

<details>
<summary>CIRCUIT DIAGRAM</summary>
<img src="./Ex 9/Circuit Diagram.PNG">
</details>

<details>
<summary>PROTOTYPE</summary>
<img src="./Ex 9/Prototype.jpg">
</details>

## Example 10

A signal pin of a servo motor is attached to PB0. Write a program to make the servo rotate back and forth (sweeping) with the following parameters: Minimum pulse width = 544us, Maximum pulse width = 2400us, Step size = 10us, Delay = 25ms.

<details>
<summary>VIDEO</summary>
...
</details>

<details>
<summary>CIRCUIT DIAGRAM</summary>
<img src="./Ex 10/Circuit Diagram.PNG">
</details>

<details>
<summary>PROTOTYPE</summary>
<img src="./Ex 10/Prototype.jpg">
</details>

## Example 11

4 servo motors are connected to PB0 to PB3. Using Servo and ServoSweeperclasses, write a program to make the 4 servo sweep.

<details>
<summary>VIDEO</summary>
...
</details>

<details>
<summary>CIRCUIT DIAGRAM</summary>
<img src="./Ex 11/Circuit Diagram.PNG">
</details>

<details>
<summary>PROTOTYPE</summary>
<img src="./Ex 11/Prototype.jpg">
</details>

## Example 12, 13, 14, 15

Rotate the stepper motor  in clockwise direction at a rate of 200 steps/s in wave drive mode.

Rotate the stepper motor  in counter-clockwise direction at a rate of 500 steps/s in wave drive mode.

Rotate the stepper motor  in clockwise direction at a rate of 500 steps/s in full drive mode.

Rotate the stepper motor  in counter-clockwise direction at a rate of 250 steps/s in half-step drive mode.

<details>
<summary>VIDEO</summary>
...
</details>

<details>
<summary>CIRCUIT DIAGRAM</summary>
<img src="./Ex 15/Circuit Diagram.PNG">
</details>

<details>
<summary>PROTOTYPE</summary>
<img src="./Ex 15/Prototype.jpg">
</details>

## Example 16

Two unipolar stepper motors are connected to PORTB (0 to 3) and PORTD (0 to 3). 
Motor 1: clockwise, 500 steps/s, full-step drive mode. 
Motor 2: counter-clockwise, 500 steps/s, half-step drive mode. 

<details>
<summary>VIDEO</summary>
...
</details>

<details>
<summary>CIRCUIT DIAGRAM</summary>
<img src="./Ex 16/Circuit Diagram.PNG">
</details>

<details>
<summary>PROTOTYPE</summary>
<img src="./Ex 16/Prototype.jpg">
</details>