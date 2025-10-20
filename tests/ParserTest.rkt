#lang racket

(require "../src/Parser.rkt" parser-tools/yacc)

(parse (open-input-string "hello
                           test
                           fuckyou
                           4+3   
                          "))
