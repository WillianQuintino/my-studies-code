programa {
  funcao inicio() {

    inteiro numero[10]

    para (inteiro i = 0; i < 10; i++){
      leia(numero[i])
    }

    //Ordem digitado
    escreva("\nLETRA A\n")
    para (inteiro y = 0; y < 10; y++){
      escreva(numero[y], " - ")
    }
    //Ordem inverça
    escreva("\nLETRA B\n")
    para (inteiro y = 9; y >= 0; y--){
      escreva(numero[y], " - ")
    }
  }
}
