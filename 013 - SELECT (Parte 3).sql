#agrupamento de dados
select totaulas, count(*) from cursos
group by totaulas
order by totaulas;

select ano, count(*) from cursos
group by ano
having count(ano) >= 2
order by count(*) desc;

select ano, count(*) from cursos
where totaulas > 10
group by ano
having count(ano) >= 2
order by count(*) desc;

select carga, count(*) from cursos
where ano > 2015
group by carga
having carga > (select avg(carga) from cursos);