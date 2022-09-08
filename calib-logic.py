#These variables will most likely be on the .ino program

t1 = int()
voltage = float()
lastVoltage = voltage

while t1 < 3:
    voltage = float(input("Actual voltage "))

    if voltage >= (lastVoltage - (lastVoltage / 10)) and voltage <= (lastVoltage + (lastVoltage / 10)):
        t1 += 1
        print("Pass", t1)

    else:
        t1 = 0
        print("Reset", t1)

    lastVoltage = voltage

print("Calibration concluded")
