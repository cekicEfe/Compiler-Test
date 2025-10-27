#lang racket
 
(require parser-tools/lex
  (prefix-in : parser-tools/lex-sre))
 
(define-tokens value-tokens (NUMBER ID))
(define-empty-tokens op-tokens (EOF ADD SUBTRACT PRODUCT DIVISION POWER
                                LPARAM RPARAM IF THEN ELSE END_STATEMENT))
 
(define next-token
  (lexer-src-pos
    [(eof) (token-EOF)] ;; eof
    [(:+ whitespace) (return-without-pos (next-token input-port))] ;; (\sp|\tab)+
    ;;(:& (:~ #\newline) whitespace)
    [#\+ (token-ADD)]      ;; \+
    [#\- (token-SUBTRACT)] ;; \-
    [#\* (token-PRODUCT)]  ;; \*
    [#\/ (token-DIVISION)] ;; \/ 
    [#\^ (token-POWER)]    ;; \^
    [#\( (token-LPARAM)]   ;; \(
    [#\) (token-RPARAM)]   ;; \)
    ;;[#\newline (token-NEWLINE)]
    [#\; (token-END_STATEMENT)]

    ["if"   (token-IF)]
    ["then" (token-THEN)]
    ["else" (token-ELSE)]
    
    [(:seq (:+ numeric) (:* (:seq #\. (:+ numeric) )))
      (token-NUMBER (string->number lexeme))] ;;[0-9]\.[0-9]
    [(:seq (:* #\_) (:+ alphabetic) (:* (:or alphabetic numeric (:* #\_))))
      (token-ID (string->symbol lexeme))] ;;[a-zA-Z][a-zA-Z0-9]*\_
  )
)                        

(provide value-tokens op-tokens next-token)
