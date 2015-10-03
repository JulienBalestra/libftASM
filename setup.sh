#! /bin/bash

function go_to_dirname
{
    echo "Go to working directory..."
    cd $( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
    if [ $? -ne 0 ]
    then
        echo "go_to_dirname failed";
        exit 1
    fi
    echo "-> Current directory is" $(pwd)
}

function apt
{
    nasm -h > /dev/null
    if [ $? -ne 0 ]
    then
        apt-get update -qq
        apt-get install nasm -y
        if [ $? -ne 0 ]
        then
            echo "failed to install nasm"
            exit 2
        fi
    fi
}

function make_commands
{
	make
	make test
	./test
}

go_to_dirname
apt
make_commands
