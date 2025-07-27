import * as cartServices from "./services/cart.js";
import createItem from "./services/item.js";

const myCart = [];
const myWhishList = [];

console.log("Welcome to the your Shopee Cart!");

// criando dois itens
const item1 = await createItem("hotwheels ferrari", 20.99, 1);
const item2 = await createItem("hotwhels lamborghini", 39.99, 3);

// adicionei dois itens ao carrinho
await cartServices.addItem(myCart, item1);
await cartServices.addItem(myCart, item2);

await cartServices.removeItem(myCart, item2);
await cartServices.removeItem(myCart, item2);
// await cartServices.removeItem(myCart, item2);

await cartServices.displaycart(myCart);

// deletei dois itens do carrinho
// await cartServices.deleteItem(myCart, item1.name);
// await cartServices.deleteItem(myCart, item2.name);

await cartServices.calculateTotal(myCart);