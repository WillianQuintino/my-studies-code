# Bat Pass App

Este projeto é um aplicativo chamado **Bat Pass App**.

## Descrição
O Bat Pass App é um aplicativo mobile desenvolvido em React Native (provavelmente com Expo), com o objetivo de gerenciar senhas de forma segura e prática. O projeto utiliza componentes customizados e segue uma arquitetura modular, separando componentes, telas e serviços.

## Estrutura do Projeto

```
bat-pass-app/
├── assets/                # Imagens e ícones do app
├── src/
│   ├── components/        # Componentes reutilizáveis (Botão, Logo, Input)
│   ├── screens/           # Telas do aplicativo (ex: Home)
│   └── services/          # Serviços (ex: gerenciamento de senhas)
├── App.tsx                # Arquivo principal do app
├── index.ts               # Ponto de entrada
├── package.json           # Dependências e scripts
├── tsconfig.json          # Configuração do TypeScript
└── README.md              # Este arquivo
```

## Como rodar o projeto

1. Instale as dependências:
   ```bash
   npm install
   ```
2. Inicie o projeto:
   ```bash
   npm start
   ```
   Ou, se estiver usando Expo:
   ```bash
   npx expo start
   ```

## Tecnologias utilizadas
- React Native
- TypeScript
- Expo (se aplicável)

## Estrutura dos Componentes
- **BatButton**: Botão customizado
- **BatLogo**: Logo do aplicativo
- **BatTextInput**: Campo de entrada customizado

## Licença
Este projeto está sob a licença MIT.
