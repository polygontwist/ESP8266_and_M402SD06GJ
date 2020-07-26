Beispiel um einen ESP an einem M402SD06GJ VFD per Serial1 anzuschließen.

Vom ESP wird der Pin GPIO2 benutzt (TX1) - es wird als 2. serielle Schnittstelle (Serial1) angesprochen.
Am M402SD06GJ liegt Pin 2, 4, 6 und 16 auf 5V. Pin 4,8, 10, 12, 14 auf GND.
Pin 19 ist der serielle Eingang (RXD). Pin 20 (BUSY) benutze ich nicht - er würde sonst die Empfangsbereitschaft signalisieren. Der Rest bleibt auch offen.
