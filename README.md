# Weather Station with Raspberry PI Zero 2W

In this project was implemented a simple Temperature and Humidity station using Raspberry PI Zero 2W, an LCD and DHT11.

In order to run both in Linux system and Raspberry PI, it was created conditional compilation
explicit in [Code Structure](#Code-Structure) and implemented in `PeripheralFactory`. So while using Linux
is used the `ConsoleDisplay` implementation, and in RPI0 is used `LCDDisplay`. Also, to have the Weather
data is implemented `RandomWeatherGeneratorTask` and in RPI0 `DHT11Sensor`.

## Dependencies

- [pigpio](http://abyz.me.uk/rpi/pigpio/cif.html) (Usually comes pre-installed on pi boards)
- pthreads: `sudo apt-get install libpthread-stubs0-dev`
    - Make DHT11 Workers.
- spdlog: `pacman -S spdlog` or in apt based system `sudo apt install libspdlog-dev`
    - Simple and Fast Logging Library

## Schematics

<div style="display: grid; grid-template-columns: 1fr 1fr 1fr; column-gap: 20px; place-items: center;">
    <img src="./docs/kicad_sche.png" alt="Kicad Schematcis">
</div>

# Code Structure

### Display

There's an `interface` that dictates the way all the data will be set on display: the `TextBasedDisplay`

<div style="display: grid; grid-template-columns: 1fr 1fr 1fr; column-gap: 20px; place-items: center;">
    <img src="./docs/Display_UML.png" alt="TextBasedDisplay UML">
</div>

### WeatherStatusTask

There's an `interface` that dictates the way the weather is acquired. The data will be scoped in a single
struct named `WeatherInfo`.

<div style="display: grid; grid-template-columns: 1fr 1fr 1fr; column-gap: 20px; place-items: center;">
    <img src="./docs/Weather_UML.png" alt="Weather UML">
</div>

## References

- [Controle de GPIO da Raspberry Pi utilizando a linguagem C](https://embarcados.com.br/gpio-da-raspberry-pi-linguagem-c/)
- [bcm2835](http://www.airspayce.com/mikem/bcm2835/)
- [pigpio](http://abyz.me.uk/rpi/pigpio/index.html)
