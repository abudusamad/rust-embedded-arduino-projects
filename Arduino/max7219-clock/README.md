---
title: wokwi-arduino-uno Reference
sidebar_label: wokwi-arduino-uno
---

Arduino Uno is the most popular board in the Arduino family. It is powered by the ATmega328p chip, which has 32K bytes of Flash program memory, 2k bytes of SRAM and 1K bytes of EEPROM.

<wokwi-arduino-uno />


![Build](./assets/R.jpg?raw=true)


## Pin names

Pins 0 to 13 are digital GPIO pins. Pins A0 to A5 double as analog input pins, in addition to being digital GPIO pins.

There are three ground pins: GND.1, which is on top of the board, next to pin 13, and GND.2/GND.3, which are on the bottom.

Pins VIN / 5V are connected to the positive power supply.

Pins 3.3V / IOREF / AREF / RESET are not available in the simulation.

Digital pins 3, 5, 6, 9, 10, and 11 have hardware PWM support.

Some of the digital pins also have additional functions:

| Pin | Function           | Signal           |
| --- | ------------------ | ---------------- |
| 0   | Serial (USART)     | RX               |
| 1   | Serial (USART)     | TX               |
| 2   | External interrupt | INT0             |
| 3   | External interrupt | INT1             |
| 10  | SPI                | SS (Chip select) |
| 11  | SPI                | MOSI             |
| 12  | SPI                | MISO             |
| 13  | SPI                | SCLK (Clock)     |
| A4  | I2C                | SDA (Data)       |
| A5  | I2C                | SCL (Clock)      |

### On board LEDs

The board includes four LEDs:

| LED | Function                                             |
| --- | ---------------------------------------------------- |
| L   | Connected to digital pin 13                          |
| RX  | Serial RX Activity                                   |
| TX  | Serial TX Activity                                   |
| ON  | Power LED. Always on while the simulation is running |

In general, only the "L" LED can be controlled by the user's code. You can use the `LED_BUILTIN` constant to reference it from your code:

```cpp
pinMode(LED_BUILTIN, OUTPUT);
digitalWrite(LED_BUILTIN, HIGH);
```

See [Blink](https://wokwi.com/projects/344891652101374548) for a complete code example.

## Attributes

| Name      | Description                                                             | Default value |
| --------- | ----------------------------------------------------------------------- | ------------- |
| frequency | MCU clock frequency, in hertz. Common values: "8m", "16m", and "20m" \* | "16m"         |

\* Many Arduino libraries assume 16 MHz clock frequency. Changing the clock frequency will void your warranty!

## Simulation features

The Arduino Uno is simulated using the [AVR8js Library](https://github.com/wokwi/avr8js). The table below summarizes the status of features:

| Peripheral        | Status | Notes                                                                  |
| ----------------- | ------ | ---------------------------------------------------------------------- |
| Processor         | ✔️     |                                                                        |
| GPIO              | ✔️     | Including External/Pin Change Interrupts                               |
| 8-bit timers      | ✔️     | Timer0, Timer2                                                         |
| 16-bit timer      | ✔️     | Timer1                                                                 |
| Watchdog Timer    | ✔️     | [Usage example](https://wokwi.com/projects/309372800631571009) |
| USART             | ✔️     |                                                                        |
| SPI               | 🟡     | Master mode only                                                       |
| I2C               | 🟡     | Master mode only                                                       |
| EEPROM            | ✔️     |                                                                        |
| Clock Prescale    | ✔️     |                                                                        |
| ADC               | ✔️     | Used by analogRead()                                                   |
| Analog Comparator | ❌     |                                                                        |
| GDB Debugging     | ✔️     | See the [GDB Debugging Guide](../gdb-debugging)                        |

Legend:  
✔️ Simulated  
🟡 Simulated, but see notes  
❌ Not implemented

If you need any of the missing features, please [open an issue on the AVR8js repo](https://github.com/wokwi/avr8js/issues/new)
or [reach out on Discord](https://wokwi.com/discord).

### Serial Monitor

You can use the Serial Monitor to receive information from your Arduino code, such as debug print. You can also use it to send information to your code, such as textual commands.

For more information and code samples, check out [the Serial Monitor guide](../guides/serial-monitor). It also explains how to configure the Serial monitor, e.g. set the line ending characters.

### Libraries

The simulator supports many popular Arduino libraries. For a complete list, see the [Libraries guides](../guides/libraries).

## Simulator examples

- [Arduino Blink](https://wokwi.com/projects/344891652101374548)




---
title: wokwi-dht22 Reference
sidebar_label: wokwi-dht22
---

Digital Humidity and Temperature sensor.

<wokwi-dht22 />

## Pin names

| Name | Description                     |
| ---- | ------------------------------- |
| VCC  | Positive voltage                |
| SDA  | Digital data pin (input/output) |
| NC   | Not connected                   |
| GND  | Ground                          |

## Attributes

| Name        | Description                                  | Default value |
| ----------- | -------------------------------------------- | ------------- |
| temperature | Initial temperature value (celsius)          | "24"          |
| humidity    | Initial relative humidity value (percentage) | "40"          |

## Controlling the temperature

You can change the temperature and humidity values while the simulation is running.
Click on the DHT22 sensor and a small popup window will open. Use the temperature and
humidity sliders to change the values. Click "Hide" to close the popup window.

:::caution
If you are trying to read this sensor from the ESP32, use the "DHT sensor library for ESPx" library. Other DHT22 libraries may not work reliably on the ESP32. You can use this [example project](https://wokwi.com/projects/322410731508073042) as a starting point.
:::

## Simulator examples

- [DHTlib example](https://wokwi.com/projects/344892337559700051)
- [DHT-sensor-library examples](https://wokwi.com/projects/344892587898831442)
- [DHT22 on the ESP32](https://wokwi.com/projects/322410731508073042)


---
title: wokwi-max7219-matrix Dot Matrix Reference
sidebar_label: wokwi-max7219-matrix
---

import DotMatrix from './wokwi-max7219-matrix.svg';
import DotMatrixChain4 from './wokwi-max7219-matrix-chain-4.svg';

8x8 LED Dot Matrix with MAX7219 Controller

![MAX7219 LED Dot Matrix](wokwi-max7219-matrix.svg)

## Pin names

| Name | Description    |
| ---- | -------------- |
| VCC  | Voltage supply |
| GND  | Ground         |
| DIN  | Data input     |
| CS   | Chip Select    |
| CLK  | Clock input    |
| DOUT | Data output    |

## Attributes

| Name   | Description                                  | Default value |
| ------ | -------------------------------------------- | ------------- |
| chain  | How many units to chain together             | "1"           |
| color  | LED color (when lit)                         | "red"         |
| layout | Matrix connection layout: "parola" or "fc16" | "parola"      |

### Chaining

Each dot matrix units is an 8x8 LED matrix. All the LEDs in the matrix have the same color. You can make the display wider by setting the "chain" attribute. For example, setting "chain" to 4 will chain four dot matrix units horizontally, resulting in 32x8 matrix (four times 8x8 matrix).

If you want to chain units in a custom way (e.g. select a different pixel color for each unit, chain them vertically, etc), connect the DOUT pin of one unit to the DIN pin of the next unit. You also need to connect the CLK / CS pins of the units together. See [32x32 LED Matrix Tunnel](https://wokwi.com/projects/318864638990090834) for an example.

### Matrix layout

There are several type of matrix layout, based on the commonly available modules. You can set the "layout" property to choose the desired pixel layout:

- "parola" - See the [Parola documentation](https://majicdesigns.github.io/MD_MAX72XX/page_parola.html) for information about the layout of these modules
- "fc16" - The FC-16 modules are available from EBay and AliExpress. They usually come in a chain of four 8x8 matrices, so they have 32x8 pixels in total.

Choosing the wrong layout will cause your text / drawing to be rotated and / or mirrored.

### Examples

| Result                                           | Attrs                  |
| ------------------------------------------------ | ---------------------- |
| <DotMatrix style={{'--pixel-color': 'green'}} /> | `{ "color": "green" }` |
| <DotMatrixChain4/>                               | `{ "chain": "4" }`     |
