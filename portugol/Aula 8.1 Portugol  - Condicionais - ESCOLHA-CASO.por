programa {
  funcao inicio() {
    inteiro numero

    escreva ("Digite um n�mero: ")
    leia (numero)

    escolha (numero){
      caso 100:
        escreva("Bom dia")
      pare
      caso 200:
        escreva("Boa tarde")
      pare
      caso 300:
        escreva("Boa noite")
      pare
      caso contrario:
        escreva("Numero inv�lido")
    }
  }
}
