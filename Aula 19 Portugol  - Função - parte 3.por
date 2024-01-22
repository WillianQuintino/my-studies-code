programa {
  funcao inicio() {

    cadeia texto1
    inteiro resultadoSoma
    
    texto1 = mensagem("inicio")
    escreva(texto1)
   
    resultadoSoma = segunda(3 , 2)
    escreva("\nSoma: " , resultadoSoma)

    resultadoSoma = segunda(3 , 12)
    escreva("\nSoma: " , resultadoSoma)
    
    escreva(mensagem("final"))
  }

  funcao cadeia mensagem(cadeia texto){
    cadeia retorno = texto
    se (texto == "inicio"){
      retorne "Inicio do Programa"
    }senao{
      retorne "\nFinal do Programa"
    }
  }

  funcao inteiro segunda(inteiro n1, inteiro n2){
    retorne n1 + n2
  }
  
  }
}
