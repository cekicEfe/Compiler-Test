#lang racket

(require "../src/Lexer.rkt" parser-tools/lex)
 
(define (lex-test ip)
  (port-count-lines! ip)
  (letrec ([one-line
            (lambda ()
              (let ([result (next-token ip)])
                (unless (equal?	(position-token-token result) 'EOF)
                  (printf "~a\n" result)
                  (one-line)
                  )))])
    (one-line)))
 
(define (my-lex-test str)
    (lex-test (open-input-string str)))

(my-lex-test "312 32 321.3213214 yellow boi123_")
    
(provide my-lex-test)
