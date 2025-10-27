#lang racket

(require "../src/Parser.rkt" parser-tools/yacc)

(parse (open-input-string ";4+3;"))
