#! /bin/bash
ps -e -o pid= | xargs -n 1 taskset -p 0xFFFFFFFF