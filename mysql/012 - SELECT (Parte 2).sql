#busca por objetos semelhantes e nao completo
select * from cursos
where nome = 'P';

select * from cursos
where nome = 'P%';

select * from cursos
where nome like 'P%'; 

#like é case sensitive
select * from cursos
where nome like 'a%'; 

select * from cursos
where nome like '%A'; 

select * from cursos
where nome like '%A%'; 

select * from cursos
where nome not like '%A%'; 

select * from cursos
where nome like 'P%p_'; 

select * from cursos
where nome like 'P_p%'; 

select * from gafanhotos
where nome like '%silva%'; 

select * from gafanhotos;

select nacionalidade from gafanhotos;

#buscar resultados sem repetição
select distinct nacionalidade from gafanhotos
order by nacionalidade;

#agregar informações
select count(*) from cursos;

#agregar informações
select count(*) from cursos
where carga > 30;

#ver o maior
select max(totaulas) from cursos where ano = '2016';

#ver o menor
select nome, min(totaulas) from cursos where ano = '2016';

#soma
select sum(totaulas) from cursos where ano = '2016';

#media
select avg(totaulas) from cursos where ano = '2016';