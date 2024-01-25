#ACID - Atomicidade Consistência Isolamento Durabilidade

use cadastro;
describe gafanhotos;

alter table gafanhotos
add cursopreferido int;

alter table gafanhotos
add foreign key (cursopreferido)
references cursos(idcursos);

select * from gafanhotos;
select * from cursos;

update gafanhotos set cursopreferido = '6' where id = '1';

delete from cursos where idcursos = '6';

delete from cursos where idcursos = '5';

select nome, cursopreferido from gafanhotos;

select nome, ano from cursos;

#junção MySQL
#inner join
select gafanhotos.nome, cursos.nome, cursos.ano 
from gafanhotos join cursos
on cursos.idcursos = gafanhotos.cursopreferido
order by gafanhotos.nome;

#apelido  = as
select g.nome, c.nome, c.ano 
from gafanhotos as g join cursos as c
on c.idcursos = g.cursopreferido
order by g.nome;

#mostrar os alunos sem ligação a tabela a esquerda
select g.nome, c.nome, c.ano 
from gafanhotos as g left outer join cursos as c
on c.idcursos = g.cursopreferido
order by g.nome;

#mostrar os alunos sem ligação a tabela a direita
select g.nome, c.nome, c.ano 
from gafanhotos as g right join cursos as c
on c.idcursos = g.cursopreferido
order by g.nome;
