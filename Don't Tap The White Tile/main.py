# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

import pyautogui
import time

import pyautogui

pyautogui.FAILSAFE = True
time.sleep(1)

while True:
    loc = pyautogui.locateCenterOnScreen('arcade.png')
    if loc == None:
        continue
    pyautogui.moveTo(x=loc.x, y=loc.y, tween=pyautogui.linear)
    pyautogui.click()
    break

time.sleep(1)

#im2 = pyautogui.screenshot(region=(1160,280,200,200))
#im2.save('fast.png')
loc = pyautogui.locateCenterOnScreen('fast.png')
pyautogui.moveTo(x=loc.x, y=loc.y, tween=pyautogui.linear)
pyautogui.click()

time.sleep(1)
im = pyautogui.screenshot(region=(890, 700, 480, 100))
im.save('test.png')

for i in range(40, 430, 120):
    px1 = im.getpixel((i, 50))
    px2 = im.getpixel((i, 52))
    if px1[0] < 10 and px2[0] < 10:
        pyautogui.click(i + 908, 50 + 664)


while True:
    im = pyautogui.screenshot(region=(908, 664, 480, 100))
    im.save('test.png')
    # (60, 50), (180,50), (300, 50), (420, 50)

    for i in range(40, 430, 120):
        px1 = im.getpixel((i, 50))
        px2 = im.getpixel((i, 52))
        if px1[0] < 10 and px2[0] < 10:
            pyautogui.click(i + 908, 50 + 664)
# Press the green button in the gutter to run the script.


"""
while True:
    loc = pyautogui.locateCenterOnScreen('black.png')
    if loc == None:
        continue
    pyautogui.moveTo(x=loc.x, y=loc.y, tween=pyautogui.linear)
    pyautogui.click()
"""

if __name__ == '__main__':
    pass

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
