//8. Crie uma função que irá converter de Celsius para Fahrenheit
function celsiusToFahrenheit(celsius){
    const fahrenheit = celsius * 1.8 + 32;
    return fahrenheit;
}
const celsius = 20;

console.log(celsius + "ºC é "+ celsiusToFahrenheit(celsius) + "ºF")