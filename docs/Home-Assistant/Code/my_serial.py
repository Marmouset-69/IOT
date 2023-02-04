import serial
#Serial takes these two parameters: serial device and baudrate
ser = serial.Serial('/dev/ttyUSB0', 9600)

while True:
    data = ser.readline()
    d=data.decode()
    dd = d.rstrip("\n")
    ddd=dd.split(';')

    count = ddd[0]
    id = ddd[1]
    temp = str(float(ddd[2]) / 10)
    lumi = str(float(ddd[3]) / 10)
    humi = ddd[4]

    print(f"\ncount `{count}`")
    print(f"id `{id}`")
    print(f"Temp `{temp}°C`")
    print(f"Lumi `{lumi}`")
    print(f"Humi `{humi}`")
