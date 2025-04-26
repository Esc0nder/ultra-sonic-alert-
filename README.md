this uses discord web hooks and esp32 and an ultra sonic sensor 
i came up with this idea cause my kitten keeps escaping out my backdoor its quite a simple project tbh
but i still thought it might be worth posting anyway

what youll need:
esp32(i use the esp-wroom-32 but should work on othera)
HC-SR04 ultrasonic sensor 
jumper/dupont wires
optional:
LED

pinout:
ultrasonic sensor to esp
VCC -> 5V
TRIG -> G5
ECHO -> G18
GND -> GND
optional:
led to esp
led+ -> G2
led- -> GND
