#lang racket
 
(require parser-tools/lex
         (prefix-in : parser-tools/lex-sre))
 
(define-tokens value-tokens (NUMBER LEGAL))
(define-empty-tokens op-tokens (EOF ADD SUBTRACT PRODUCT DIVISION POWER))
 
(define next-token
  (lexer-src-pos
    [(eof) (token-EOF)]    ;; eof
    [(:+ (:& (:~ #\newline) whitespace)) (return-without-pos (next-token input-port))] ;; \sp
    [#\+ (token-ADD)]      ;; \+
    [#\- (token-SUBTRACT)] ;; \-
    [#\* (token-PRODUCT)]  ;; \*
    [#\/ (token-DIVISION)] ;; \/ 
    [#\^ (token-POWER)]    ;; \^
    [(:seq (:+ numeric) (:* (:seq #\. (:+ numeric) ))) (token-NUMBER (string->number lexeme))] ;; [0-9]\.[0-9]
    [(:seq (:+ alphabetic) (:* (:or alphabetic numeric)) #\_) (token-LEGAL (string lexeme))]))  ;; [a-zA-Z][a-zA-Z0-9]*\_

(provide value-tokens op-tokens next-token)
