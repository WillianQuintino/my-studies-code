# Ambiente de Codificação

## A Importância do ambiente certo

## Instalando o VSCode

Recomendado utilizar o vscode

## Tunando seu VSCode
Themes
- Andromeda
- Aura Theme
- Dracula
- Fonte Fire code

## Node e NPM
Precisamos node e NPM

## React Native
Fique sempre de olho na documentação é la que vai encontrar tudo que precisa sempre é o lugar para voce encontrar as atualizar
-- Toda documentação tem um get starts
-- ira utilizar o metodo com expo

## Expo
Armamento pesado use um projet builder
adicona template de projetos
Ele ajuda a rodar o app no celular fisico
Ele é uma ferramenta de produtividade

## Expo - Criando um projeto ReactNative
Para criar um novo projeto deve ser utilizaro o comando abaixo que permite escolher o tipo do template

## Estrutura de um projeto React Native com Expo
para utilizar tem que entrar na pasta do projeto com cd
- Sempre temos um package.json com scripts e dependencias do projeto sempre no projeto no coração está o react o react native sempre chama o projeto que vc esta criando
- tem um arquivo locke-json quue tem toda a arvore de dependencias
- tem um arquivo de tsconfig configuração de basicamente o projeto deve se portar
- tinha um arquivo de babel.config.js ele server para traduzir para funcionar
- temos uma arquivo que é importante que é o App.tsx ele é a porta de entrada do nosso app a tsx é de typescript xml
- tem um arquivo de configurações do seu aplicativo que é o app.json que tem o nome, versão, orientação de retrato ou paisagem, icone do seu app que está pasta assets, tem a configuração de splash screen que aparece ao abrir o app a cor do background
- tem o .gitignore para ignorar aplicativos para nao ir para o github
- tem a pasta do node-modules que armazena todos os pacotes que aplicação precisa
- pasta assets que fica as imagens do app
- tinha o .expo-shared onde ficava os tokit

## Expo GO
- package.json coração do projeto, app.json do seu app.
- para iniciar usa o run start
- na primeira vez pode demorar ele vai copilar tudo fa dar feedbacks
- ele da alguns comando para acessar
- ? da mais opções
- no celular instalar o app expo go

## Pontos Importantes sobre o Expo GO
- abrir o projeto o e intalar algo dentro dele ele pode dar erro entao é so parar e iniciar novamante
- com isso podemos rodar direto do celular

## Pontos importantes sobre O Expo
- Ele é uma camada amais do seu app
- Ele só entende as sua aplicações e algumas feramentas de terceiros não vai funcionar com expo
- Ele da para criar app real mais ele limita em alguns pontos
- Consegue sim sair do expo

# Visualizador de Celular

## Android Studio e Vysor
- A indicação para o react native é o android studio sedo para atender a emulação do celular no seu computador
- Nós não vamos utilizar vamos espelhar a tela do celular no pc é usar no Vysor

## Habilitando o modo desenvoldor no seu Android
- ele é escondido pois tem opções que pode quebrar o aparelho
- precissa entrar no sobre telefone na verção apertar 10 vezes

## Testando seu Ap
- inicia o visor depois da um 
- inicia o app

# Guias Rápidos

## O guia definitivo para iniciar projetos expo
- abre um new files 
- digite pnpx create-expo-app@latest my-app -t
- ele lista modelos do projeto celecione sempre o blank com typescript
- precisa entrar no diretorio e rodar o comando no diretorio
- ele tem que aparecer o packge.json
- pnpm run start ele inicia o projeto
- no android studio
- vai em more option e devices manager e criar um devices e da um play
- para executar no emulador
- no seu aparelho scanea o qr
- para inicar no emulardor aperta o a
- ai vai executar direto do emulador
- app.tsx começa para editar
- mudança brusca é só apertar o r para atualizar
- para fechar é só dar o crl + c
- para fechar é só fazer como no celular

## Recapitulando arquivos expo
tem um documento README
no .expo vc não meche
no asset fica as images icones e tela de load
no nodemodules é tudo que vc instalar e se nao tiver é so dar um install
app.json configura a imagem de icones, claro e escuro, atela de load o assets para limitar, opção para android e web
o app.tsx todo o tsx é onde se edita o codigo como componete
babel.conf configuraçaõ de copilação do app
packege lock a arvore de dependecias do projeto
packege.json fica todos os seus scripts e pacotes que é dependentes
tsconfig a configuração de como vai rodar o typescript

## Sobre pastas sources
- costuma criar um src é onde fica o codigo e fora dela configs o app.tsx é um componente e tamvém não é pois nele não carregamos quase nada
-  A boa paratica diz par anão codificar nele.

## Sobre as documentações
- nos devemos sempre utilizar estas duas documentasções
- reactnative.dev
- sempre tem que estár de olho com as mudanças do projeto
- isso também vale para:
- docs.expo.dev
- isso que ele vai explicar é o resumo da documentação e a experiencia dele de desenvolvedor
- nunca ignore a documentação oficial isso podemos cair neste erro.
