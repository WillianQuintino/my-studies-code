programa {
  funcao inicio() {
    inteiro idade

    escreva("Digite sua idade:")
    leia(idade)
    
    se(idade < 16){
      escreva("Não pode votar")
    }senao{
      escreva("Pode votar")
    }
  }
}
