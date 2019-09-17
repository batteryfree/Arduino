pool = 0
function pin1cb(level)
   -- print("level")
   -- print(level)
   -- print("gpio")
   -- print(gpio.read(2))

if (level==0) and (gpio.read(2)==0) then
   pool=pool+1
else 
    pool=0        
end
if pool==200 then
       print("Onjjjjjjjjjjjjjjjjjjjjjjj1")
end
end
gpio.trig(2, "low",pin1cb)