#!/usr/bin/python

# -*- coding: UTF-8 -*-

"""
Script for generate virt-dashboard controller scenario
from the simunit bus log file
"""

import sys

_USAGE = """
Usage: log-to-vdc.py <file>
"""

def PrintUsage():
    sys.stderr.write(_USAGE)
    sys.exit(1)

def ParseLine(line):
    line.find('send')

def ParseFile(filename):
    file = open(filename)
    content = file.readlines()
    for line in content:
        ParseLine(line)
    file.close()

def main():
    if len(sys.argv) < 1:
        PrintUsage()

    log_file = sys.argv[1]

    ParseFile(log_file)

if __name__ == '__main__':
    main()
