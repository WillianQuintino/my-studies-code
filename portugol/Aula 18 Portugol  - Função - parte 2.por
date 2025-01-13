programa {
  funcao inicio() {

    cadeia texto1
    inteiro resultadoSoma
    
    texto1 = primeira()
    escreva(texto1)
   
    resultadoSoma = segunda()
    escreva("\nSoma: " , resultadoSoma)
    
    escreva(terceira())
  }

  funcao cadeia primeira(){
    cadeia retorno = "Inicio do Programa"
    retorne retorno
  }

  funcao inteiro segunda(){
    retorne 2 + 2
  }
  
  funcao cadeia terceira(){
   retorne "\nFinal do Programa"
  }
}
