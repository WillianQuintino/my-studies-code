export enum ContentType {
  // JSON e formatos de dados
  JSON = "application/json",
  JSON_UTF8 = "application/json; charset=utf-8",
  XML = "application/xml",
  TEXT_XML = "text/xml",
  YAML = "application/x-yaml",
  CSV = "text/csv",
  TSV = "text/tab-separated-values",

  // Texto simples e HTML
  TEXT = "text/plain",
  HTML = "text/html",
  MARKDOWN = "text/markdown",

  // Arquivos e downloads
  PDF = "application/pdf",
  ZIP = "application/zip",
  GZIP = "application/gzip",
  TAR = "application/x-tar",
  OCTET_STREAM = "application/octet-stream", // binário genérico

  // Imagens
  PNG = "image/png",
  JPEG = "image/jpeg",
  GIF = "image/gif",
  WEBP = "image/webp",
  SVG = "image/svg+xml",
  ICO = "image/x-icon",

  // Áudio
  MP3 = "audio/mpeg",
  WAV = "audio/wav",
  OGG_AUDIO = "audio/ogg",

  // Vídeo
  MP4 = "video/mp4",
  WEBM = "video/webm",
  OGG_VIDEO = "video/ogg",

  // Outros
  FORM_URLENCODED = "application/x-www-form-urlencoded",
  FORM_DATA = "multipart/form-data"
}
