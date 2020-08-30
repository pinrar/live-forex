# -*- coding: utf-8 -*-
"""
Created on Sun Aug 30 01:48:33 2020

@author: pinrar
"""
import requests
import bs4
from bs4 import BeautifulSoup
import time
import serial

ser = serial.Serial('COM5', 9600) #change to your port and baud rate

def parseRate():
    r=requests.get('https://finance.yahoo.com/quote/USDTRY=X/')
    soup = bs4.BeautifulSoup(r.text,"lxml")
    price = soup.find("span",{'class':'Trsdu(0.3s) Fw(b) Fz(36px) Mb(-4px) D(ib)'}).text
    kur = price + " " #this is basically the stop sign for Arduino serial
    return kur

def tellBoard():
    toldya  = str(parseRate())
    ser.write(toldya.encode())
    print("Just sent this: "+toldya) #this is not really necessary but I like keeping an eye on the shell

while True:
    tellBoard()
    time.sleep(2) 
