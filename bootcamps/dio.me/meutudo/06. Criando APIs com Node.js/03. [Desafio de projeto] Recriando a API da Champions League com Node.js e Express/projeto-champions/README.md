# ⚽ API Champions League

Uma API completa e eficiente para acessar e manipular dados da Champions League, desenvolvida com Node.js e Express. Esta API fornece informações detalhadas sobre equipes, jogadores e suas estatísticas, ideal para plataformas que necessitam de acesso rápido e confiável a dados atualizados.

## 🚀 Funcionalidades

- **Gerenciamento de Jogadores**: CRUD completo para jogadores
- **Informações de Clubes**: Consulta de dados dos principais clubes europeus
- **Estatísticas Detalhadas**: Dados completos de performance dos jogadores
- **API RESTful**: Endpoints bem estruturados e documentados
- **Tipagem TypeScript**: Código totalmente tipado para maior segurança

## 🛠️ Tecnologias Utilizadas

- **Node.js**: Runtime JavaScript
- **Express**: Framework web minimalista
- **TypeScript**: Tipagem estática para JavaScript
- **CORS**: Configuração de políticas de origem cruzada
- **TSX**: Executor TypeScript para desenvolvimento
- **TSUP**: Bundler para TypeScript

## 📋 Pré-requisitos

- Node.js (versão 18 ou superior)
- npm ou yarn

## ⚙️ Instalação e Configuração

1. **Clone o repositório**
```bash
git clone <url-do-repositorio>
cd projeto-champions
```

2. **Instale as dependências**
```bash
npm install
```

3. **Configure as variáveis de ambiente**
```bash
# Crie um arquivo .env na raiz do projeto
echo "PORT=3333" > .env
```

4. **Execute o projeto**

**Desenvolvimento (com hot reload):**
```bash
npm run start:watch
```

**Desenvolvimento:**
```bash
npm run start:dev
```

**Produção:**
```bash
npm run start:dist
```

A API estará disponível em `http://localhost:3333`

## 📚 Documentação da API

### Base URL
```
http://localhost:3333/api
```

### 👥 Endpoints - Jogadores

#### Listar todos os jogadores
```http
GET /api/players
```

#### Buscar jogador por ID
```http
GET /api/players/:id
```

#### Criar novo jogador
```http
POST /api/players
```

**Body da requisição:**
```json
{
  "name": "Nome do Jogador",
  "club": "Nome do Clube",
  "nationality": "Nacionalidade",
  "position": "Posição",
  "statistics": {
    "Overall": 85,
    "Pace": 78,
    "Shooting": 82,
    "Passing": 89,
    "Dribbling": 87,
    "Defending": 45,
    "Physical": 80
  }
}
```

#### Atualizar jogador
```http
PATCH /api/players/:id
```

#### Remover jogador
```http
DELETE /api/players/:id
```

### 🏆 Endpoints - Clubes

#### Listar todos os clubes
```http
GET /api/clubs
```

**Resposta:**
```json
[
  {
    "id": 1,
    "name": "Real Madrid",
    "country": "Spain",
    "founded": 1902,
    "stadium": "Santiago Bernabéu",
    "capacity": 81044
  }
]
```

## 🏗️ Estrutura do Projeto

```
projeto-champions/
├── src/
│   ├── controllers/          # Controladores da aplicação
│   │   ├── clubs-controller.ts
│   │   └── players-controller.ts
│   ├── data/                 # Dados mockados
│   │   ├── clubs.json
│   │   └── players.json
│   ├── models/               # Interfaces TypeScript
│   │   ├── club-model.ts
│   │   ├── http-response-model.ts
│   │   ├── player-model.ts
│   │   └── statistics-model.ts
│   ├── repositories/         # Camada de acesso aos dados
│   │   ├── clubs-repository.ts
│   │   └── players-repository.ts
│   ├── services/             # Regras de negócio
│   │   ├── clubs-service.ts
│   │   └── players-service.ts
│   ├── utils/                # Utilitários
│   │   └── http-helper.ts
│   ├── app.ts                # Configuração do Express
│   ├── routes.ts             # Definição das rotas
│   └── server.ts             # Inicialização do servidor
├── package.json
├── tsconfig.json
└── README.md
```

## 🎯 Arquitetura

O projeto segue uma arquitetura em camadas bem definida:

- **Controllers**: Responsáveis por receber as requisições HTTP
- **Services**: Contêm a lógica de negócio
- **Repositories**: Gerenciam o acesso aos dados
- **Models**: Definem as interfaces e tipos
- **Utils**: Funções utilitárias compartilhadas

## 📊 Modelo de Dados

### Jogador
```typescript
interface PlayerModel {
  id: number;
  name: string;
  club: string;
  nationality: string;
  position: string;
  statistics: {
    Overall: number;
    Pace: number;
    Shooting: number;
    Passing: number;
    Dribbling: number;
    Defending: number;
    Physical: number;
  };
}
```

### Clube
```typescript
interface ClubModel {
  id: number;
  name: string;
  country: string;
  founded: number;
  stadium: string;
  capacity: number;
}
```

## 🧪 Testando a API

Você pode testar a API usando ferramentas como:

- **Insomnia**
- **Postman** 
- **Thunder Client** (extensão do VS Code)
- **curl**

### Exemplo com curl:
```bash
# Listar jogadores
curl http://localhost:3333/api/players

# Buscar jogador específico
curl http://localhost:3333/api/players/1

# Criar novo jogador
curl -X POST http://localhost:3333/api/players \
  -H "Content-Type: application/json" \
  -d '{"name":"Cristiano Ronaldo","club":"Al Nassr","nationality":"Portuguese","position":"Forward","statistics":{"Overall":91,"Pace":85,"Shooting":93,"Passing":82,"Dribbling":88,"Defending":34,"Physical":78}}'
```

## 🚀 Scripts Disponíveis

- `npm run dist`: Gera build de produção
- `npm run start:dev`: Inicia em modo desenvolvimento
- `npm run start:watch`: Inicia com hot reload
- `npm run start:dist`: Inicia versão de produção

## 🤝 Como Contribuir

1. Fork o projeto
2. Crie uma branch para sua feature (`git checkout -b feature/AmazingFeature`)
3. Commit suas mudanças (`git commit -m 'Add some AmazingFeature'`)
4. Push para a branch (`git push origin feature/AmazingFeature`)
5. Abra um Pull Request

## 📄 Licença

Este projeto está sob a licença ISC. Veja o arquivo `LICENSE` para mais detalhes.

## 👨‍💻 Desenvolvido por

**Willian Custodio Quintino** - [GitHub](https://github.com/WillianQuintino)

---

### 🏆 Sobre o Desafio DIO

Este projeto foi desenvolvido como parte do desafio da **Digital Innovation One (DIO)**, no curso de Node.js com Express ministrado por **Felipe Aguiar**. O objetivo é criar uma API robusta para gerenciar dados da Champions League, aplicando as melhores práticas de desenvolvimento backend.

**Repositório Original**: [nodejs-express-api](https://github.com/digitalinnovationone/nodejs-express-api)

---

⭐ Se este projeto foi útil para você, considere dar uma estrela no repositório!
