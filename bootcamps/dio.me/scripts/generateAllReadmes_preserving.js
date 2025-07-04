
const fs = require('fs');
const path = require('path');

const startMarker = '<!-- aulas:start -->';
const endMarker = '<!-- aulas:end -->';

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

function buildTable(headers, rows) {
  const head = `| ${headers.join(' | ')} |`;
  const sep = `|${headers.map(() => '---').join('|')}|`;
  return [head, sep, ...rows.map(r => `| ${r.join(' | ')} |`)].join('\n');
}

function updateReadme(targetPath, sectionId, headers, rows) {
  const readmePath = path.join(targetPath, 'README.md');
  const sectionStart = `<!-- ${sectionId}:start -->`;
  const sectionEnd = `<!-- ${sectionId}:end -->`;
  const sectionContent = `\n${sectionStart}\n${buildTable(headers, rows)}\n${sectionEnd}\n`;

  let content = '';
  const defaultHeader = `# ${path.basename(targetPath)}\n\nEste é o diretório de **${path.basename(targetPath)}**.\n`;
  if (fs.existsSync(readmePath)) {
    content = fs.readFileSync(readmePath, 'utf-8');
    const oldSection = extractSection(content, sectionStart, sectionEnd);
    if (oldSection) {
      content = content.replace(oldSection, sectionContent);
    } else {
      content += `\n\n## ${sectionId.toUpperCase()}\n${sectionContent}`;
    }
  } else {
    content = `# ${path.basename(targetPath)}\n\n## ${sectionId.toUpperCase()}\n${sectionContent}`;
  }

  fs.writeFileSync(readmePath, content || defaultHeader + `\n## ${sectionId.toUpperCase()}\n` + sectionContent);
}

const basePath = './';
const structure = walk(basePath);

// Atualiza cada módulo
structure.filter(x => x.depth === 3).forEach(({ path: modulePath }) => {
  const aulas = fs.readdirSync(modulePath).filter(f =>
    fs.statSync(path.join(modulePath, f)).isDirectory()
  );
  const rows = aulas.map((aula, i) => [i + 1, aula, '⏳ A iniciar', '']);
  updateReadme(modulePath, 'aulas', ['Aula Nº', 'Nome da Aula', 'Status', 'Observações'], rows);
});

// Atualiza cada grupo
structure.filter(x => x.depth === 2).forEach(({ path: groupPath }) => {
  const modulos = fs.readdirSync(groupPath).filter(f =>
    fs.statSync(path.join(groupPath, f)).isDirectory()
  );
  const rows = modulos.map((mod, i) => [i + 1, mod, '🔄 Em andamento']);
  updateReadme(groupPath, 'módulos', ['Módulo Nº', 'Nome do Módulo', 'Status'], rows);
});

// Atualiza cada bootcamp
structure.filter(x => x.depth === 1).forEach(({ path: bootcampPath }) => {
  const grupos = fs.readdirSync(bootcampPath).filter(f =>
    fs.statSync(path.join(bootcampPath, f)).isDirectory()
  );
  const rows = grupos.map((grupo, i) => [i + 1, grupo, '🧩 Em progresso']);
  updateReadme(bootcampPath, 'grupos', ['Grupo Nº', 'Nome do Grupo', 'Status'], rows);
});
