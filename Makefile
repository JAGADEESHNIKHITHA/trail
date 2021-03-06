CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0
LDFLAGS= -nostdlib -T stm32_ls.ld -Wl,-Map=finalled.map
source= main.c stm32f407xx_gpio_driver.c stm32_startup.c
BOARD = STM32F4-Discovery
MCU = STM32F407VG
TARGET = finalled.elf
all:main.o stm32f407xx_gpio_driver.o stm32_startup.o finalled.elf
gitall:add push

stm32f407xx_gpio_driver.o:stm32f407xx_gpio_driver.c
	$(CC) $(CFLAGS) -o $@ $^

main.o:main.c
	$(CC) $(CFLAGS) -o $@ $^

stm32_startup.o:stm32_startup.c
	$(CC) $(CFLAGS) -o $@ $^

finalled.elf:main.o stm32f407xx_gpio_driver.o stm32_startup.o
	$(CC) $(LDFLAGS) -o $@ $^

run: ${TARGET}
	-qemu-system-gnuarmeclipse.exe -M ${BOARD} -mcu ${MCU} --image ${TARGET}

clean:
	rm -rf *.o *.elf *.map 

analysis:
	cppcheck --enable=all --inconclusive $(source)

git:
	git init

add:
	git add .
	git commit -m="$m"
	
status:
	git status
	
clone:
	git clone "$c"
	
push:
	git push

pull:
	git pull
