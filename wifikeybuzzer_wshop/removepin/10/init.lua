gpio.mode(2, gpio.OUTPUT)
gpio.write(2, gpio.LOW)
wifi.setmode(wifi.STATION)
wifi.sta.setip({ip="20.20.0.12",netmask="255.255.255.0",gateway="20.20.0.1"}) 
wifi.sta.config("kipia","F4gLNf57")
wifi.sta.connect()
dofile ("main.lua")