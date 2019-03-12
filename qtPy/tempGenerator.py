import numpy as np 
import pandas as pd




SIZER = 1000


def roomTempGen(roomTemp):
    temp = np.ones(SIZER)*roomTemp
    return temp


def cooler(roomTemp, nitrogenTemp):
    temp = np.linspace(roomTemp, nitrogenTemp, SIZER/25)
    return temp

def nitrogenGenerator(nitrogenTemp):
    temp = np.ones(SIZER)*nitrogenTemp
    return temp



def createForwardSignal(roomTemp, nitrogenTemp):
    return np.array(list(roomTempGen(roomTemp) ) + list(cooler(roomTemp, nitrogenTemp)) + list(nitrogenGenerator(nitrogenTemp)))



def createBackSignal(roomTemp, nitrogenTemp):
    return np.array( list(cooler( nitrogenTemp, roomTemp)) +list(roomTempGen(roomTemp) ) )


roomTemp = 22
nitrogenTemp = - 65

creator = list(createForwardSignal(roomTemp, nitrogenTemp))+list(createBackSignal(roomTemp, nitrogenTemp))
creator = np.array(creator)
timer = np.arange(0,len(creator), 1)
noise = np.random.normal(0, 0.15, len(creator))

data = {'time':timer, 'temp':creator+noise}
df = pd.DataFrame(data=data)
df.to_csv("testDataSet.csv")

print("DOne")











