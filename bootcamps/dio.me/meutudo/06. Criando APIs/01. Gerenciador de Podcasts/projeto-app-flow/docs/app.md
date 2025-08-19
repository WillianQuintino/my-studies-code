# Podcast Menager

### Descrição
Um app ao estilo netflix, aonde poss centralizar diferentes episódios podcasts separados por categorias

### Domíno 
podcasts feitos em vídeo

### Features
- Listar os episódios podscasts em sessões de categorias
    - [saúde, filness, mentalidade, humor]
- Filtrar episódios por nome e podcast

## Como

#### Feature:
- Listar os episódios podcasts em sessões de categorias

### Como vou implementar:
GET: retorna uma lista de episodios

```js
[
    {
        podcastName: "flow",
        episode: "CBUM - Flow #319",
        videoId: "pQSuQmUfS30",
        cover: "https://i.ytimg.com/vi/pQSuQmUfS30/maxresdefault.jpg",
        link: "https://www.youtube.com/live/pQSuQmUfS30",
        categories: ["saúde", "bodybuilder"]
    },
    {
        podcastName: "flow",
        episode: "CBUM - Flow #319",
        videoId: "pQSuQmUfS30",
        cover: "https://i.ytimg.com/vi/pQSuQmUfS30/maxresdefault.jpg",
        link: "https://www.youtube.com/live/pQSuQmUfS30",
        categories: ["saúde", "bodybuilder"]
    }
]

```


GET: retorna uma lista de episódios baseado em um paramentro enviado pelo cliente do nome do podcast