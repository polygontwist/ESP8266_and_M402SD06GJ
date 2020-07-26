Beispiel um einen ESP an einem M402SD06GJ VFD per Serial1 anzuschließen.
<img src="https://raw.githubusercontent.com/polygontwist/ESP8266_and_M402SD06GJ/master/esp8255_vfd_m402sd06gj.jpg" width="640" alt="M402SD06GJ VFD">

Vom ESP wird der Pin GPIO2 benutzt (TX1) - es wird als 2. serielle Schnittstelle (Serial1) angesprochen.
Am M402SD06GJ liegt Pin 2, 4, 6 und 16 auf 5V. Pin 4, 8, 10, 12, 14 auf GND.
Pin 19 ist der serielle Eingang (RXD). Pin 20 (BUSY) benutze ich nicht - er würde sonst die Empfangsbereitschaft signalisieren. Der Rest bleibt auch offen.

J1 und J3 habe ich am Display geschlossen, damit kann man das Display mit 15625 Baud ansprechen.

<img src="https://raw.githubusercontent.com/polygontwist/ESP8266_and_M402SD06GJ/master/frizing.jpg" width="417" alt="Frizing Schema">
