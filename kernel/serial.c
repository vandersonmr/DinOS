#include "x86.h"
#include "serial.h"

void serial_setup() {

    outb(COM1 + 1, 0x00);
    outb(COM1 + 3, 0x80);
    outb(COM1 + 0, 0x03);
    outb(COM1 + 1, 0x00);
    outb(COM1 + 3, 0x03);
    outb(COM1 + 2, 0xc7);
    outb(COM1 + 4, 0x0b);

}

static int serial_received() {
    return inb(COM1 + 5) & 1;
}

unsigned char serial_read_byte() {
    while(serial_received() == 0);
    return inb(COM1);
}

static int serial_ready_to_transmit() {
    return inb(COM1 + 5) & 0x20;
}

void serial_write_byte(unsigned char byte) {
    while(serial_ready_to_transmit() == 0);
    outb(COM1, byte);
}
