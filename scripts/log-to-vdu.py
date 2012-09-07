#!/usr/bin/python

# -*- coding: UTF-8 -*-

"""
Script for generate virt-dashboard uso scenario
from the simunit bus log file
"""

import sys

USAGE = """
Usage: log-to-vdu.py <file>
"""

def PrintUsage():
    sys.stderr.write(USAGE)
    sys.exit(1)

def GetSendList(content):
    result = []
    for line in content:
        if line.find('send') != -1 :
            result.append(line)
    return result

def ParseBytes(line):
    start = line.rfind('[')
    end = line.rfind(']')
    return "[" + line[start+5:end+1]

def GetTime(line):
    start = line.find('.')
    end = line.find(']')

    return int(line[start+1:end])

def ParseDelay(line, next):
    return GetTime(next) - GetTime(line)

def ParseFile(filename):
    file = open(filename)
    content = file.readlines()

    send_list = GetSendList(content)

    rule = ""
    for index, line in enumerate(send_list):
        rule = ParseBytes(line) + " "

        if (index + 1) < len(send_list):
            rule += str(ParseDelay(line, send_list[index + 1]))
        else:
            rule += "0"

        print rule

    file.close()

def main():
    if len(sys.argv) < 1:
        PrintUsage()

    log_file = sys.argv[1]

    ParseFile(log_file)

if __name__ == '__main__':
    main()
