# NRF24L01 Wireless Communication - Arduino
Wireless transmitter and receiver using NRF24L01+PA+LNA modules 
with Arduino Uno and Nano. Receiver triggers a buzzer on signal receipt.

## Hardware
- Arduino Uno (RX)
- Arduino Uno (TX)
- 2x NRF24L01+PA+LNA SMA modules
- 2x ASM1117 Voltage converter
- Buzzer on pin 4

## Wiring
|Component| Pin  | Connects To | 
| ------- | ---- | ----------- | 
| Arduino | 5V   | AMS1117 VIN |
| Arduino | GND  | AMS1117 GND |
| AMS1117 | VOUT | NRF24 VCC   |
| AMS1117 | GND  | NRF24 GND   |
| Arduino | 7    | NRF24 CE    |
| Arduino | 8    | NRF24 CSN   |
| Arduino | 11   | NRF24 MOSI  |
| Arduino | 12   | NRF24 MISO  |
| Arduino | 13   | NRF24 SCK   |

ASM1117 converts Arduino's onboard 5V to the NRF module's required 3.3V. We generally refrain from using Arduino's 3.3V pin as Arduino's on-board voltage regulator cannot reliably provide enough current during radio transmissions, which results in the NRF module not functioning properly.
 
## Libraries
- RF24 by TMRh20
