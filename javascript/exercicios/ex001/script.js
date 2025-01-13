// console.log("Hello World JavaScript!");

// // console
// console.error("Este é um erro")
// console.warn("Este é um aviso")
// console.log("Este é uma mensagem")

// // variáveis
// var x = 10
// // maneiras mais modernas
// let y = 15
// const z = 20

// if (1) {
//     let y = 55
//     console.log(y)
// }

// console.log(x)
// console.log(y)
// console.log(z)

// y = 25

// console.log(y)

// // tipos de dados
// const name = "Matheus"
// console.log(name)
// console.log(typeof name)

// const shirsQty = 4
// console.log(shirsQty)
// console.log(typeof shirsQty)

// const decimal = 12.4
// console.log(decimal)
// console.log(typeof decimal)

// const isApproved = false // true ou false
// console.log(isApproved)
// console.log(typeof isApproved)

// let surname = null
// console.log(surname)
// console.log(typeof surname)

// surname = "Battisti"
// console.log(surname)
// console.log(typeof surname)

// let age
// console.log(age)
// console.log(typeof age)

// age = 30
// console.log(age)
// console.log(typeof age)

// const languages = ["JavaScript", "PHP", "Python"]
// console.log(languages)
// console.log(typeof languages)

// const user = {email: 'matheus@teste.com', password: 'teste123', age: 30} // objet literals
// console.log(user)
// console.log(typeof user)

//metodos de string
// const fullName = "Matheus Battisti"

// console.log(fullName.length)

// const stringToArray = fullName.split(" ")

// console.log(stringToArray)

// console.log(fullName.toLocaleLowerCase())

// console.log(fullName.toLocaleUpperCase())

// console.log(fullName.indexOf("Battisti"))

// console.log('adsiahsid'.indexOf("Battisti"))

// console.log(fullName.slice(0, 7))

// //métodos de array
// const list = ['a', 'b', 'c', 'd', 'e'] //comecam a contar do 0

// console.log(list.length)

// console.log(list[2])

// list[5] = 'f'

// console.log(list)

// console.log(list[list.length - 1])

// list.push('g')

// console.log(list)

// list.pop(list)

// console.log(list)

// list.shift()

// console.log(list)

// list.unshift('a')

// console.log(list)

// //objetos
// const product = {
//     name: 'Camisa',
//     price: 15.99,
//     inStock: true,
//     size: ['P', 'M', 'G'],
//     'Main color': 'Azul',
// }

// console.log(product.name)

// console.log(product['name'])

// console.log(product['Main color'])

// // destructuring
// const {price, inStock} = product

// console.log(price)
// console.log(inStock)

// const [n1, n2] = list

// console.log(n1)
// console.log(n2)

// // JSON - JavaScript Object Notation
// const dog = {
//     name: 'Shark',
//     age: 10,
// }

// const json = JSON.stringify(dog)

// console.log(json)

// const obj = JSON.parse(json)

// console.log(obj)

// const jsonErrado = '{"name": "Teste", "surname":"Testando"}'

// const obj2 = JSON.parse(jsonErrado)

// console.log(obj2)

// // estruturas condicionais
// const a = 10

// if (a > 8) {
//     console.log('É maior que 8')
// }

// // >, <. >=, <=

// const b = "Matheus"

// if (b === "João") {
//     console.log("O nome é João")
// } else if (b === "Pedro") {
//     console.log("O nome é Pedro")
// } else {
//     console.log("Não encontramos o nome do usuário")
// }

// const someNumber = 24

// //if ternário
// let testingANumber = someNumber < 20 ? 'Yes' : 'No'

// console.log(testingANumber)

// // Estrutura de repetição
// const myList = [1, 2, 3, 4, 5]
// let counter = 0

// while(counter < myList.length) {
//     console.log('Imprimindo: ' + myList[counter])
//     // counter = counter + 1
//     counter++
// }

// const mySecondList = ['a', 'b', 'c', 'd', 'e']

// for(let counter = 0; counter < mySecondList.length; counter++) {
//     console.log(`Imprimindo: ${mySecondList[counter]}`) // template literals
// }

// //métodos de array -> repetição
// const names = ["Matheus", "João", "Pedro", "Maria"]

// names.forEach(function(name) {
//     console.log(`O nome é: ${name}`)
// })

// const modifiedNames = names.map(function(name) { 
//     if (name === "Matheus") {
//         return name = 'Sr. Matheus'
//     } else {
//         return name
//     }
// })

// console.log(modifiedNames)

// const bigNumbers = [1, 2, 3, 4, 5, 10, 100].filter(function(number) {
//     return number >=5
// })

// console.log(bigNumbers)

const sumAll = [10, 20, 30, 40, 50].reduce((total, number) => {
     return total + number
})

console.log(sumAll)

// Funções
function minhaFuncao() {
    console.log("Olá Função!")
}

minhaFuncao()

function nomeCompleto(nome, sobrenome) {
    return `O nome completo é: ${nome} ${sobrenome}`
}

console.log(nomeCompleto("Matheus", "Battisti"))
console.log(nomeCompleto("João", "Azevedo"))

const primeiroNome = "Maria"
const segundoNome = "Matos"

const meuNomeCompleto = nomeCompleto(primeiroNome, segundoNome)

console.log(meuNomeCompleto)

// Arrow Functions
const myArrowFunction = (a, b) => {
    return a + b
}

console .log(myArrowFunction(2, 5))

const mySimplesArrowFunction = (a, b) => a + b

console.log(mySimplesArrowFunction(5, 5))

// Classes
class Product {

    constructor(name, price){
        this.name = name
        this.price = price
    }

    productDetails() {
        return `O produto é ${this.name} e o preço é R$ ${this.price}`
    }
}

const socks = new Product("Meia branca", 10.99)
const shift = new Product("Camisa preta", 22.99)

console.log(socks.name)
console.log(socks.price)

console.log(shift.name)

console.log(shift.productDetails())

// Herança
class SuperProduct extends Product {
    constructor(name, price, size){
        super(name, price)
        this.size = size
    }

    showAdjective(adjective) {
        return `O ${this.name} é muito ${adjective}`
    }

    // static
    static sayHello() {
        console.log("Hello")
    }
}

const tenis = new SuperProduct("Tênis Vermelho", 59.90, '42')

console.log(tenis.name)
console.log(tenis.size)
console.log(tenis.showAdjective('Bom'))

SuperProduct.sayHello()

//DOM - Document Object Model
//Seleção de elementos
const title = document.getElementById('title') //#title

console.log(title)

//querySelector
const sameTitle = document.querySelector('#title')

console.log(sameTitle)

const texts = document.querySelectorAll('.text')

console.log(texts)
console.log(texts[1])

texts.forEach((text) => {
    console.log(text.textContent.toLocaleUpperCase())
})

//Manipulando elementos
title.textContent = "Mudei o texto"

texts[0].innerHTML = "<span>Alteramos o HTML deste elemento</span>"

texts[1].style.backgroundColor = "red" // background-color: red

texts[2].classList.add('my-class')

texts[2].classList.remove('text')

texts[3].remove()

// Eventos
const btn = document.querySelector('#btn')

btn.addEventListener('click', function() {
    texts[2].style.color = "blue"
})