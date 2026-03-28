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
