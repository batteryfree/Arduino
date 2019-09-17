gpio.mode(1,gpio.INPUT, gpio.PULLUP)
gpio.mode(2,gpio.INPUT, gpio.PULLUP)
gpio.mode(3,gpio.INPUT, gpio.PULLUP)
gpio.mode(4,gpio.INPUT, gpio.PULLUP)
wifi.setmode(wifi.STATION)
wifi.sta.setip({ip="20.20.0.14",netmask="255.255.255.0",gateway="20.20.0.1"}) 
wifi.sta.config("kipia","F4gLNf57")
wifi.sta.connect()
dofile ("main.lua")


