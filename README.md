# Libft in Assembly x64

[![Build Status](https://travis-ci.org/JulienBalestra/libftASM.svg?branch=master)](https://travis-ci.org/julienbalestra/libftASM)


## Requirements

nasm available in $PATH:


* use brew for Mac OS
* use apt for Linux

The nasm version have to provide the following output format:

* macho64
* elf64

Make sure with the following command:


	nasm -hf

Example: nasm 2.11.05

## How to

Build the libfts.a:


	make

Build the testing program:


	make test


Run the testing program:


	./test
