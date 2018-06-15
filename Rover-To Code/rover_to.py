import serial
import os

try:
    ser = serial.Serial("dev/ttyS0",9600)
    control = serial.Serial("dev/ttyACM0", 9600)
    arduino = serial.Serial("dev/ttyUSB0", 9600)

    while True:

        data = ser.read()

        if(data == "1"): #muñeca giro der
            control.write("")
        elif(data == "2"): #muñeca giro izq
            control.write("")
        elif(data == "3"): #muñeca abajo
            control.write("")
        elif(data == "4"): #muñeca arriba
            control.write("")
        elif (data == "5"):
            control.write("")
        elif (data == "6"):
            control.write("")
        elif (data == "7"):
            control.write("")
        elif (data == "8"):
            control.write("")
        elif (data == "9"):
            control.write("")
        elif (data == "-"):
            control.write("")
        elif (data == "."):
            control.write("")
        elif (data == "_"):
            control.write("")
        elif (data == ","):
            control.write("")
        elif (data == "*"):
            control.write("")
        elif (data == "/"):
            control.write("")
        elif (data == ";"):
            control.write("")
        elif (data == "a"):
            control.write("w")
        elif (data == "b"):
            control.write("s")
        elif (data == "c"):
            control.write("d")
        elif (data == "d"):
            control.write("a")
        elif (data == "%"):
            control.write("")
        elif (data == "&"):
            control.write("")
        elif (data == ">"):
            control.write("e")
        elif (data == "<"):
            control.write("r")
        elif (data == "n"):
            control.write("")
        elif (data == "C"):
            control.write("")
        elif (data == "G"):
            control.write("")
        elif (data == "s"):
            control.write("")
        elif (data == "Q"):
            control.write("")

except serial.SerialException:
    try:
        ser = serial.Serial("dev/ttyS0", 9600)
        control = serial.Serial("dev/ttyACM1", 9600)
        arduino = serial.Serial("dev/ttyUSB0", 9600)

        while True:

            data = ser.read()

            if (data == "1"):
                control.write("a")
            elif (data == "2"):
                control.write("b")

    except serial.SerialException:
        pass
