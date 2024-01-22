programa {
  funcao inicio() {
    inteiro idade

    escreva("Digite sua idade:")
    leia(idade)
    
    se(idade < 16){
      escreva("Não pode votar")
    }senao se ((idade < 18) ou (idade > 70)){
      escreva("Voto Opcional")
    }senao {
      escreva("Voto Obrigatorio")
    }
  }
}
