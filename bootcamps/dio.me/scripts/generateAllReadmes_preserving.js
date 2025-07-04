
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
  const fullSection = `\n${sectionStart}\n${generatedContent}\n${sectionEnd}\n`;

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
    return `${prefix}${branch} 📂 ${item}` + (subtree.length ? '\n' + subtree : '');
  }).join('\n');
}

function buildTable(headers, rows) {
  const head = `| ${headers.join(' | ')} |`;
  const sep = `|${headers.map(() => '---').join('|')}|`;
  return [head, sep, ...rows.map(r => `| ${r.join(' | ')} |`)].join('\n');
}

// Bootcamp
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
    return modulos.map(mod => [trilha, mod, '0/0', '⏳ A iniciar']);
  }).flat();

  const estrutura = formatTree(bootcampPath);
  let content = fs.existsSync(readmePath) ? fs.readFileSync(readmePath, 'utf-8') : '';
  content = updateSection(content, 'estrutura-bootcamp', estrutura);
  content = updateSection(content, 'progresso', buildTable(['Trilha', 'Módulo', 'Aulas Completas', 'Status'], progressTable));
  fs.writeFileSync(readmePath, content);
}

// Trilha (grupo)
function updateGrupoReadme(trilhaPath) {
  const readmePath = path.join(trilhaPath, 'README.md');
  const modulos = fs.readdirSync(trilhaPath).filter(f =>
    fs.statSync(path.join(trilhaPath, f)).isDirectory()
  );

  const estrutura = formatTree(trilhaPath);
  const progresso = modulos.map(modulo => [modulo, '0/0', '⏳ A iniciar']);

  let content = fs.existsSync(readmePath) ? fs.readFileSync(readmePath, 'utf-8') : '';
  content = updateSection(content, 'estrutura-trilha', estrutura);
  content = updateSection(content, 'módulos', buildTable(['Módulo', 'Aulas Completas', 'Status'], progresso));
  fs.writeFileSync(readmePath, content);
}

// Módulo
function updateModuloReadme(moduloPath) {
  const readmePath = path.join(moduloPath, 'README.md');
  const aulas = fs.readdirSync(moduloPath).filter(f =>
    fs.statSync(path.join(moduloPath, f)).isDirectory()
  );

  const estrutura = formatTree(moduloPath);
  const tabelaAulas = aulas.map((aula, i) => [i + 1, aula, '⏳ A iniciar', '']);

  let content = fs.existsSync(readmePath) ? fs.readFileSync(readmePath, 'utf-8') : '';
  content = updateSection(content, 'estrutura-modulo', estrutura);
  content = updateSection(content, 'aulas', buildTable(['Aula Nº', 'Nome da Aula', 'Status', 'Observações'], tabelaAulas));
  fs.writeFileSync(readmePath, content);
}

const basePath = './';
const structure = walk(basePath);

// Bootcamp = depth 0
structure.filter(x => x.depth === 0).forEach(({ path }) => updateBootcampReadme(path));

// Trilha (grupo) = depth 1
structure.filter(x => x.depth === 1).forEach(({ path }) => updateGrupoReadme(path));

// Módulo = depth 2
structure.filter(x => x.depth === 2).forEach(({ path }) => updateModuloReadme(path));
