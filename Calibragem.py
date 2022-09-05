t1 = 0
voltage = float(input("Digite a tensão: "))
lastVoltage = voltage

while t1 < 3:
    if voltage >= (lastVoltage - (lastVoltage / 10)) and voltage <= (lastVoltage + (lastVoltage / 10)):
        t1 += 1
        print("Passou")
    else:
        t1 = 0
        print("Não passou")
        lastVoltage = 0
        voltage = 0

    voltage = float(input("Digite a tensão: "))
    lastVoltage = voltage

print("Calibragem concluída")
