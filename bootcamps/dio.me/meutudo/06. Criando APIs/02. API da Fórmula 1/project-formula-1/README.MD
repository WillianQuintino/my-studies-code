# API Minimal com Node.js e Fastify

**Descrição**  
Este projeto apresenta uma **API leve e eficiente**, desenvolvida com **Node.js** e **Fastify**, ideal para aplicações web e móveis que necessitam de respostas rápidas e um ambiente minimalista.

---

##  Features

- Ambiente **minimalista** e **performático** com Fastify
- Estrutura preparada para crescer com TypeScript (se estiver usando TS)

---

##  Tecnologias usadas

- **Node.js**  
- **Fastify** — servidor web rápido e eficiente  
- **TypeScript** (caso esteja em uso) — tipagem opcional e segurança  
- Ferramentas auxiliares — como `tsup`, `tsx`

---

##  Como usar

1. Clone o repositório

```bash
   git clone https://github.com/digitalinnovationone/node-formula-1.git
   cd node-formula-1
```

2. Instale as dependências

```bash
   npm install
```

3. Inicie o servidor em modo deve-relload:

```bash
   npm run start:dev
```

   Ou use o build distribuído:

```bash
   npm run dist
   npm run start:dist
```

---

## Endpoints

* `GET /teams` — lista todos os registros dos times
* `GET /drivers` — lista todos os registros dos motoristas
* `GET /drivers/:id` — busca um registro por ID dos motoristas

---

## Estrutura do projeto

```
.
├── src/                # Código-fonte da API
├── .env                # Variáveis de ambiente
├── tsconfig.json       # Configuração do TypeScript (caso exista)
├── package.json
└── README.md
```

---

## Autor

**Willian Custodio Quintino** — Desenvolvedor FullStack Junior
\[LinkedIn](https://www.linkedin.com/in/willian-custodio-quintino/) • \[GitHub](https://github.com/WillianQuintino)

---

## Como contribuir

Contribuições são bem-vindas!

1. Fork do repositório
2. Crie uma feature branch (`git checkout -b minha-feature`)
3. Faça commit das suas alterações (`git commit –m 'Adiciona nova feature'`)
4. Push para sua branch (`git push origin minha-feature`)
5. Abra um Pull Request

---

## Licença

Este projeto está licenciado sob a **MIT License**.
