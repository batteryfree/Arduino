function interrupt1(level)
    if (level==0) and (gpio.read(1)==0) then
        pool=pool+1
    else 
        pool=0        
    end
    if pool==2000 then
       conn=net.createConnection(net.TCP)
       conn:connect(333,"20.20.0.11")
       conn:send('buzzer on')
   end
end
function interrupt2(level)
    if (level==0) and (gpio.read(2)==0) then
        pool=pool+1
    else 
        pool=0        
    end
    if pool==2000 then
       conn=net.createConnection(net.TCP)
       conn:connect(333,"20.20.0.12")
       conn:send('buzzer on')
   end
end
function interrupt3(level)
    if (level==0) and (gpio.read(3)==0) then
        pool=pool+1
    else 
        pool=0        
    end
    if pool==2000 then
       conn=net.createConnection(net.TCP)
       conn:connect(333,"20.20.0.13")
       conn:send('buzzer on')
   end
end
function interrupt4(level)
    if (level==0) and (gpio.read(4)==0) then
        pool=pool+1
    else 
        pool=0        
    end
    if pool==2000 then
       conn=net.createConnection(net.TCP)
       conn:connect(333,"20.20.0.10")
       conn:send('buzzer on')
   end
end

gpio.trig(1,"low", interrupt1)
gpio.trig(2,"low", interrupt2)
gpio.trig(3,"low", interrupt3)
gpio.trig(4,"low", interrupt4)


