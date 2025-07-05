# Como o node Funciona

## A história do node.js

---

**Slide 01**

- 2009
> Node.js foi criado por Ryan Dahl e lançado com um ambiente de execução de JavaScript do lado do servidor.

- 2010
> Aversão 0.1.14 de Node.js foi lançada, marcando o início do desenvolvimento da comunidade e o crescente interesse na plataforma.

---

- Importate saber o porque das coisas.
- Ele queria monitorar alguma coisa e acabou usando codigo em javascript
- Existia um problema em sua epoca para executar o codigo precisava de um navegador em execução
- nesta época já se via um potencial na liguagem.

---

**Slide 02**

- 2011
> O Node.js foi adotado por grandes empresas como Microsoft, Yahoo! e LinkedIn, aumentando ainda mais sua popularidade.

- 2012
> A formação da Fundação Node.js como uma organização sem fins lucrativos para gerenciar e evoluir o projeto. Mais tarde conhecida como OpenJS Foundation

---

- Varias empresa gigantes começou a se interesar em node js.
- Em 2012 ele abandona o javascript e uma fundação pela comunidade foi criado a openjs foundation.
- O criador faz uma conferencia intitulada como 10 coisas que lamento sobre Node.js - Ryan Dahl - JSConf EU.
- A OpenJS fundation mantem ativo com atualizações frequentes o node.js e está a ouvidos a comunidade node.

---

**Slide 03**

- 2013
> Lançamento da versão 0.10 do Node.js, trazendo melhorias de desempenho e estabilidade.

- 2015
> A versão 0.12 introduziu o suporte oficial para o ECMAScript 6 (ES6), trazendo recursos modernos ao JavaScript

---

- Já estava contruido aplicações completas
- O ECMA Script veio para padronizar o javascript e neste momento eles adiciona compatibilidade com ele.

---

**Slide 04**

- 2016
> O lançamento da versão 6 do Node.js, marcando a transição para um ciclo de lançamento de versões Long Term Support (LTS).

- 2020
> Ryab Dahl cria o Deno, o maior concorrent do Node.js, dessa vez fazendo tudo do jeito como ele queria.

---

- A partir da versão 6 sempre terá uma versão que é estavel, uma com os ultimos recurso para ter mais confiabilidade no seu código
- Ele criou o node como ele queria fazer.
- No youtube tem o video "Deno, a new way to JavaScript. Ryan Dahl. JS FEST 2019 Spring
- O logo do node.js é de um pacote simbolizado poder levar pra qualquer lugar e nao so no navegador e a caracteristica de criar pequenos pacotes de codigo que é o termo node.

## O que o Nodejs não é

---

**Slide 05**

Como funciona?

---

**Slide 06**
O QUE O NODE NÃO É

- Node.js não é uma linguagem de programação, a çinguagem é Javascript
- Não é uma framework, é uum runtime (ambiente de execução) de Javascript
- Node não é limitado, ele faz tudo que outras tacnologias de backend fazem.

---

**Slide 07**

Applications of Node.js
- Real time chats
- Data streaming
- IoT applications
- Complex SPAs
- REST API Server
- Web applications

---


## Como O Nodejs Funciona

---

**Slide 08**

Como funciona?

Navegadores = `Rendering Engine` + `JavaScript Engine` + `User Interface`
IE = `Trident` + `Chakra`
Firefox = `Gecko` + `*Monkey`
Chrome = `Webkit` + `V8`
Safari = `Webkit` + `JavascriptCore`

---

- O criado isolou o v8 do crome para criar o node e ele faz uma camada para converça como o sistema chamada de libuv em c++ que faz o Event Loop
- v8 javascript linguagem de alto nivel