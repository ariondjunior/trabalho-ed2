# trabalho-ed2

## Primeiro passos depois de clonar o projeto

1. **Instalar o pre-commit**:
   Rode o seguinte comando no terminal: 
   ```bash
   sudo apt update && sudo apt install -y pre-commit
   ```
   Ou com o pipx, fica a sua escolha: 
   ```bash
   pipx install pre-commit
   ```

2. **Rodar os seguintes comandos**:
   - `pre-commit install`
   - `pre-commit run --all-files`   # opcional, para validar tudo uma vez
   - `make`
   - `make run`

## Compilação do projeto com Makefile

Todos os comandos abaixo devem ser executados na **raiz do projeto**.

- `make clean`: Limpa todos os binários presentes no projeto.
- `make` ou `make all`: Compila o projeto inteiro e cria o binário `app` para execução.
- `make run`: Executa o binário `app` para rodar o projeto. **Obs.:** caso queira, pode executar com o `./app` normalmente também.

## Adicionando novos arquivos

Ao criar um novo arquivo dentro do projeto, ele deve ser inserido no Makefile para ser compilado junto com o projeto. 

Para adicionar esse novo arquivo na compilação do Makefile, adicione o caminho partindo da raiz do projeto no `SRCS`.

## Motivação

Este projeto foi desenvolvido como parte da atividade avaliativa proposta pelo docente Wayner Moyses Marcelino para a disciplina de Estrutura de Dados I, na Universidade Vila Velha (UVV). O objetivo central é a simulação de um sistema de telemarketing que resolva problemas reais de fluxo de trabalho, como o cadastro de clientes, a oferta ativa de produtos e a posterior arquivação de contatos.

A motivação técnica do trabalho reside na aplicação prática de Tipos Abstratos de Dados (TADs) estudados em sala de aula utilizando a linguagem C. Para otimizar o sistema, optamos pela implementação de Fila, que gerenciam de forma organizada o fluxo de compradores, e Listas Duplamente Encadeadas, escolhidas estrategicamente para permitir uma navegação bidirecional eficiente nas estruturas de Clientes aguardando contato e Clientes arquivado.

[Baixar o PDF do projeto](./assets/Trabalho_I_de_EDI%281%29.pdf)
