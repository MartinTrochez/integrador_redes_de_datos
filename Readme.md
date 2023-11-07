# Trabajo Integrador - Hidroponia Utilizando Arduino

**Cátedra: Redes de Datos**

**Docente: Dr. Marcelo Julio Marinelli**

**Carrera: Ingeniería en Sistemas de Información - Comisión "U"**

## Elementos utilizados:
- Arduino Mega 2560
- DHT11
- Rele

## Funcionamiento
Se una variable deltaK que varia según los valores de las temperatura y la humedad.

### Condiciones Normales
deltaK se mantiene constante.
- Temperatura normal es entre 17°C y 25°C 
- Humedad normal es entre 50% y 60%

### Condiciones de Alta Temperatura y Alta Humedad
deltaK disminuye.
- Humedad alta --> mayor a 60%;
- Temperatura alta --> mayor a 25°C;

### Condiciones de Baja Temperatura y Baja Humedad
deltaK aumenta.
- Temperatura baja --> menor a 17°C;
