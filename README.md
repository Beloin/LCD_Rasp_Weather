# Weather Station with Raspberry PI Zero 2W

In this project was implemented a simple Temperature and Humidity station using Raspberry PI Zero 2W
and a LCD display.

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


### WeatherStatus

There's an `interface` that dictates the way the weather is acquired. The data will be scoped in a single
struct named `WeatherInfo`.

<div style="display: grid; grid-template-columns: 1fr 1fr 1fr; column-gap: 20px; place-items: center;">
    <img src="./docs/Weather_UML.png" alt="Weather UML">
</div>