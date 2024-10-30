Usage Instructions:

Use the Arduino IDE to upload the program.

For the master node, use the official Arduino Nano 33 BLE (or any Arduino board with hardware I2C interface) and upload the Master program.

For the slave node, use an Arduino ATmega328P chip. Use a USBtinyISP downloader with a 3P dual-row 1.25mm pitch test clip to upload the program. In the Arduino IDE, under the board options, install the MiniCore library. After installation, set the clock to "external 8MHz". When using the board for the first time, select "Burn Bootloader" first, and for regular uploads, choose "Upload Using Programmer".

First, upload the calibration code [Calibration_mpu6050toEEPROM.ino] to the slave node. Place the IMU on a flat surface for calibration. When the slave node's LED starts blinking rapidly, calibration is complete, and the data is saved automatically to the chip's EEPROM. Then, upload the [Slave.ino] program.
