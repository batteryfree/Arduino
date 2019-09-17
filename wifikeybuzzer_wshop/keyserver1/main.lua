pool = 0
function interrupt1(level)
    if (level==0) and (gpio.read(1)==0) then
        pool=pool+1
    else 
        pool=0        
    end
    if pool==2000 then
       conn=net.createConnection(net.TCP)
       conn:connect(333,"20.20.0.3")
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
       conn:connect(333,"20.20.0.4")
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
       conn:connect(333,"20.20.0.5")
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
       conn:connect(333,"20.20.0.6")
       conn:send('buzzer on')
   end
end
function interrupt5(level)
     if (level==0) and (gpio.read(5)==0) then
        pool=pool+1
    else 
        pool=0        
    end
    if pool==2000 then
       conn=net.createConnection(net.TCP)
       conn:connect(333,"20.20.0.7")
       conn:send('buzzer on')
   end
end
function interrupt6(level)
    if (level==0) and (gpio.read(6)==0) then
        pool=pool+1
    else 
        pool=0        
    end
    if pool==2000 then
       conn=net.createConnection(net.TCP)
       conn:connect(333,"20.20.0.8")
       conn:send('buzzer on')
   end
end
function interrupt7(level)
    if (level==0) and (gpio.read(7)==0) then
        pool=pool+1
    else 
        pool=0        
    end
    if pool==2000 then
       conn=net.createConnection(net.TCP)
       conn:connect(333,"20.20.0.9")
       conn:send('buzzer on')
   end
end


gpio.trig(1,"low", interrupt1)
gpio.trig(2,"low", interrupt2)
gpio.trig(3,"low", interrupt3)
gpio.trig(4,"low", interrupt4)
gpio.trig(5,"low", interrupt5)
gpio.trig(6,"low", interrupt6)
gpio.trig(7,"low", interrupt7)


print("Started")
