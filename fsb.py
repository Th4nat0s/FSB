#!/usr/bin/python
# -*- coding: utf-8 -*-

# FSB : The Fast Searching Beak
# (c) Thanat0s 2013
#

import sys,re,subprocess,argparse,yaml

version = '0.0 Alpha'
verbose = False  
template_folder = './templates'
format_folder = './formats'

def func_seek(args):
  dbgprint ('Requested templates %s') % (args.template)


def func_print_template(args):
  print ('Requested templates %s') % (args.template)
  with open(template_folder + '/' + args.template + '.yaml', 'r') as f:
    doc = yaml.load(f)
  print doc  

if __name__ == '__main__':
  parser = argparse.ArgumentParser( description='FSB v'+version+' (c) Thanatos 2013', usage='Find something in somes logs')
  parser.add_argument('-v', '--verbose', action='store_true', help='verbose mode', dest='verbose')
  subparsers = parser.add_subparsers(help='sub-command help')
  
  parser_c = subparsers.add_parser('template', help='Print template info')
  parser_c.add_argument('-t','--template',required=True,  help='Search template')
  parser_c.set_defaults(func=func_print_template)

  parser_d = subparsers.add_parser('seek',help='Do a extract' )
  parser_d.set_defaults(func=func_seek)

  args = parser.parse_args()
  argsdict = vars(args)
  if argsdict['verbose']:   # Set the verbose flag
    verbose = True

  # Launche the right function
  args.func(args)

