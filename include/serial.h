#ifndef _SERIAL_H_
#define _SERIAL_H_

#define COM1 0x03f8

void serial_setup();
unsigned char serial_read_byte();
void serial_write_byte(unsigned char);

#endif
