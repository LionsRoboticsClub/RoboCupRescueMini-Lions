import serial
import os

try:
    ser = serial.Serial("dev/ttyS0",9600)
    control = serial.Serial("dev/ttyACM0", 9600)
    arduino = serial.Serial("dev/ttyUSB0", 9600)

    while True:

        data = ser.read()

        if(data == "1"): #muñeca giro der
            control.write("l")
        elif(data == "2"): #muñeca giro izq
            control.write("j")
        elif(data == "3"): #muñeca abajo
            control.write("i")
        elif(data == "4"): #muñeca arriba
            control.write("k")
        elif (data == "5"):
            control.write("p")
        elif (data == "6"):
            control.write("o")
        elif (data == "7"):
            control.write("u")
        elif (data == "8"):
            control.write("y")
        elif (data == "9"):
            control.write("m")
        elif (data == "-"):
            control.write("n")
        elif (data == "."):
            control.write("z")
        elif (data == "_"):
            control.write("w")
        elif (data == ","):
            control.write("s")
        elif (data == "*"):
            control.write("a")
        elif (data == "/"):
            control.write("d")
        elif (data == ";"):
            control.write("w")
        elif (data == "a"):
            control.write("s")
        elif (data == "b"):
            control.write("a")
        elif (data == "c"):
            control.write("d")
        elif (data == "d"):
            control.write("e")
        elif (data == "%"):
            control.write("r")
        elif (data == "&"):
            control.write("t")
        elif (data == ">"):
            control.write("x")
        elif (data == "<"):
            control.write("f")
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
