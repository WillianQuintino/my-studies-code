import chalk from "chalk";

const PromptSchemaQRCode = [
    {
        name: "link",
        description: chalk.yellow("Digite o link para gerar o QR CODE"),
    },
    {
        name: "type",
        description: chalk.yellow("Escolha entre o tipo de QRcode(1- NORMAL ou (2- TERMINAL"),
        patter: /^[1-2]+$/,
        message: chalk.red.italic("Escolha entre 1 e 2"),
        require: true
    }
];

export default PromptSchemaQRCode;