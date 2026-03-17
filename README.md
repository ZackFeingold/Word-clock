# Word Clock

A custom-built word clock designed from scratch using Fusion 360, an Arduino microcontroller, an LED matrix and a real-time clock module.

Instead of displaying time numerically, the clock lights up words to show the current time in natural language.

## Project Overview

The goal of this project was to design and build a complete physical product combining:
- CAD design
- electronics assembly
- soldering
- embedded programming

I designed the front plate in Fusion 360, built the internal LED layout, wired and soldered the electronics, and wrote the Arduino C++ code to control the illuminated words based on data from a real-time clock module.

## What I Built

I:
- designed the front face in Fusion 360
- built the internal LED arrangement
- wired and soldered the electronics
- connected a real-time clock module
- wrote the Arduino code to convert time into the correct illuminated word pattern

## Hardware

- Arduino
- LED matrix / LEDs
- Real-time clock module
- custom front plate
- wiring and soldered connections
- enclosure / backing structure

## Software Logic

The control logic:
1. reads the current time from the RTC module
2. converts the numerical time into a phrase
3. activates the LED combination corresponding to the required words

This required mapping time values to specific display states and ensuring the correct LEDs illuminated consistently.

## Engineering Challenges

Key challenges included:
- designing the front plate so the words aligned correctly with the LEDs
- managing wiring and soldering across the display
- mapping time logic accurately to physical output
- integrating the electronics cleanly into a working enclosure

## Results

The final build functions as a working word clock, displaying the correct words based on real-time data from the RTC module.

## What I Learned

This project gave me practical experience with:
- CAD design in Fusion 360
- soldering and electronics assembly
- embedded C++ on Arduino
- hardware/software integration
- translating logical state into physical output

## Future Improvements

Potential next steps:
- cleaner enclosure design
- brightness control
- improved power management
- support for alternative display layouts
- modularising the Arduino code

![Front of clock](<Image 1.jpg>)
![Inside of clock](<Image 2.jpg>)
