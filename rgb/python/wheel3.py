import sys
import signal
import struct
from PyQt4 import QtGui
import pyqtgraph as pg
from lib.connect_arduino import connect_arduino

def main():
    app = QtGui.QApplication([])
    win = QtGui.QMainWindow()
    btn = pg.ColorButton()
    win.setCentralWidget(btn)
    win.show()

    arduino = connect_arduino()

    def change(btn):
        r, g, b, a = btn.color().getRgb()
        arduino.write(b'\n')
        arduino.write(struct.pack('BBB', r, g, b))

    btn.sigColorChanging.connect(change)

    # start main loop
    if sys.flags.interactive != 1:
        app.exec_()

if __name__ == '__main__':
    signal.signal(signal.SIGINT, signal.SIG_DFL)
    main()
