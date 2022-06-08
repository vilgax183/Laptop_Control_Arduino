
import  time
import pyautogui
import serial.tools.list_ports

ser = serial.Serial()
port=serial.tools.list_ports.comports()
print     (port[0])
count=1

ser  .port = 'COM4'
ser.baudrate = 9600
ser.open()
time.sleep(2)


while (True):
    dat = str(ser.readline())
    print(dat)
    print("")
    if "Pause/Play" in dat:
        pyautogui.typewrite(['space'], 0.2)
    if "down" in dat:
        pyautogui.press("down")
    if "up" in dat:
        pyautogui.press("up")
    if "Forward" in dat:
        pyautogui.hotkey("right")
    if "Rewind" in dat:
        pyautogui.press("left")
    if "screenshot" in dat:
        myScreenshot = pyautogui.screenshot()
        alpha=str(count)
        myScreenshot.save(r"C:\pyss\screenshot_"+ alpha +".png")
        count=count+1

    dat=""