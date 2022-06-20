:: Xiaolaba dump AVR chips script 
:: Target = LoRa_fuse.txt 
:: MCU    = ATmega328PB 
:: 
 
set MCU=ATmega328PB
set TARGET=IFS_LoRa_328PB_testing.ino_atmega328pb_1000000L


set ac=C:\avr8-gnu-toolchain-win32_x86
path %ac%\bin;%ac%\utils\bin;%path%;
avr-gcc.exe -dumpversion
 
set efuse=0xf7
set hfuse=0xd4
set lfuse=0x52
set lock=0x3f
set sig=0x1e,0x95,0x16
 
avrdude -c usbtiny -p %MCU% -U flash:w:%TARGET%.hex:a 
::avrdude -c usbtiny -p %MCU% -U lfuse:w:%lfuse%:m 
::avrdude -c usbtiny -p %MCU% -U hfuse:w:%hfuse%:m 
::avrdude -c usbtiny -p %MCU% -U hfuse:w:%efuse%:m
::pause
::avrdude -c usbtiny -p %MCU% -U hfuse:r:fuse.txt:h 
pause
::avrdude -c usbtiny -p %MCU% -U hfuse:w:%hfuse%:m 
pause