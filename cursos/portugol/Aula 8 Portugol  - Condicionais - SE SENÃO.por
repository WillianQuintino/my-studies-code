programa {
  funcao inicio() {
    inteiro idade

    escreva("Digite sua idade:")
    leia(idade)
    
    se(idade < 16){
      escreva("N�o pode votar")
    }senao se ((idade < 18) ou (idade > 70)){
      escreva("Voto Opcional")
    }senao {
      escreva("Voto Obrigatorio")
    }
  }
}
