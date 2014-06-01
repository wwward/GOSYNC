GOSYNC
======

----------
3 Modules:
----------

Teensy Sandwitch Module: I2C communication and button

Teensy Frame/Trigger Module: frame sync, trigger

Due scanline Module: scanline sync


------------
Conncection:
------------
Teensy Sandwitch  ----->  Teensy Frame/Trigger Module
7                         7
8                         8
       
Button            ----->  Teensy Sandwitch
white                     6
    
------------
API
------------
I2C clock                 19 Teensy Sandwitch
I2C data                  18 Teensy Sandwitch
I2C stage control         13 Teensy Sandwitch
Frame Sync                12 Teensy Frame/Trigger Module
Trigger                   11 Teensy Frame/Trigger Module
Scanline Sync             13 Due
                   

Ground                  
Connection indicator
