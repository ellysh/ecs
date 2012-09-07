#!/usr/bin/python

# -*- coding: UTF-8 -*-

"""
Script for generate virt-dashboard controller scenario
from the simunit bus log file
"""

import sys

USAGE = """
Usage: log-to-vdc.py <file>
"""

def PrintUsage():
    sys.stderr.write(USAGE)
    sys.exit(1)

def ParseLine(line):
    start = line.rfind('[')
    end = line.rfind(']')
    return "[" + line[start+5:end+1]

def ParseFile(filename):
    file = open(filename)
    content = file.readlines()

    rule = ""
    counter = 0
    for line in content:
        if counter == 0:
            rule = ParseLine(line) + " "
            counter = 1
        elif counter == 1:
            rule += ParseLine(line)
            print rule
            counter = 0

    file.close()

def main():
    if len(sys.argv) < 1:
        PrintUsage()

    log_file = sys.argv[1]

    ParseFile(log_file)

if __name__ == '__main__':
    main()
