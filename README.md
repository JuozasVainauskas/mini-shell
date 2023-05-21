# mini-shell

Hobby UNIX shell implementation.

The purpose of this project is to understand the principles how UNIX shells work "under the hood".

## How to run it

You can run the shell:

- in a container:

  ```shell
    docker run --rm -it $(docker build -q .)
  ```

- locally:

  ```shell
    make
  ```

  **_NOTE:_** you can clean up build files with `make clean` command

## TODO

- [ ] Piping
- [ ] Redirection
- [ ] Globbing
- [ ] ...
