# MANIPULANDO REGISTROS OU LINHAS OU TUPLAS

#DDL - DATA DEFINITION LANGUAGE
# L CREATE
#	L DATABASE
#	L TABLE
# L ALTER
#	L TABLE
# L DROP
#	L TABLE

#DML - DATA MANIPULATION LANGUAGE
# L INSERT
#	L INTO
# L UPDATE
# L DELETE
# L TRUNCATE

# Colunas são os campos ou tributos

# selecionar o banco 
use cadastro;

# selecionado dados da tabela
select * from gafanhotos;
select * from cursos;

# incluir cursos na tabela
insert into cursos values
('1','HTML4','Cursos em HTML5','40','37','2014'),
('2','Algoritmos','Lógica de Programação','20','15','2014'),
('3','Photoshop','Dicas de Photosho CC','10','8','2014'),
('4','PGP','Curso de PHP para iniciantes','40','20','2010'),
('5','Jarva','Introdução à Linguagem Java','10','29','2000'),
('6','MySQL','Banco de Dados MySQL','30','15','2016'),
('7','Word','Curso completo de Word','40','30','2016'),
('8','Sapateado','Danças Rítimicas','40','30','2018'),
('9','Cozinha Árabe','Aprenda a fazer Kibe','40','30','2018'),
('10','YouTuber','Gerar polêmica e ganhar inscritos','5','2','2018');

# modificação da primeira linha apenas um erro
update cursos #seleciona a tabela
set nome = 'HTML5' #modifica o dado
where idcursos = '1'; #usa o idcursos para encontrar o local da modificacao

# modificação da linha 4 dois erros nome e ano
update cursos #seleciona a tabela
set nome = 'PHP', ano = '2015' #modifica os dados
where idcursos = '4'; #usa o idcursos para encontrar o local da modificacao

# modificação da linha 5 dois erros nome, carga e ano
update cursos #seleciona a tabela
set nome = 'Java', ano = '2015', carga = '40' #modifica os dados
where idcursos = '5' #usa o idcursos para encontrar o local da modificacao
limit 1; #limita a apenas uma linha afetada

# modificação todos os anos de 2018 para ano de 2050 e carga de 800 sem limitação
update cursos #seleciona a tabela
set ano = '2050', carga = '800' #modifica os dados
where ano = '2018'; #usa o idcursos para encontrar o local da modificacao


# modificação todos os anos de 2050 para ano de 2018 e carga de 0 com limitação
update cursos #seleciona a tabela
set ano = '2018', carga = '0' #modifica os dados
where ano = '2050' #usa o idcursos para encontrar o local da modificacao
limit 1; #limita a apenas uma linha afetada

# remover dados da tabela pelo id
delete from cursos
where idcursos = '8';

# remover varios dados da tabela pelo ano com limit 2
delete from cursos
where ano = '2050'
limit 2;

# remover todos os registro da tabela
truncate table cursos;

# remover todos os registro da tabela resumido
truncate cursos;
