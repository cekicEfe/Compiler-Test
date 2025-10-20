#lang racket

(require "../src/Parser.rkt" parser-tools/yacc)

(parse (open-input-string "4+3
                           (321 + 321 * 5)
                           (31 + 32 * 33 - 0.1)
                          "
  )
)
