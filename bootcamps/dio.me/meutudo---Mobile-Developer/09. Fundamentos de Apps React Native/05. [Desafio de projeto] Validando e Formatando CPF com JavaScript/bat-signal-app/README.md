
# Bat Signal App

## Descrição
Este projeto tem como objetivo desenvolver a interface mobile de um aplicativo de Bat-Sinal usando React Native, permitindo acionar e visualizar o famoso sinal do Batman de forma interativa e responsiva.

**Tecnologias:** React Native · Expo · TypeScript

**Nível:** Básico a Especialista

**Autor do Desafio:** Felipe Aguiar — Tech Educator, DIO

---

## Entendendo o Desafio
Agora é a sua hora de brilhar e construir um perfil de destaque na DIO! A proposta aqui é ir além: você poderá recriar do zero ou aperfeiçoar o projeto original desenvolvido pelo instrutor. Para isso, dê um fork no repositório-base ou crie o seu próprio repositório, colocando em prática tudo o que aprendeu até agora.

### Descrição do Desafio
Desenvolver a interface mobile de um aplicativo de Bat-Sinal usando React Native, permitindo acionar e visualizar o famoso sinal do Batman de forma interativa e responsiva.

### Objetivos de Aprendizagem
- Reproduzir e/ou melhorar um projeto com base em um código existente
- Aplicar os conceitos aprendidos em um cenário real
- Documentar seu raciocínio técnico e decisões de forma clara e organizada
- Utilizar o GitHub como plataforma para versionamento e exposição do seu trabalho

### Entrega do Desafio
Para concluir este desafio, você deverá:

1. Assistir a todas as vídeo-aulas (não pule nenhuma etapa!)
2. Criar um repositório público no GitHub contendo:
   - O código-fonte do seu projeto (recriado ou modificado)
   - Um arquivo README.md detalhado
   - Qualquer outro arquivo relevante para a compreensão do projeto
   - Opcionalmente, capturas de tela relevantes organizadas em uma pasta `/images`
3. Enviar o link do seu repositório e uma breve descrição clicando no botão “Entregar Projeto”

---

## Funcionalidades
- Exibe o logo do Batman
- Botão personalizado para acionar o "Bat Sinal"
- Formulário de exemplo
- Tela inicial estilizada

## Estrutura do Projeto
```
app.json
App.tsx
index.ts
package.json
tsconfig.json
assets/
  adaptive-icon.png
  bat-logo.png
  favicon.png
  icon.png
  splash-icon.png
src/
  index.d.ts
  components/
    BatButton/
      BatButton.tsx
      BatButtonStyles.tsx
    BatLogo/
      BatLogo.tsx
      BatLogoStyles.tsx
    Form/
      Form.tsx
      FormStyles.tsx
  screens/
    Home/
      Home.tsx
      HomeStyles.tsx
```

## Como rodar o projeto

1. Instale as dependências:
   ```bash
   npm install
   ```
2. Inicie o projeto:
   ```bash
   npm run start
   ```
3. Siga as instruções do terminal para rodar no emulador ou dispositivo físico.

## Requisitos
- Node.js
- npm ou yarn
- Expo CLI (se aplicável)

## Recursos Úteis
- [Briefing - Desafio: Recrie um app de Bat Sinal.pdf](#)
- [GitHub Quick Start](https://github.com/digitalinnovationone/github-quick-start)
- [GitBook: Formação GitHub Certification](https://digitalinnovationone.github.io/github-certification/)
- [Documentação do GitHub](https://docs.github.com/pt)
- [Guia de Markdown do GitHub](https://docs.github.com/pt/get-started/writing-on-github)

## Licença
MIT
