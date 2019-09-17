sv=net.createServer(net.TCP,10)
function receiver(sck, data)
     if  (data) == "buzzer on" then
          gpio.write(2, gpio.HIGH)
     else
          if string.sub (data, 0, 1) == "0" then
               gpio.write(2, gpio.LOW)
          end
     end
end
if sv then
  sv:listen(333, function(conn)
    conn:on("receive", receiver)
     print("Conneting")
  end)
end
print("Started.")
