import platform
from glob import glob

import serial

__all__ = ['connect_arduino']

def connect_arduino(port=None, rate=9600):
    if port is None:
        port = guess_serial_port()
        print('Guessing serial port: ', port)
    return serial.Serial(port, rate)


def serial_port_patterns():
    system = platform.system()
    if system == 'Linux':
        return ['/dev/ttyACM*', '/dev/ttyUSB*']
    if system == 'Darwin':
        return ['/dev/tty.usbmodem*', '/dev/tty.usbserial*']
    raise NotImplementedError("Not implemented for Windows")


def list_serial_ports():
    ports = []
    for p in serial_port_patterns():
        matches = glob(p)
        ports.extend(matches)
    return ports


def guess_serial_port():
    ports = list_serial_ports()
    if ports:
        return ports[0]
    raise ValueError('No ports found')


