
const fs = require('fs');
const path = require('path');

function walk(dir, depth = 0) {
  let results = [];
  fs.readdirSync(dir).forEach(file => {
    const fullPath = path.join(dir, file);
    const stat = fs.statSync(fullPath);
    if (stat && stat.isDirectory()) {
      results.push({ path: fullPath, depth });
      results = results.concat(walk(fullPath, depth + 1));
    }
  });
  return results;
}

function extractSection(content, start, end) {
  const iStart = content.indexOf(start);
  const iEnd = content.indexOf(end);
  return (iStart !== -1 && iEnd !== -1) ? content.slice(iStart, iEnd + end.length) : null;
}

function updateSection(content, sectionId, generatedContent) {
  const sectionStart = `<!-- ${sectionId}:start -->`;
  const sectionEnd = `<!-- ${sectionId}:end -->`;
  const fullSection = `${sectionStart}\n${generatedContent}\n${sectionEnd}`;

  const oldSection = extractSection(content, sectionStart, sectionEnd);
  if (oldSection) {
    return content.replace(oldSection, fullSection);
  } else {
    return content + `\n## ${sectionId.toUpperCase().replace(/-/g, ' ')}\n` + fullSection;
  }
}

function formatTree(dir, prefix = '') {
  const items = fs.readdirSync(dir).filter(f =>
    fs.statSync(path.join(dir, f)).isDirectory()
  );

  return items.map((item, i) => {
    const isLast = i === items.length - 1;
    const branch = isLast ? '┗' : '┣';
    const nextPrefix = prefix + (isLast ? '  ' : '┃ ');
    const subtree = formatTree(path.join(dir, item), nextPrefix);
    return `${prefix}${branch} 📂 ${item}${subtree ? '\n' + subtree : ''}`;
  }).join('\n');
}

function buildTable(headers, rows) {
  const head = `| ${headers.join(' | ')} |`;
  const sep = `|${headers.map(() => '---').join('|')}|`;
  return [head, sep, ...rows.map(r => `| ${r.join(' | ')} |`)].join('\n');
}

function countCompleted(targetPath) {
  const aulas = fs.readdirSync(targetPath).filter(f =>
    fs.statSync(path.join(targetPath, f)).isDirectory()
  );

  let total = aulas.length;
  let done = 0;

  aulas.forEach(aula => {
    const readmePath = path.join(targetPath, aula, 'README.md');
    if (fs.existsSync(readmePath)) {
      const content = fs.readFileSync(readmePath, 'utf-8');
      if (content.includes('[X] Aula assistida') && content.includes('[X] Exercício concluído')) {
        done++;
      }
    }
  });

  return { total, done };
}

function updateBootcampReadme(bootcampPath) {
  const readmePath = path.join(bootcampPath, 'README.md');
  const trilhas = fs.readdirSync(bootcampPath).filter(f =>
    fs.statSync(path.join(bootcampPath, f)).isDirectory()
  );

  const progressTable = trilhas.map(trilha => {
    const trilhaPath = path.join(bootcampPath, trilha);
    const modulos = fs.readdirSync(trilhaPath).filter(f =>
      fs.statSync(path.join(trilhaPath, f)).isDirectory()
    );

    let total = 0;
    let done = 0;

    modulos.forEach(mod => {
      const modPath = path.join(trilhaPath, mod);
      const count = countCompleted(modPath);
      total += count.total;
      done += count.done;
    });

    const status = total === 0 ? '⏳ A iniciar' : (done === total ? '✅ Concluído' : '🔄 Em andamento');
    const trilhaLink = `[${trilha}](${encodeURI(trilha + '/README.md')})`;
    return [trilhaLink, modulos.length.toString(), `${done}/${total}`, status];
  });

  const estrutura = formatTree(bootcampPath);
  let content = fs.existsSync(readmePath) ? fs.readFileSync(readmePath, 'utf-8') : '';
  content = updateSection(content, 'estrutura-bootcamp', '```\n' + estrutura + '\n```');
  content = updateSection(content, 'progresso', buildTable(['Trilha', 'Módulos', 'Aulas Completas', 'Status'], progressTable));
  fs.writeFileSync(readmePath, content);
}

function updateGrupoReadme(trilhaPath) {
  const readmePath = path.join(trilhaPath, 'README.md');
  const modulos = fs.readdirSync(trilhaPath).filter(f =>
    fs.statSync(path.join(trilhaPath, f)).isDirectory()
  );

  const estrutura = formatTree(trilhaPath);
  const progresso = modulos.map(modulo => {
    const modPath = path.join(trilhaPath, modulo);
    const { total, done } = countCompleted(modPath);
    const status = total === 0 ? '⏳ A iniciar' : (done === total ? '✅ Concluído' : '🔄 Em andamento');
    const moduloLink = `[${modulo}](${encodeURI(modulo + '/README.md')})`;
    return [moduloLink, `${done}/${total}`, status];
  });

  let content = fs.existsSync(readmePath) ? fs.readFileSync(readmePath, 'utf-8') : '';
  content = updateSection(content, 'estrutura-trilha', '```\n' + estrutura + '\n```');
  content = updateSection(content, 'módulos', buildTable(['Módulo', 'Aulas Completas', 'Status'], progresso));
  fs.writeFileSync(readmePath, content);
}

function updateModuloReadme(moduloPath) {
  const readmePath = path.join(moduloPath, 'README.md');
  const aulas = fs.readdirSync(moduloPath).filter(f =>
    fs.statSync(path.join(moduloPath, f)).isDirectory()
  );

  const estrutura = formatTree(moduloPath);
  const count = { total: aulas.length, done: 0 };
  const tabelaAulas = aulas.map((aula, i) => {
    const readmePath = path.join(moduloPath, aula, 'README.md');
    const isDone = fs.existsSync(readmePath) && fs.readFileSync(readmePath, 'utf-8').includes('[X] Aula assistida');
    if (isDone) count.done++;
    const aulaLink = `[${aula}](${encodeURI(aula + '/README.md')})`;
    return [i + 1, aulaLink, isDone ? '✅ Concluída' : '⏳ A iniciar', ''];
  });

  let content = fs.existsSync(readmePath) ? fs.readFileSync(readmePath, 'utf-8') : '';
  content = updateSection(content, 'estrutura-modulo', '```\n' + estrutura + '\n```');
  content = updateSection(content, 'aulas', buildTable(['Aula Nº', 'Nome da Aula', 'Status', 'Observações'], tabelaAulas));
  content = updateSection(content, 'progresso',
    buildTable(['Aulas Completas', 'Status'], [[`${count.done}/${count.total}`, count.total === 0 ? '⏳ A iniciar' : (count.done === count.total ? '✅ Concluído' : '🔄 Em andamento')]])
  );
  fs.writeFileSync(readmePath, content);
}

const basePath = './';
const structure = walk(basePath);

structure.filter(x => x.depth === 0).forEach(({ path }) => updateBootcampReadme(path));
structure.filter(x => x.depth === 1).forEach(({ path }) => updateGrupoReadme(path));
structure.filter(x => x.depth === 2).forEach(({ path }) => updateModuloReadme(path));
