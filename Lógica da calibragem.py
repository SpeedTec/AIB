#These variables will most likely be on the .ino program

t1 = int()
voltage = float()
lastVoltage = voltage

while t1 < 3:
    voltage = float(input("Digite a tensão: "))

    if voltage >= (lastVoltage - (lastVoltage / 10)) and voltage <= (lastVoltage + (lastVoltage / 10)):
        t1 += 1
        print("Passou", t1)

    else:
        t1 = 0
        print("Não passou", t1)

    lastVoltage = voltage

print("Calibragem concluída")